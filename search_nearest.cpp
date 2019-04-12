#include <bits/stdc++.h>
#include "burrito_extras.h"
#define INF 1000000000
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
	string time;
	int tmp_index;
	float lat, lon, dist_shop, dist, tmp_min;
	vector<pair<float, float>> pos_vec;
	vector<vector<float>> dist_vec_vec;
	dist_vec_vec.reserve(100);
	vi min_dist_vec;
	vector<Order> order_vec;

    for (int i=0;i<100;i++) {
    	cin >> time >> lat >> lon >> dist_shop;
    	pos_vec.push_back(make_pair(lat, lon));
    	cerr << lat << " " << lon << endl;
    	order_vec.push_back(Order(make_pair(lat, lon), time));
    }

    for (int i=0;i<100;i++) {
    	tmp_min = 500.0;
    	for (int j=0;j<100;j++) {
    		if (j!=i) {
    			dist = HaversineDistance(
    				Coordinate(pos_vec[i].first, pos_vec[i].second),
    				Coordinate(pos_vec[j].first, pos_vec[j].second)
    			);
    			cerr << dist << endl;
    			cerr << "                 " << (tmp_min > dist)<< "           " << (count(min_dist_vec.begin(), min_dist_vec.end(), j) < 1) << endl;
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
    for (int e : min_dist_vec) {cout << e << " "; order_vec[e].print_vals();}
    cout << endl;
}
