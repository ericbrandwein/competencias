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
	ll x, y;

	Point operator-(const Point& other) const {
		return Point{this->x - other.x, this->y - other.y};
	}
};

struct Circle {
	Point center;
	ll radius;

	bool contains(Point& point) {
		Point diff = this->center - point;
		return diff.x * diff.x + diff.y * diff.y < radius * radius;
	}

	bool contains(Circle& other) {
		return contains(other.center);
	}

	bool operator<(const Circle& other) const {
		return radius < other.radius;
	}
};

// struct Tree {
// 	vector<Circle>& circles;
// 	vector<ll> graph;

// 	ll outside(ll index) {
// 		return index * 2 + 1;
// 	}

// 	ll inside(ll index) {
// 		return index * 2 + 2;
// 	}

// 	Tree(vector<Circle>& circles): circles(circles) {
// 		ll n = circles.size();
// 		graph.resize(2*n + 1, -1);
// 	}
// };


int main() {
	IOS;

	// std::clock_t start;
    // double duration;

    // start = std::clock();


	ll n, m, k;
	cin >> n >> m >> k;
	vector<Point> points(n);
	fore (i, 0, n) {
		cin >> points[i].x >> points[i].y;
	}

	vector<Circle> circles(m);
	fore (i, 0, m) {
		cin >> circles[i].radius;
		Point center;
		cin >> center.x >> center.y;
		circles[i].center = center;
	}

	fore (i, 0, k) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		Point pointa = points[a];
		Point pointb = points[b];
		ll not_shared = 0;
		for (ll j = 0; j < circles.size(); j++) {
			if (
				(circles[j].contains(pointa) && !circles[j].contains(pointb)) ||
				(!circles[j].contains(pointa) && circles[j].contains(pointb))
			) {
				not_shared++;
			}
		}

		cout << not_shared << endl;
	}

	// k = 100000;
	// fore (i, 0, k) {
	// 	// ll a, b;
	// 	// cin >> a >> b;
	// 	ll a = 0;
	// 	ll b = 0;
	// 	Point pointa = points[a];
	// 	Point pointb = points[b];
	// 	ll not_shared = 0;
	// 	for (ll j = 0; j < 1000; j++) {
	// 		if (
	// 			(circles[0].contains(pointa) && !circles[0].contains(pointb)) ||
	// 			(!circles[0].contains(pointa) && circles[0].contains(pointb))
	// 		) {
	// 			not_shared++;
	// 		}
	// 	}

	// 	cout << not_shared << endl;
	// }



    // duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    // std::cout<<"duration: "<< duration <<'\n';
	// // ordenados del mayor radio
	// sort(circles.rbegin(), circles.rend());







	return 0;
}
