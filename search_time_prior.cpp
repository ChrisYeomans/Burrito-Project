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
	int tmp_index, curr;
	double lat, lon, dist_shop, dist, tmp_min;
	vector<Coordinate> pos_vec;
    vector<Order> out_vec;
	vector<Order> order_vec;
    vector<bool> used;
    used.reserve(100);
    vi final_index_vec;
    priority_queue<Order> time_q;
    vector<Order> passed_orders;
    float ct = 0, score = 0;
    Coordinate cl = Coordinate(53.38195, -6.59192);

    for (int i=0;i<100;i++) {
        cin >> lat >> lon >> time;
        pos_vec.push_back(Coordinate(lat, lon));
        order_vec.push_back(Order(lat, lon, time, i));
        time_q.push(Order(lat, lon, time, i));
    }

    while (!time_q.empty()) {
        if (time_q.top().achievable(ct, cl)) {
            out_vec.push_back(time_q.top());
            ct += time_q.top().time_to_get(cl);
            cl = time_q.top().location;

            cerr << time_q.top().index << endl;

            curr = time_q.top().index;
            used[time_q.top().index] = true;
            time_q.pop();
        } else {
            passed_orders.push_back(time_q.top());
            time_q.pop();
        }
    }
    cerr << "Switching" << endl;
    while(out_vec.size() < 100) {
        tmp_min = 99999.99;
        for (int j=0;j<passed_orders.size();j++) {
            if (j!=curr) {
                dist = HaversineDistance(passed_orders[curr].location, passed_orders[j].location); 
                if (!used[j] && dist < tmp_min) {
                    tmp_min = dist;
                    tmp_index = j;
                }
            }
        }
        used[tmp_index] = true;
        out_vec.push_back(order_vec[tmp_index]);
        curr = tmp_index;
        cerr << curr << endl;
    }
    cout << calc(out_vec) << endl;
    for(Order o : out_vec) cout << o.index << ",";cout << endl;
}