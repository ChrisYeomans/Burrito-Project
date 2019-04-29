#ifndef burrito_extras
#define burrito_extras

#define _USE_MATH_DEFINES
 
#include <math.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
const static double EarthRadiusKm = 6372.8;
 
inline double DegreeToRadian(double angle) {
	return M_PI * angle / 180.0;
}

class Coordinate {
public:
	double lat, lon;
	Coordinate(double latitude, double longitude){
		lat = latitude;
		lon = longitude;
	}
	Coordinate() {}
	double Latitude() const{return lat;}
	double Longitude() const {return lon;}
};
 
double HaversineDistance(const Coordinate& p1, const Coordinate& p2) {
	double latRad1 = DegreeToRadian(p1.Latitude());
	double latRad2 = DegreeToRadian(p2.Latitude());
	double lonRad1 = DegreeToRadian(p1.Longitude());
	double lonRad2 = DegreeToRadian(p2.Longitude());
 
	double diffLa = latRad2 - latRad1;
	double doffLo = lonRad2 - lonRad1;
 
	double computation = asin(sqrt(sin(diffLa / 2) * sin(diffLa / 2) + cos(latRad1) * cos(latRad2) * sin(doffLo / 2) * sin(doffLo / 2)));
	return 2 * EarthRadiusKm * computation;
}

class Order {
	public:
	Coordinate location;
	string time;
	int index;
	Order(double lat, double lon, string t, int i) {
		location = Coordinate(lat, lon);
		time = t;
		index = i;
	}
	Order() {}
	void print_vals() {
		cout << fixed;
		cout  << location.lat << " " << location.lon << " " << time << endl;
	}
	double dist(Order one, Order two) {
		return HaversineDistance(one.location, two.location);
	}
	bool achievable(double ct, Coordinate curr_loc) const {
		return (stoi(time.substr(2, 2)) + -30 >= ct - this->time_to_get(curr_loc));
	}
	double time_to_get(Coordinate curr) const {
    	return (HaversineDistance(curr, location)/80)*60;
	}
	friend bool operator <(const Order& a, const Order&b);
	friend bool operator >(const Order& a, const Order&b);
};

#endif