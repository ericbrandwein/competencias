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

struct DisjointSet {
	ll n;
	vector<ll> sets;
	vector<ll> sizes;

	DisjointSet(ll n): n(n), sets(n), sizes(n) {
		for (ll i = 0; i < n; i++) {
			// Cada uno es su propio padre.
			sets[i] = i;
			sizes[i] = 1;
		}
	}

	// Versión iterativa.
	ll find(ll node) {
		vector<ll> actualizar;
		while (sets[node] != node) {
			actualizar.push_back(node);
			node = sets[node];
		}

		for (ll hijo : actualizar) {
			sets[hijo] = node;
		}
		return node;
	}

	// Versión recursiva.
	ll findr(ll node) {
		if (sets[node] != node) {
			sets[node] = findr(sets[node]);
		}
		return sets[node];
	}

	/** Devuelve true si estaban en distintas componentes, y false sino. */
	bool join(ll first, ll second) {
		ll pfirst = find(first);
		ll psecond = find(second);

		// Si tienen el mismo padre no los unimos.
		if (pfirst == psecond) return false;

		if (sizes[pfirst] < sizes[psecond])
			swap(pfirst, psecond);

		// Ponemos al más chico como hijo del más grande.
		sets[psecond] = sets[pfirst];
		sizes[pfirst] += sizes[psecond];
		return true;
	}
};

struct City {
	ll x, y;
	ll cost;
	ll k;
	map<ll, ll> connections;
	ll index;

	bool operator< (const City& other) const {
		return cost<other.cost;
	}
};

struct Arista {
	ll from, to, costo;

	bool operator<(const Arista& other) const {
		return costo < other.costo;
	}
};

ll distancia(City& a, City& b) {
	return (abs(a.x - b.x) + abs(a.y - b.y)) * (a.k + b.k);
}

int main() {
	IOS;

	ll n;
	cin >> n;

	vector<City> cities(n + 1);
	fore (i, 1, n + 1) {
		cities[i].index = i;
		cin >> cities[i].x >> cities[i].y;
	}

	fore (i, 1, n + 1) {
		cin >> cities[i].cost;
	}
	fore (i, 1, n + 1) cin >> cities[i].k;

	vector<Arista> aristas;

	fore (i, 1, n + 1) {
		aristas.push_back({0, i, cities[i].cost});
		fore (j, i + 1, n + 1) {
			aristas.push_back({i, j, distancia(cities[i], cities[j])});
		}
	}

	sort(all(aristas));

	DisjointSet kruskal(n + 1);
	vector<ll> stations;
	vector<Arista> connections;
	ll total = 0;
	fore (i, 0, aristas.size()) {
		ll from = aristas[i].from;
		ll to = aristas[i].to;
		bool unidos = kruskal.join(from, to);
		if (unidos) {
			if (from == 0) {
				stations.push_back(to);
			} else {
				connections.push_back(aristas[i]);
			}
			total += aristas[i].costo;
		}
	}

	cout << total << endl;
	cout << stations.size() << endl;
	for (auto station : stations)
		cout << station << " ";
	cout << endl;
	cout << connections.size() << endl;
	for (Arista& connection : connections)
		cout << connection.from << " " << connection.to << endl;

	return 0;
}
