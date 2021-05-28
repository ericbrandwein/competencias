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

ll g;

ll to_node(ll pos, ll time) {
	return pos * (g + 1) + time;
}

vec<int> BFS_01(ll from, vec<vec<pair<int,bool>>>& graph) {
	vec<int> dists(graph.size(), INT_MAX);
	dists[from] = 0;
	deque<int> next;
	next.push_back(from);
	while (!next.empty()) {
		int curr = next.front();
		next.pop_front();
		for (pair<int,int> child : graph[curr]) {
			int node = child.first;
			ll dist = child.second;
			ll new_dist = dists[curr] + dist;
			if (dists[node] > new_dist) {
				dists[node] = new_dist;
				if (dist == 0) {
					next.push_front(node);
				} else {
					next.push_back(node);
				}
			}
		}
	}
	return dists;
}

int main() {
	IOS;

	ll n, m;
	cin >> n >> m;

	vec<ll> islas(m);
	fore (i, 0, m) {
		cin >> islas[i];
	}

	sort(all(islas));
	ll r;
	cin >> g >> r;

	ll nodes = m * (g+1);
	vec<vec<pair<int, bool>>> graph(nodes);
	for (ll i = 0; i < m; i++) {
		ll from = to_node(i, 0);
		ll to = to_node(i, g);
		graph[from].push_back({to, 1});

		if (i > 0) {
			ll dist_left = islas[i] - islas[i-1];
			for (ll tiempo = dist_left; tiempo <= g ; tiempo++) {
				from = to_node(i, tiempo);
				to = to_node(i - 1, tiempo - dist_left);
				graph[from].push_back({to, 0});
			}
		}
		if (i < m-1) {
			ll dist_right = islas[i + 1] - islas[i];
			for (ll tiempo = dist_right; tiempo <= g ; tiempo++) {
				from = to_node(i, tiempo);
				to = to_node(i + 1, tiempo - dist_right);
				graph[from].push_back({to, 0});
			}
		}
	}

	vec<int> dists = BFS_01(to_node(0, g), graph);


	ll min_dist = INT_MAX;
	for (ll i = 0; i < m; i++) {
		if (n - islas[i] <= g) {
			ll node = to_node(i, g);
			if (dists[node] != INT_MAX) {
				min_dist = min(
					min_dist,
					dists[node] * r + dists[node] * g + n - islas[i]
				);
			}
		}
	}

	if (min_dist == INT_MAX) {
		cout << -1 << endl;
	} else {
		cout << min_dist << endl;
	}

	return 0;
}
