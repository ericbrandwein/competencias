//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define elif else if
#define ll long long int
#define ld long double
#define vec vector
#define forn(a) for(ll a=0; a<n; a++)
#define fore(a, v, n) for(ll a=v; a<n; a++)
#define all(x) x.begin(), x.end()
#define presicion(x) cout<<fixed<<setprecision(x)
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define PI 3.14159265358979323
#define sen(ang) sin((ang)*PI/180)
//cout<<flush;

using namespace std;

struct Point {
	ll x, y, z;
	ll pos;

	bool operator<(const Point& other) const {
		return x < other.x || (x == other.x && y < other.y) ||
			(x == other.x && y == other.y && z < other.z);
	}
};

ll mas_cercano(ll ipunto, vector<Point>& points, vector<bool>& visitado) {
	Point& punto = points[ipunto];

	ll par = ipunto + 1;
	while (visitado[par]) par++;
	ll x = points[par].x;
	ll min_y = abs(points[par].y - punto.y);
	ll min_z = abs(points[par].z - punto.z);


	if (points[par].x != punto.x || points[par].y != punto.y) {
		for (ll i = par + 1; i < points.size() && points[i].x == x; i++) {
			if (points[par].x == punto.x && points[i].y > points[par].y) break;
			if (points[par].y == punto.y && points[i].y != punto.y) break;

			if (!visitado[i]) {
				ll dif_y = abs(points[i].y - punto.y);
				ll dif_z = abs(points[i].z - punto.z);

				if (dif_y < min_y) {
					min_y = dif_y;
					min_z = dif_z;
					par = i;
				} else if (dif_y == min_y && dif_z < min_z) {
					min_z = dif_z;
					par = i;
				}
			}
		}
	}

	return par;
}

int main() {
	IOS;

	ll n;
	cin >> n;
	vector<Point> points(n);
	forn (i) {
		cin >> points[i].x >> points[i].y >> points[i].z;
		points[i].pos = i + 1;
	}

	sort(all(points));

	vector<bool> visitado(n, false);
	for (ll i = 0;i < n -1; i++) {
		if (!visitado[i]) {
			ll par = mas_cercano(i, points, visitado);
			visitado[par] = true;
			cout << points[i].pos << " " << points[par].pos << endl;
		}
	}

	

	return 0;
}
