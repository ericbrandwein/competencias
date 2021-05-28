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

#define MOD 1000000007

/**
 * Devuelve el ciclo al que corresponde este nodo,
 * actualizado recursivamente según sus padres.
 */
ll updated_ciclo(ll nodo, vector<ll>& ciclos) {
	stack<ll> padres;
	while (ciclos[nodo] != nodo) {
		padres.push(nodo);
		nodo = ciclos[nodo];
	}
	while (!padres.empty()) {
		ciclos[padres.top()] = nodo;
		padres.pop();
	}
	return nodo;
}

/**
 * Devuelve el nodo padre de nivel más bajo de este nodo
 * que pertenece a un ciclo al que pertenece este nodo.
 */
ll ciclo_mas_arriba(ll nodo, vector<set<ll>>& graph, vector<ll>& ciclos,
		vector<ll>& niveles, ll nivel, vector<bool>& padres) {

	padres[nodo] = true;
	niveles[nodo] = nivel;
	ll nodo_menor_nivel = nodo;
	for (ll hijo : graph[nodo]) {
		ll menor_ciclo;
		if (niveles[hijo] != -1) {
			// Ya fue visitado.
			menor_ciclo = updated_ciclo(hijo, ciclos);
		} else {
			// No fue visitado todavía.
			menor_ciclo = ciclo_mas_arriba(
				hijo, graph, ciclos, niveles, nivel + 1, padres);
		}
		if (padres[menor_ciclo] && niveles[menor_ciclo] < niveles[nodo_menor_nivel]) {
			nodo_menor_nivel = menor_ciclo;
		}
	}

	ciclos[nodo] = nodo_menor_nivel;
	padres[nodo] = false;
	return nodo_menor_nivel;
}


int main() {
	IOS;

	ll n;
	cin >> n;
	vector<ll> costs(n);
	forn (i) {
		cin >> costs[i];
	}

	ll m;
	cin >> m;
	vector<set<ll>> graph(n);
	fore (i, 0, m) {
		ll u, v;
		cin >> u >> v;
		u--;
		v--;
		graph[u].insert(v);
	}

	vector<ll> ciclos(n);
	forn (i) {
		ciclos[i] = i;
	}

	vector<ll> niveles(n, -1);
	vector<bool> padres(n, false);

	forn (i) {
		if (niveles[i] == -1) {
			ciclo_mas_arriba(i, graph, ciclos, niveles, 0, padres);
		}
	}

	vector<vector<ll>> componentes(n);

	forn (i) {
		componentes[updated_ciclo(i, ciclos)].push_back(i);
	}

	ll posib = 1;
	ll total = 0;
	forn (i) {
		if (!componentes[i].empty()) {
			ll min_cost = LONG_LONG_MAX;
			ll quant = 0;
			for (ll nodo : componentes[i]) {
				if (min_cost > costs[nodo]) {
					min_cost = costs[nodo];
					quant = 1;
				} else if (min_cost == costs[nodo]) {
					quant++;
				}
			}
			total += min_cost;
			posib *= quant;
			posib %= MOD;
		}
	}

	cout << total << " " << posib << endl;


	return 0;
}
