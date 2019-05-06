#include <bits/stdc++.h>
#include "burrito_extras.h"
#define INF 1000000000
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

double calc(vector<Order> order_vec) {
    double dist, curr_time = 60, score = 0, mins_after_7;
    Coordinate cur_loc = Coordinate(53.38195, -6.59192);

    for (int i=0;i<100;i++) {
    	dist = HaversineDistance(cur_loc, Coordinate(order_vec[i].location.lat, order_vec[i].location.lon));
        cur_loc = order_vec[i].location;
    	curr_time += (dist/80)*60;
        mins_after_7 = stoi(order_vec[i].time.substr(2, 2));

        if (curr_time - (mins_after_7 > 30)) 
            score += curr_time - mins_after_7 - 30;
    	
        cerr << "dist " << dist << " time due: " << order_vec[i].time <<  " curr time " << curr_time << " score change " << curr_time - mins_after_7 - 30 << endl; 
    }
    return score;
}
