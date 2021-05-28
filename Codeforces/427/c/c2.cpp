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

struct Nodo {
    ll tiempo_encontrado = -1;
    ll menor_link = -1;
    ll en_stack = false;
    vector<ll> hijos;
};

/**
 * Calcula las componentes fuertemente conexas que se encuentran en el subárbol
 * debajo de este nodo.
 */
void encontrar(ll& tiempo, ll indice_nodo, vector<Nodo>& graph,
        vector<vector<ll>>& componentes, stack<ll>& componente_actual) {

    componente_actual.push(indice_nodo);
    Nodo& nodo = graph[indice_nodo];
    nodo.en_stack = true;
    nodo.tiempo_encontrado = tiempo;
    nodo.menor_link = tiempo;
    tiempo++;

    for (ll indice_hijo : nodo.hijos) {
        Nodo& hijo = graph[indice_hijo];
        if (hijo.tiempo_encontrado == -1) {
            // No lo encontramos todavía; calculamos su menor_link
            encontrar(tiempo, indice_hijo, graph, componentes, componente_actual);
            nodo.menor_link = min(nodo.menor_link, hijo.menor_link);
        } else if (hijo.en_stack) {
            // Este hijo en realidad es un padre nuestro que está
            // en componente_actual.
            // Si hijo no está en el stack pero sí lo encontramos en algún
            // momento, entonces ese hijo lo sacamos del stack en algún
            // momento porque estaba en otra componente conexa, o sea que
            // acá no hay que tenerlo en cuenta.
            nodo.menor_link = min(nodo.menor_link, hijo.tiempo_encontrado);
        }
    }

    if (nodo.menor_link == nodo.tiempo_encontrado) {
        // Es root de su Componente Fuertemente conexa, hay que sacarlo y a
        // todos sus hijos en el stack.
        componentes.emplace_back();
        ll actual;
        do {
            actual = componente_actual.top(); componente_actual.pop();
            componentes[componentes.size() - 1].push_back(actual);
            graph[actual].en_stack = false;
        } while (actual != indice_nodo);
    }
}

/**
 * Devuelve las componentes fuertemente conexas de graph en orden
 * topológico inverso.
 *
 * Complejidad: O(n + m).
 */
vector<vector<ll>> tarjan(vector<Nodo>& graph) {
    ll n = graph.size();
    vector<vector<ll>> componentes;
    stack<ll> componente_actual;

    ll tiempo = 0;
    for (ll i = 0; i < n; i++) {
        if (graph[i].tiempo_encontrado == -1) {
            encontrar(tiempo, i, graph, componentes, componente_actual);
        }
    }

    return componentes;
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
	vector<Nodo> graph(n);
	fore (i, 0, m) {
		ll u, v;
		cin >> u >> v;
		u--;
		v--;
		graph[u].hijos.push_back(v);
	}


	vector<vector<ll>> componentes = tarjan(graph);

	ll total = 0;
	ll posib = 1;
	for (ll i = 0; i < componentes.size(); i++) {
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

	cout << total << " " << posib << endl;


	return 0;
}
