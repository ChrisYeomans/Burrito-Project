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
	double lat, lon;
	string time;
	vector<Order> order_vec;
	int j;
	
    for (int i=0;i<100;i++) {
    	cin >> lat >> lon >> time;
    	order_vec.push_back(Order(lat, lon, time, i));
    }
    cout << calc(order_vec) << endl;
    for (Order o : order_vec) {
        cout << o.index << " ";
    } cout << endl;
}
