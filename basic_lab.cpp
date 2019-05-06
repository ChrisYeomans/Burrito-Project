#include <bits/stdc++.h>
#include "burrito_extras.h"
#define INF 1000000000
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
	double lat1, lat2, lon1, lon2;
    cout << "Input the first set of coordinates seperated by space: ";
    cin >> lon1 >> lat1;
    cout << endl << "Input the second set of coordinates seperated by space:  ";
    cin >> lon2 >> lat2;
    cout << endl << HaversineDistance(Coordinate(lon1, lat1), Coordinate(lon2, lat2)) << endl;
}