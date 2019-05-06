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
	int tmp_index, curr = 0;
	double lat, lon, dist, tmp_min, min_start = 9999.99;
	vector<Order> order_vec, out_vec;
    vector<bool> used;
    used.reserve(100);

    for (int i=0;i<100;i++) {
    	cin >> lat >> lon >> time;
    	order_vec.push_back(Order(lat, lon, time, i));
        if (HaversineDistance(order_vec[i].location, Coordinate(53.38195, -6.59192)) < min_start) {
            min_start = HaversineDistance(order_vec[i].location, Coordinate(53.38195, -6.59192));
            curr = i;
        }
    }
    while(out_vec.size() < 100) {
    	tmp_min = 9999.99;
    	for (int j=0;j<100;j++) {
    		if (j!=curr) {
                dist = HaversineDistance(order_vec[curr].location, order_vec[j].location); 
                if (!used[j] && dist < tmp_min) {
                    tmp_min = dist;
                    tmp_index = j;
                }
    		}
    	}
        used[tmp_index] = true;
        out_vec.push_back(order_vec[tmp_index]);
        curr = tmp_index;
    }
    cout << calc(out_vec) << endl;
    for (Order o : out_vec) cout << o.index << ",";cout << endl;
}