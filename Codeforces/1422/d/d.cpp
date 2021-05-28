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

struct Location {
	pair<ll,ll> pos;
	ll index;

	const bool operator<(const Location& other) const {
		return pos.first < other.pos.first;
	}
};


bool order_by_y(const Location& first, const Location& second) {
	return first.pos.second < second.pos.second;
}

/**
 * Devuelve la distancia del camino más chico desde from
 * a todos los otros nodos. Solo funciona para distancias
 * positivas entre nodos.
 *
 * graph tiene que ser una lista de adyacencias donde cada arista
 * es un pair (destino, distancia).
 *
 * Complejidad: O(m*log(m)), con m la cantidad de aristas.
 */
vec<ll> dijkstra2(ll from, vec<vec<pair<ll,ll>>>& graph) {
  vec<ll> dists(graph.size(), LONG_LONG_MAX);
  set<pair<ll,ll>> next; // (dist, node)
  next.insert({0, from});
  while (!next.empty()) {
    pair<ll, ll> curr = *next.begin();
    next.erase(next.begin());
    ll node = curr.second;
    if (dists[node] == LONG_LONG_MAX) {
      dists[node] = curr.first;
      for (pair<ll,ll> child : graph[node]) {
        if (dists[child.first] == LONG_LONG_MAX) {
          next.insert({dists[node] + child.second, child.first});
        }
      }
    }
  }
  return dists;
}


int main() {
	IOS;

	ll n;
	cin >> n;
	ll m;
	cin >> m;
	pair<ll,ll> orig, dest;
	cin >> orig.first >> orig.second;
	cin >> dest.first >> dest.second;

	vec<Location> locations(m);
	fore (i,0 ,m) {
		cin >> locations[i].pos.first >> locations[i].pos.second;
		locations[i].index = i;
	}

	// locations.push_back({orig, locations.size()});
	vec<vec<pair<ll,ll>>> graph(m+2); // (nodo, dist)
	sort(all(locations));
	for (ll i = 0; i < (ll)locations.size()-1; i++) {
		Location& curr = locations[i];
		Location& next = locations[i+1];
		ll dist_x = abs(curr.pos.first - next.pos.first);
		graph[curr.index].push_back({next.index, dist_x});
		graph[next.index].push_back({curr.index, dist_x});
	}

	sort(locations.begin(), locations.end(), order_by_y);
	for (ll i = 0; i < (ll)locations.size()-1; i++) {
		Location& curr = locations[i];
		Location& next = locations[i+1];
		ll dist_y = abs(curr.pos.second - next.pos.second);
		graph[curr.index].push_back({next.index, dist_y});
		graph[next.index].push_back({curr.index, dist_y});
	}

	for (Location& location : locations) {
		graph[m].push_back({
			location.index,
			min(
				abs(location.pos.first - orig.first),
				abs(location.pos.second - orig.second)
			)
		});

		graph[location.index].push_back({
			m+1,
			abs(location.pos.first - dest.first) + abs(location.pos.second - dest.second)
		});
	}

	graph[m].push_back({
		m+1, abs(orig.first - dest.first) + abs(orig.second - dest.second)
	});

	cout << dijkstra2(m, graph)[m+1] << endl;
	return 0;
}
