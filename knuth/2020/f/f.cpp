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

struct Circle {
	ll x,y;


	bool operator<(const Circle& other) const {
		return y < other.y;
	}

	bool intersects(Circle& other) {
		ll diff_x = x - other.x;
		ll diff_y = y - other.y;
		return diff_x * diff_x + diff_y * diff_y <= 300*300;
	}
};


ll path_len(vector<vector<ll>>& graph, vector<bool>& visited, ll pos) {
	ll len_tomado = 0;
	ll len_no = 1;
	visited[pos] = true;
	for (ll child: graph[pos]) {
		if (!visited[child]) {
			cost_tomado += path_len(graph, visited, pos) - 1;
			cost_no += path_len(graph, visited, pos);
		}
	}

	return min(cost_tomado, cost_no);

}

int main() {
	IOS;


	ll n, m;
	cin >> n >> m;
	ll t;
	cin >> t;

	vector<Circle> circles(t);
	fore (i, 0, t) {
		cin >> circles[i].x >> circles[i].y;
	}
	if (n == 1) {
		sort(all(circles));

		ll total = 1;
		Circle curr = circles[0];
		for (ll i = 1; i < circles.size(); i++) {
			if (!circles[i].intersects(curr)) {
				curr = circles[i];
				total++;
			}
		}

		cout << total << endl;
	} else {
		vector<vector<ll>> graph(t);
		for (ll i = 0; i < t; i++) {
			for (ll j = 0; j < t; j++) {
				if (circles[i].intersects(circles[j])) {
					graph[i].push_back(j);
				}
			}
		}

		ll total = 0;
		vector<bool> visited(t, false);
		for (ll i = 0; i < t; i++) {
			if (!visited[i]) {
				total += path_cost(graph, visited, i);
			}
		}



		ll intersections = 0;
		vector<bool> counted_intersection(t, false);

		for (ll i = 0; i < t; i++) {
			if (!counted_intersection[i]) {
				for (ll j = i + 1; j < t; j++) {
					if (circles[i].intersects(circles[j]) && !counted_intersection[j]) {
						intersections++;
						counted_intersection[j] = true;
					}
				}
			}
		}

		cout << t - intersections << endl;
	}


	return 0;
}
