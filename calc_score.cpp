#include <bits/stdc++.h>
#include "burrito_extras.h"
#define INF 1000000000
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
    float lat, lon, dist, curr_time = 0, score = 0;
    pair<float, float> cur_loc = make_pair(53.38195, -6.59192);
    string time;
    int index;
    for (int i=0;i<100;i++) {
    	cin >> index >> lat >> lon >> time;
    	dist = HaversineDistance(Coordinate(cur_loc.first, cur_loc.second), Coordinate(lat, lon));
    	curr_time += (dist/80)*60;
    	score += curr_time + (60 - stoi(time.substr(2, 2)));
    }
    cout << score << endl;
}
