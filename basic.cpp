#include <bits/stdc++.h>
#include "burrito_extras.h"
#define INF 1000000000
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
	double lat, lon, dist;
	string time;
	vector<Order> order_vec;
	int j, v;
	cin >> v;
	
    for (int i=0;i<100;i++) {
    	cin >> time >> lat >> lon >> dist;
    	order_vec.push_back(Order(lat, lon, time, 1));
    }
    for (int i=0;i<100;i++) {
    	j = (i+v) % 100;
    	order_vec[j].print_vals();
    }
}
