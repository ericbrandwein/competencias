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

const ll MOD = 1000'000'007;

struct Edge {
	ll to;
	ll weight;
};

struct Arista {
	ll from, to;
	ll weight;
};


int main() {
	IOS;

	ll nodes_q, edges_q, max_path_length;
	cin >> nodes_q >> edges_q >> max_path_length;

	vector<vector<Edge>> graph(nodes_q);
	vector<Arista> aristas(edges_q);
	fore (i, 0, edges_q) {
		ll from, to, weight;
		cin >> from >> to >> weight;
		from--;
		to--;
		graph[from].push_back({to, weight});
		graph[to].push_back({from, weight});
		aristas.push_back({from, to, weight});
	}

	ll sum = 0;
	vector<ll> max_path_weights(nodes_q, 0);
	set<ll> current_nodes = {0};
	fore (i, 0, edges_q) {
		set<ll> new_nodes;
		vector<ll> new_max_path_weights(nodes_q, 0);

		ll max_weight = 0;
		for (ll from : current_nodes) {
			for (Edge& edge : graph[from]) {
				ll path_weight = max_path_weights[from] + edge.weight;
				new_max_path_weights[edge.to] = max(
					new_max_path_weights[edge.to],
					path_weight
				);
				new_nodes.insert(edge.to);
				max_weight = max(max_weight, new_max_path_weights[edge.to]);
			}
		}

		max_weight %= MOD;
		sum += max_weight;
		sum %= MOD;

		current_nodes = new_nodes;
		max_path_weights = new_max_path_weights;
	}

	// En max_path_weights están los pesos de los caminos de largo edges_q.
	// Para cada arista, por lo menos uno de sus nodos tiene un valor en max_path_weights.
	// Demo: Todos los nodos son alcanzables por un camino de cantidad de aristas edges_q o
	// menos, ya que sino no sería conexo. Si existe un camino de cantidad par de aristas c
	// a un nodo i, existen caminos a i para toda cantidad par de aristas mayor a c.
	// Lo mismo para cantidades impares. Consideremos la arista (v, w). Si existe un camino de
	// cantidad par de aristas a uno de los nodos, existe uno de cantidad impar de aristas al
	// otro. Supongamos que edges_q es de una paridad y v tiene un camino de cantidad de aristas
	// de la misma paridad,
	// entonces existe un camino de edges_q a v, y por lo tanto está en max_path_weights.
	// Supongamos que la paridad entre edges_q y v es distinta, entonces w tiene la misma
	// paridad que edges_q, y entonces existe un camino de edges_q + 1 ... blahblah

	// Agarramos el nodo de camino más pesado para cada arista.
	vector<ll> mayor_peso_por_arista(edges_q);
	fore (i, 0, aristas.size()) {
		Arista& arista = aristas[i];
		ll peso_from = max_path_weights[arista.from];
		ll peso_to = max_path_weights[arista.to];
		mayor_peso_por_arista[i] = max(peso_from, peso_to);
	}

	// Calculamos la intersección entre la recta de mayor peso y cada una de las otras rectas,
	// desechamos las que ocurren antes que edges_q
	ll arista_de_camino_de_mayor_peso = 0;
	fore (i, 0, aristas.size()) {
		if (
			mayor_peso_por_arista[arista_de_camino_de_mayor_peso] < mayor_peso_por_arista[i] ||
			mayor_peso_por_arista[arista_de_camino_de_mayor_peso] == mayor_peso_por_arista[i] &&
			aristas[arista_de_camino_de_mayor_peso].weight < aristas[i].weight
		) {
			arista_de_camino_de_mayor_peso = i;
		}
	}

	// Interseccion de rectas:
	// a1x + b1 = a2x + b2
	// x = (a2x + b2 - b1) / a1
	// x = (a2/a1)x + (b2 - b1)/a1
	// (1 - a2/a1)x = (b2 - b1)/a1
	// x = ((b2 - b1)/a1)/(1 - a2/a1)
	// x = (b2 - b1)/(a1 - a2)

	ll current_length = edges_q;


	// En la suma tenemos ya as longitudes de los edges_q caminos.




	cout << sum << endl;

	return 0;
}
