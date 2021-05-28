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

bool any_cycle(vec<vec<ll>>& aristas, ll node, ll parent, vec<bool>& visited) {
	visited[node] = true;
	bool cycle = false;
	for (ll child : aristas[node]) {
		if (child != parent) {
			if (visited[child]) {
				return true;
			}
			cycle = cycle || any_cycle(aristas, child, node, visited);
		}
	}
	return cycle;
}


int main() {
	IOS;


	ll m;
	cin >> m;
	map<vec<ll>, ll> pos;
	vec<vec<ll>> nodos;
	vec<vec<ll>> aristas;
	fore (i, 0, m) {
		vec<ll> from(3), to(3);
		fore (j, 0, 3) cin >> from[j];
		fore (j, 0, 3) cin >> to[j];
		if (pos.count(from) == 0) {
			pos[from] = aristas.size();
			aristas.emplace_back();
			nodos.push_back(from);
		}
		if (pos.count(to) == 0) {
			pos[to] = aristas.size();
			aristas.emplace_back();
			nodos.push_back(to);
		}
		aristas[pos[from]].push_back(pos[to]);
		aristas[pos[to]].push_back(pos[from]);
	}

	vec<bool> visited(aristas.size(), false);
	if (any_cycle(aristas, 0, -1, visited)) {
		cout << "True closed chains" << endl;
	} else {
		cout << "No true closed chains" << endl;
	}

	map<vec<ll>, set<vec<ll>>> aristas_piso;
	for (ll i = 0; i < aristas.size(); i++) {
		vec<ll> nodo = nodos[i];
		nodo.pop_back();
		for (ll pos : aristas[i]) {
			vec<ll> destino = nodos[pos];
			destino.pop_back();
			aristas_piso[nodo].insert(destino);
		}
	}

	map<vec<ll>, ll> pos_piso;
	vec<vec<ll>> graph_piso;
	for (const auto& entry : aristas_piso) {
		vec<ll> nodo = entry.first;
		if (pos_piso.count(nodo) == 0) {
			pos_piso[nodo] = graph_piso.size();
			graph_piso.emplace_back();
		}
		for (const vec<ll>& destino: entry.second) {
			if (pos_piso.count(destino) == 0) {
				pos_piso[destino] = graph_piso.size();
				graph_piso.emplace_back();
			}
			if (nodo != destino) {
				graph_piso[pos_piso[nodo]].push_back(pos_piso[destino]);
			}
		}
	}

	visited = vec<bool>(graph_piso.size(), false);
	if (any_cycle(graph_piso, 0, -1, visited)) {
		cout << "Floor closed chains" << endl;
	} else {
		cout << "No floor closed chains" << endl;
	}

}
