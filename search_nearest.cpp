#include <bits/stdc++.h>
#include "burrito_extras.h"
#include "calc_score.h"
#define INF 1000000000
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
	string time;
	int tmp_index;
	double lat, lon, dist_shop, dist, tmp_min;
	vector<Coordinate> pos_vec;
	vector<vector<double>> dist_vec_vec;
	dist_vec_vec.reserve(100);
	vi min_dist_vec;
	vector<Order> order_vec;

    for (int i=0;i<100;i++) {
    	cin >> time >> lat >> lon >> dist_shop;
    	pos_vec.push_back(Coordinate(lat, lon));
    	cerr  << lat << " " << lon << endl;
    	order_vec.push_back(Order(lat, lon, time, i));
    }
    for (int i=0;i<100;i++) {
    	tmp_min = 500.0;
    	for (int j=0;j<100;j++) {
    		if ( j!=i ) {
    			dist = HaversineDistance(pos_vec[i], pos_vec[j]);
    			cerr << dist << endl;
    			cerr << "                 " << (tmp_min > dist) << "           " << (count(min_dist_vec.begin(), min_dist_vec.end(), j) < 1) << endl;
    			if ((tmp_min > dist) && (count(min_dist_vec.begin(), min_dist_vec.end(), j) < 1)) {
    				tmp_min = dist;
    				tmp_index = j;
    				cerr << "inserting " << j << endl;
    			}
    			dist_vec_vec[i].push_back(dist);
    		}
    	}
    	min_dist_vec.push_back(tmp_index);
    }
    cout << calc(order_vec) << " " << endl;
}
