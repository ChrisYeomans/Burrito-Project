#define _USE_MATH_DEFINES
 
#include <math.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
const static double EarthRadiusKm = 6372.8;
 
inline double DegreeToRadian(double angle)
{
	return M_PI * angle / 180.0;
}
 
class Coordinate
{
public:
	Coordinate(double latitude ,double longitude):myLatitude(latitude), myLongitude(longitude)
	{}
 
	double Latitude() const
	{
		return myLatitude;
	}
 
	double Longitude() const
	{
		return myLongitude;
	}
 
private:
 
	double myLatitude;
	double myLongitude;
};
 
double HaversineDistance(const Coordinate& p1, const Coordinate& p2)
{
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
	pair<float, float> location;
	string time;
	Order(pair<float, float> l, string t) {
		location = l;
		time = t;
	}
	Order() {}
	void print_vals() {
		cout << location.first << " " << location.second << " " << time << endl;
	}
	float dist(Order one, Order two) {
		return HaversineDistance((one.location.first, one.location.seond), (two.location.first, two.location.second));
	}

};