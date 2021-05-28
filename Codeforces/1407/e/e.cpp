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

vec<ll> dijkstra(ll from, vec<vec<pair<ll,ll>>>& graph) {
	vec<ll> dists(graph.size(), LONG_LONG_MAX);
	priority_queue<pair<ll,ll>> next; // (node, dist)
	next.push({from, 0});
	while (!next.empty()) {
		pair<ll, ll> curr = next.top(); next.pop();
		ll node = curr.first;
		if (dists[node] == LONG_LONG_MAX) {
			dists[node] = curr.second;
			for (pair<ll,ll> child : graph[node]) {
				if (dists[child.first] == LONG_LONG_MAX) {
					next.push({child.first, dists[node] + child.second});
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

	vec<vec<ll>> blancas(n), blancas_rev(n);
	vec<vec<ll>> negras(n), negras_rev(n);
	fore (i, 0, m) {
		ll from, to, blanca;
		cin >> from >> to >> blanca;
		from--;
		to--;
		if (blanca) {
			blancas[from].push_back(to);
			blancas_rev[to].push_back(from);
		} else {
			negras[from].push_back(to);
			negras_rev[to].push_back(from);
		}
	}

	vec<bool> ciudades_blancas(n, false);
	vec<ll> dist(n, LONG_LONG_MAX);
	vec<ll> dist_blanca(n, LONG_LONG_MAX);
	vec<ll> dist_negra(n, LONG_LONG_MAX);
	dist[n-1] = 0;
	dist_blanca[n-1] = 0;
	dist_negra[n-1] = 0;
	queue<ll> next;
	next.push(n-1);
	while(!next.empty()) {
		ll curr = next.front();
		next.pop();
		for (ll child : negras_rev[curr]) {
			if (dist[child] == LONG_LONG_MAX) {
				dist_negra[child] = min(dist_negra[child], dist[curr] + 1);
				ciudades_blancas[child] = true;
				if (dist_blanca[child] != LONG_LONG_MAX) {
					dist[child] = max(dist_blanca[child], dist_negra[child]);
					ciudades_blancas[child] = dist_blanca[child] > dist_negra[child];
					next.push(child);
				}
			}
		}
		for (ll child : blancas_rev[curr]) {
			if (dist[child] == LONG_LONG_MAX) {
				dist_blanca[child] = min(dist_blanca[child], dist[curr] + 1);
				ciudades_blancas[child] = false;
				if (dist_negra[child] != LONG_LONG_MAX) {
					dist[child] = max(dist_blanca[child], dist_negra[child]);
					ciudades_blancas[child] = dist_blanca[child] > dist_negra[child];
					next.push(child);
				}
			}
		}
	}

	vec<vec<pair<ll,ll>>> graph(n);
	forn (i) {
		if (ciudades_blancas[i]) {
			for (ll child : blancas[i]) {
				graph[i].push_back({child, 1});
			}
		} else {
			for (ll child : negras[i]) {
				graph[i].push_back({child, 1});
			}
		}
	}

	vec<ll> dists = dijkstra(0, graph);

	if (dist[0] == LONG_LONG_MAX) {
		cout << -1 << endl;
	} else {
		cout << dist[0] << endl;
		// assert(dists[n-1] == dist[0]);
	}

	forn (i) {
		cout << (int) ciudades_blancas[i];
	}
	cout << endl;



	return 0;
}
