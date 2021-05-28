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

struct Edge {
	ll node, max_load, cost;
};

void fill_children(vec<vec<Edge>>& graph, vec<ll>& subtree_size, vec<bool>& heavy, vec<ll>& parent, vec<ll>& max_load, vec<ll>& cost, ll node) {
	for (Edge edge : graph[node]) {
		ll child = edge.node;
		if (parent[child] == -1) {
			parent[child] = node;
			max_load[child] = edge.max_load;
			cost[child] = edge.cost;
			fill_children(graph, subtree_size, heavy, parent, max_load, cost, child);
			subtree_size[node] += subtree_size[child];
		}
	}
	for (Edge edge : graph[node]) {
		ll child = edge.node;
		if (parent[child] == node && subtree_size[child] >= subtree_size[node] / 2) {
			heavy[child] = true;
		}
	}
}





void solve() {
	ll n, days;
	cin >> n >> days;
	vec<vec<Edge>> graph(n);
	fore (i, 0, n-1) {
		ll from, to, load, cost;
		cin >> from >> to >> load >> cost;
		from--;
		to--;
		graph[from].push_back({to, load, cost});
		graph[to].push_back({from, load, cost});
	}

	vec<ll> parent(n, -1);
	vec<ll> max_load(n, -1);
	vec<ll> cost(n, -1);
	parent[0] = -2;
	vec<ll> subtree_size(n,1);
	vec<bool> heavy(n, false);
	fill_children(graph, subtree_size, heavy, parent, max_load, cost, 0);

	// heavy-light
	vec<ll> decomposition_parent(n, -1);
	// weight, gcd
	vec<map<ll,ll>> decomp_map(n);
	decomposition_parent[0] = -2;
	for (ll i = 0; i < n; i++) {
		bool all_light = true;
		for (Edge edge : graph[i]) {
			if (parent[edge.node] == i && heavy[edge.node]) {
				all_light = false;
			}
		}
		if (all_light) {
			ll node = i;
			while (heavy[node]) {
				node = parent[node];
			}
			if (node != 0) node = parent[node];
			ll top = node;
			node = i;
			while (heavy[node]) {
				decomposition_parent[node] = top;
				auto it = decomp_map[top].upper_bound(max_load[node]);
				if (it != decomp_map[top].begin()) {
					it--;
					decomp_map[top][max_load[node]] = __gcd(it->second, cost[node]);
				} else {
					decomp_map[top][max_load[node]] = cost[node];
				}
				it = decomp_map[top].find(max_load[node]);
				it++;
				while (it != decomp_map[top].end()) {
					it->second = __gcd(it->second, cost[node]);
					it++;
				}
				node = parent[node];

			}
			if (node != 0) {
				decomposition_parent[node] = top;
				auto it = decomp_map[top].upper_bound(max_load[node]);
				if (it != decomp_map[top].begin()) {
					it--;
					decomp_map[top][max_load[node]] = __gcd(it->second, cost[node]);
				} else {
					decomp_map[top][max_load[node]] = cost[node];
				}
				it = decomp_map[top].find(max_load[node]);
				it++;
				while (it != decomp_map[top].end()) {
					it->second = __gcd(it->second, cost[node]);
					it++;
				}
			}
		}
	}




	while (days--) {
		ll node, weight;
		cin >> node >> weight;
		node--;
		ll res = 0;
		ll parent_decomp = decomposition_parent[node];
		while (node != parent_decomp) {
			if (max_load[node] <= weight) {
				res = __gcd(res, cost[node]);
				if (res == 1) break;
			}
			node = parent[node];
		}
		while (res != 1 && node != 0) {
			node = decomposition_parent[node];
			auto it = decomp_map[node].upper_bound(weight);
			if (it != decomp_map[node].begin()) {
				it--;
				res = __gcd(res, it->second);
			}
		}
		cout << res << " ";
	}

}


int main() {
	IOS;

	ll t;
	cin >> t;
	fore (i, 0, t) {
		cout << "Case #" << i + 1 << ": ";
		solve();
		cout << endl;
	}


}
