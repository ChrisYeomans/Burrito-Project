#include <bits/stdc++.h>
#include "burrito_extras.h"
#include "calc_score.h"
#define INF 1000000000
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

bool operator <(const Order& a, const Order& b) {
    return stoi(a.time.substr(2, 2)) > stoi(b.time.substr(2, 2));
}

bool operator >(const Order& a, const Order& b) {
    return stoi(a.time.substr(2, 2)) < stoi(b.time.substr(2, 2));
}

int main() {
	string time;
	int tmp_index;
	double lat, lon, dist_shop, dist, tmp_min;
	vector<Coordinate> pos_vec;
    vector<Order> out_vec;
	vector<Order> order_vec;
    vi final_index_vec;
    priority_queue<Order> time_q;
    vector<Order> passed_orders;
    float ct = 0, score = 0;
    Coordinate cl = Coordinate(53.38195, -6.59192);

    for (int i=0;i<100;i++) {
        cin >> lat >> lon >> time;
        pos_vec.push_back(Coordinate(lat, lon));
        cerr  << lat << " " << lon << endl;
        order_vec.push_back(Order(lat, lon, time, i));
        time_q.push(Order(lat, lon, time, i));
    }

    while (!time_q.empty()) {
        if (time_q.top().achievable(ct, cl)) {
            final_index_vec.push_back(time_q.top().index);
            ct += time_q.top().time_to_get(cl);
            cl = time_q.top().location;
            time_q.pop();
        } else {
            passed_orders.push_back(time_q.top());
            time_q.pop();
        }
    }
    for (int i=0;i<passed_orders.size();i++) { // greedy distance based algorithm to finish off
        tmp_min = 500.0;
        for (int j=0;j<passed_orders.size();j++) {
            if (j != i) {
                dist = HaversineDistance(passed_orders[i].location, passed_orders[j].location);
                if ((tmp_min > dist) && (count(final_index_vec.begin(), final_index_vec.end(), j) < 1)) {
                    tmp_min = dist;
                    tmp_index = passed_orders[j].index;
                    cerr << "inserting " << passed_orders[j].index << endl;
                }
            }
        }
        final_index_vec.push_back(tmp_index);
    }
    for (int i=0;i<100;i++) out_vec.push_back(order_vec[final_index_vec[i]]);
    cout << calc(out_vec) << endl;
    for(Order o : out_vec) cout << o.index << " ";
    cout << endl;
}
