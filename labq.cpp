#include <bits/stdc++.h>
#include "burrito_extras.h"
#include "calc_score.h"
#include <cstdlib>
#include <ctime>
#define INF 1000000000
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
	srand(time(0));
	double lat, lon, dist, best_score = 15053, tmp_score;
	string time;
	Order temp;
	int r_num1, r_num2, r_num3;
	vi curr_best;
	vector<Order> order_vec, tmp;
	tmp.reserve(100);

	for(int i=0;i<100;i++) {
	    cin >> time >> lat >> lon >> dist;
	    order_vec.push_back(Order(lat, lon, time, i));
	}

	while (true) {
		tmp.clear();
		for(int e=0;e<100;e++) {
			tmp.push_back(order_vec[e]);
		}

		for(int i=0;i<1000;i++) {
			r_num1 = rand()%100;
			r_num2 = rand()%100;
			r_num3 = rand()%100;
			temp = tmp[r_num1];
			tmp[r_num1] = tmp[r_num2];
			tmp[r_num2] = tmp[r_num3];
			tmp[r_num3] = temp;
		}
		//for(Order q : tmp) cerr << q.index << " ";
		//cerr << endl;

		tmp_score = calc(tmp);
		//cerr << "tmp_score " << tmp_score << endl;
		if (tmp_score < best_score) {
			best_score = tmp_score;
			cout << best_score << endl;
			curr_best.clear();
			for(Order o : tmp) {
				curr_best.push_back(o.index);
				cout << o.index << " ";
			}
			cout << endl;
		}
	}
}
