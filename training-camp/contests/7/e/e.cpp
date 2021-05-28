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


namespace dinics {

constexpr int noparent = -1;
/**
 * - los nodos se numeran de 0 a n-1.  En caso en que se numeren de 1 a n, simplemente generar un flowgraph con n+1 vertices
 *   sin conectar nada al vertice 0.
 *
 * COMPLEJIDAD
 * - O(n^2m). - Si todas las capacidades 1, cuesta O(min(m^1/2, n^2/3)m) => O(n^{2/3}m) denso O(m^{3/2}) ralos.
 * - Bipartito cuesta O(sqrt(n)m).
 */
class flowgraph {
    struct edge {
        long long from,         //vertice del que parte la arista; solo por simetria y para simplificar, se puede sacar
                  to,           //vertice al que llega la arista
                  capacity,     //capacidad de la arista
                  flow,         //flujo de la arista, el residual es capacity - flow
                  reverse;      //indice a la arista reversa en el grafo residual
    };
    template<class T>
    using digraph = vector<vector<T>>;
public:
    digraph<edge> residual;

    inline edge& reverse(const edge& e) {
        return residual[e.to][e.reverse];
    }

    digraph<int> find_level_graph(int source) {
        digraph<int> level_graph(residual.size());
        vector<int> level(residual.size(), noparent);
        deque<int> q(1, source);
        level[source] = 0;

        while(not q.empty()) {
            auto v = q.front(); q.pop_front();
            for(int idx = 0; idx < residual[v].size(); ++idx) {
                auto& e = residual[v][idx];
                if(e.flow == e.capacity) continue;
                if(level[e.to] == noparent) {
                    q.push_back(e.to);
                    level[e.to] = level[v] + 1;
                }
                if(level[e.to] > level[v]) level_graph[v].push_back(idx);
            }
        }
        return level_graph;
    }

    long long find_augmenting_path(digraph<int>* level_graph, int from, int sink, vector<int>* parent, vector<int>* index) {
        while(not level_graph->at(from).empty()) {
            auto& e = residual[from][level_graph->at(from).back()];
            auto success = e.capacity-e.flow;
            if(success > 0 && e.to != sink) success = min(success, find_augmenting_path(level_graph, e.to, sink, parent, index));
            if(success == 0) {
                //arista saturada! o dead end!
                level_graph->at(from).pop_back();
                continue;
            }
            //camino encontrado.  Guardamos la informacion y retornamos el flujo
            parent->at(e.to) = e.from;
            index->at(e.to) = level_graph->at(from).back();
            return min(success, e.capacity - e.flow);
        }
        //no habia augmenting path
        return 0;
    }

    long long find_blocking_flow(int source, int sink) {
        auto level_graph = find_level_graph(source);

        vector<int> parent(residual.size(), noparent);
        vector<int> index(residual.size(), 0);
        long long ans=0, volume;

        while((volume = find_augmenting_path(&level_graph, source, sink, &parent, &index)) > 0) {
            for(int to = sink; parent[to] != noparent; to = parent[to]) {
                auto& e = residual[parent[to]][index[to]];
                e.flow += volume;
                reverse(e).flow -= volume;
            }
            ans += volume;
        }
        return ans;
    }


//public:
    flowgraph(int n) {
        residual.assign(n, vector<edge>());
    }

    void add_edge(int from, int to, long long capacity) {
        if(capacity <= 0) return;
        auto idxfrom = (int)residual[from].size(), idxto = (int)residual[to].size();
        residual[from].push_back(edge{from, to, capacity, 0, idxto});
        residual[to].push_back(edge{to, from, 0, 0, idxfrom});
    }

    long long maxflow(int source, int sink) {
        long long res = 0, step;
        while((step = find_blocking_flow(source, sink)) > 0) {
            res += step;
        }
        return res;
    }

    void print() {
        for(int f = 0; f < residual.size(); ++f) {
            cout << f << ": ";
            for(auto e : residual[f]) {
                auto& rev = reverse(e);
                cout << "(" << e.from << "," << e.to << "," << e.capacity << "," << e.flow << ") {"
                    << rev.from << "," << rev.to << ","  << rev.capacity << "," << rev.flow << "}  -  ";
            }
            cout << endl;
        }
    }
};
}

using namespace dinics;

map<ll, ll> calculate_factors(ll num) {
	map<ll, ll> factors;

	ll prime = 2;
	ll orig = num;
	while (num > 1 && prime * prime <= orig) {
		while (num % prime == 0) {
			num/= prime;
			factors[prime]++;
		}
		prime++;
	}
	if (num > 1) {
		factors[num]++;
	}
	return factors;
}


int main() {
	IOS;


	ll n, m;
	cin >> n >> m;
	vector<ll> a(n);
	forn (i) cin >> a[i];

	vec<pair<ll, ll>> good(m);
	fore (i, 0, m) {
		cin >> good[i].first >> good[i].second;
		good[i].first--;
		good[i].second--;
		if (good[i].second % 2 == 0) {
			swap(good[i].first, good[i].second);
		}
	}

	vector<map<ll, ll>> factors(n);
	vector<ll> first_node(n + 1);
	// El primero es el source
	first_node[0] = 1;
	forn (i) {
		factors[i] = calculate_factors(a[i]);
		first_node[i + 1] = first_node[i] + factors[i].size();
	}
	// 1 más para el sink
	ll node_quantity = 1 + first_node[n];
	flowgraph graph(node_quantity);

	for (ll i = 0; i < n; i+=2) {
		// source to evens
		ll pos = first_node[i];
		for (auto& factor:factors[i]) {
			graph.add_edge(0, pos, factor.second);
			pos++;
		}
	}

	for (ll i = 1; i < n; i+=2) {
		// odds to sink
		ll pos = first_node[i];
		for (auto& factor:factors[i]) {
			graph.add_edge(pos, node_quantity - 1, factor.second);
			pos++;
		}
	}


	for (ll i = 0; i < m; i++) {
		pair<ll, ll>& curr = good[i];
		ll pos_first = first_node[curr.first];
		ll pos_second = first_node[curr.second];
		auto factor_first = factors[curr.first].begin();
		auto factor_second = factors[curr.second].begin();
		while (
			factor_first != factors[curr.first].end() &&
			factor_second != factors[curr.second].end()
		) {
			if (factor_first->first < factor_second->first) {
				factor_first++;
				pos_first++;
			} else if (factor_second->first < factor_first->first) {
				factor_second++;
				pos_second++;
			} else {
				// son iguales, conectamos los nodos
				graph.add_edge(pos_first, pos_second, LONG_LONG_MAX);
				factor_first++;
				factor_second++;
				pos_first++;
				pos_second++;
			}
		}
	}

	cout << graph.maxflow(0, node_quantity - 1) << endl;

	return 0;
}
