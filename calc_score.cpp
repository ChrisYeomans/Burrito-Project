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
    Coordinate cur_loc = Coordinate(53.38195, -6.59192);
    string time;

    for (int i=0;i<100;i++) {
    	cin  >> lat >> lon >> time;
    	dist = HaversineDistance(cur_loc, Coordinate(lat, lon));
        cur_loc = Coordinate(lat, lon);
    	curr_time += (dist/80)*60;
    	score += curr_time + (60 - stoi(time.substr(2, 2)));
        cerr << "dist " << dist << " time due: " << time <<  " curr time " << curr_time << " score change " << curr_time + (60 - stoi(time.substr(2, 2))) << endl; 
    }
    cout << score << endl;
}
