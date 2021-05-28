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

/**
 * Permite mantener conjuntos de cosas, pudiendo preguntar
 * el conjunto de una cosa y unir dos conjuntos con complejidad
 * amortizada O(a(n)), donde a es la inversa de la función de Ackermann.
 * Es, para todos los fines prácticos, constante.
 *
 * Uso:
 * 	DisjointSet ds(cant_elementos);
 * 	bool juntados = ds.join(i, j); // junta los conjuntos a los que pertenecen i y j.
 * 	ll conjunto = ds.find(i); // determina el conjunto al que pertenece i.
 *
 * Para lograr esto, elige un elemento como la raíz de cada conjunto.
 * Si un elemento tiene como padre a sí mismo, es la raíz de su conjunto,
 * sino, debe ir a buscar el ancestro más lejano para ver cuál es la raíz.
 * Cada vez que se va a buscar la raíz de un elemento, se actualiza su padre
 * para que apunte a la raíz, acortando el camino a ella.
 *
 * Es importante guardar también los tamaños de los conjuntos.
 * Cuando dos conjuntos son unidos, se pone la raíz del conjunto
 * más grande como el padre de la raíz del conjunto más chico.
 * Así, la raíz del nuevo conjunto es la raíz del conjunto anterior
 * más grande.
 */
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

struct Edge {
    ll from, to, cost;
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

/**
 * Devuelve las aristas de un árbol generador mínimo.
 *
 * Complejidad: O(n + m * log(m)), donde m es edges.size().
 * Si las aristas ya están ordenadas, se reduce a
 * O(n + m * a(m)), donde a es la inversa de la función de
 * Ackermann, que es prácticamente constante.
 */
vector<Edge> kruskal(ll n, vector<Edge>& edges) {
    vector<Edge> agm;
    sort(all(edges));
    DisjointSet ds(n);
    for (Edge& e : edges) {
        bool joined = ds.join(e.from, e.to);
        if (joined) {
            agm.push_back(e);
        }
    }
    return agm;
}


int main() {
	IOS;

	ll n, m;
	cin >> n>>m;

	vector<set<ll>> ones(n);

	for (ll i = 0; i < m; i++) {
		ll from, to;
		cin >> from >> to;
		from--;
		to--;
		ones[from].insert(to);
		ones[to].insert(from);
	}

	vector<bool> visitados(n);

	return 0;
}
