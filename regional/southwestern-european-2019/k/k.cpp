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


void filter_good_nodes(vec<Nodo>& graph, vec<bool>& good_nodes) {
	ll n = graph.size();

	vec<vec<ll>> componentes = tarjan(graph);
	vec<ll> componente_de_nodo(n);
	vec<vec<ll>> good_nodes_de_componente(componentes.size());
	for (ll i = 0; i < componentes.size(); i++) {
		for (ll nodo : componentes[i]) {
			componente_de_nodo[nodo] = i;
			if (good_nodes[nodo]) {
				good_nodes_de_componente[i].push_back(nodo);
			}
		}
	}

	vec<set<ll>> graph_de_componentes(componentes.size());
	vec<set<ll>> padres_de_componentes(componentes.size());
	for (ll i = 0; i < componentes.size(); i++) {
		for (ll nodo : componentes[i]) {
			for (ll hijo : graph[nodo].hijos) {
				if (componente_de_nodo[hijo] != i) {
					graph_de_componentes[i].insert(componente_de_nodo[hijo]);
					padres_de_componentes[componente_de_nodo[hijo]].insert(i);
				}
			}
		}
	}


	// Tengo que marcar las componentes a las que lleguen nodos buenos
	queue<ll> next;
	for (ll i = 0; i < componentes.size(); i++) {
		if (padres_de_componentes[i].empty()) next.push(i);
	}

	vec<ll> visited(componentes.size(), false);
	vec<ll> parents_visited(componentes.size(), 0);
	vec<bool> alcanzan_good_nodes(componentes.size(), false);
	while (!next.empty()) {
		ll curr = next.front();
		next.pop();
		if (!visited[curr] && parents_visited[curr] == padres_de_componentes[curr].size()) {
			bool hay_good_nodes = !good_nodes_de_componente[curr].empty() ||
				alcanzan_good_nodes[curr];
			for (ll child : graph_de_componentes[curr]) {
				next.push(child);
				parents_visited[child]++;
				alcanzan_good_nodes[child] = alcanzan_good_nodes[child] || hay_good_nodes;
			}
			visited[curr] = true;
		}
	}

	for (ll i = 0; i < componentes.size(); i++) {
		if (alcanzan_good_nodes[i] || good_nodes_de_componente[i].size() >= 2) {
			for (ll good_node : good_nodes_de_componente[i]) {
				good_nodes[good_node] = false;
			}
		}
	}






}

int main() {
	IOS;

	ll n, m, orig;
	cin >> n >> m >> orig;
	vec<bool> good_nodes(n, false);
	vec<Nodo> graph(n);
	fore (i,0, m) {
		ll from, to;
		cin >> to >> from;
		if (from == orig) {
			good_nodes[to] = true;
		} else if (to != orig) {
			graph[from].hijos.push_back(to);
		}
	}

	filter_good_nodes(graph, good_nodes);

	vec<ll> res;
	for (ll i = 0; i < n; i++) {
		if (good_nodes[i]) res.push_back(i);
	}
	cout << res.size() << endl;
	for (ll node : res) {
		cout << node << endl;
	}



	return 0;
}
