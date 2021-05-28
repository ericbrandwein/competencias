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

#define OP(a,b) min(a, b)
using TYPE = int;
const TYPE NEUT = 1e9;

struct ST {
	vec<TYPE> elems;
	void init(vec<TYPE> &a){ // O(n)
		int size = 1;
		while(size<a.size()) size*=2;
		elems.assign(size*2,NEUT);
		_init(0,0,size-1,a);
	}
	void _init(int node, int i_from, int i_to, vec<TYPE>& a){
		if(i_from>=a.size())return;
		if(i_from==i_to) {elems[node]=a[i_from]; return;}
		int mid = (i_from+i_to)/2;
		_init(node*2+1,i_from,mid,a);
		_init(node*2+2,mid+1,i_to,a);
		elems[node] = OP(elems[node*2+1], elems[node*2+2]);
	}
	void set(int i, TYPE value){ // O(log n)
		_set(0,0,elems.size()/2-1,i,value);
	}
	void _set(int node, int i_from, int i_to, int i, TYPE value){
		if(i_from==i_to){ elems[node]=value; return; }
		int mid = (i_from+i_to)/2;
		if(i<=mid) _set(node*2+1,i_from,mid,i,value);
		else _set(node*2+2,mid+1,i_to,i,value);
		elems[node] = OP(elems[node*2+1], elems[node*2+2]);
	}
	TYPE query(int q_left, int q_right){ // O(log n)
		return _query(0,0,elems.size()/2-1,q_left,q_right);
	}
	TYPE _query(int node, int i_from, int i_to, int q_left, int q_right){
		if(q_left<=i_from && i_to<=q_right) return elems[node];
		if(q_left>i_to || q_right<i_from) return NEUT;
		int mid = (i_from+i_to)/2;
		return OP(_query(node*2+1,i_from,mid,q_left,q_right),
				_query(node*2+2,mid+1,i_to,q_left,q_right));
	}
};


int eulerian_path(
    int node, vector<vector<int>>& tree, vector<int>& path, vector<int>& apparitions,
    vector<int>& nodes_for_times, int parent = -1, int time = 0
) {
    apparitions[node] = path.size();
    nodes_for_times[time] = node;
    path.push_back(time);
    int new_time = time;
    for (int child : tree[node]) {
        if (child != parent) {
            new_time++;
            new_time = eulerian_path(child, tree, path, apparitions, nodes_for_times, node, new_time);
            path.push_back(time);
        }
    }
    return new_time;
}


/**
 * Calculate the lowest common ancestors of two nodes of a tree.
 *
 * Complexity:
 * - Creation time: O(n)
 * - Query time: O(log(n))
 * - Memory: O(n)
 */
struct LCA {
    ST rmq;
    vector<int> apparitions, nodes_for_times;

    LCA(int root, vector<vector<int>>& tree) : apparitions(tree.size(), -1), nodes_for_times(tree.size(), -1) {
        vector<int> path;
        eulerian_path(root, tree, path, apparitions, nodes_for_times);
        rmq.init(path);
    }

    /**
     * Returns the lowest common ancestor between nodes a and b.
     * a and b must be 0-indexed.
     * Complexity: O(log n)
     */
    int query(int a, int b) {
        int apa = apparitions[a], apb = apparitions[b];
        return nodes_for_times[rmq.query(min(apa, apb), max(apa, apb))];
    }
};




vec<ll> calcular_min_costos(vec<ll>& costos) {
	ll k = costos.size() - 1;
	vec<ll> min_costos(k+1, LONG_LONG_MAX);
	min_costos[0] = 0;
	for (ll i = 1; i <= k;i++) {
		for (ll j = 1; j <= i;j++) {
			min_costos[i] = min(
				min_costos[i],
				costos[j] + min_costos[i-j]
			);
		}
	}
	return min_costos;
}

vec<vec<ll>> enraizar(vec<vec<ll>>& graph, vec<ll>& padres, vec<ll>& alturas) {
	ll n = graph.size();
	vec<vec<ll>> hijos(n);
	stack<ll> next;
	next.push(0);
	while (!next.empty()) {
		ll curr = next.top();
		next.pop();

		for (ll hijo : graph[curr]) {
			if (padres[curr] != hijo) {
				hijos[curr].push_back(hijo);
				padres[hijo] = curr;
				next.push(hijo);
				alturas[hijo] = alturas[curr] + 1;
			}
		}
	}

	return hijos;
}

int main() {
	IOS;

	ll n;
	cin >> n;
	vec<vec<ll>> graph(n);
	fore (i, 0, n-1) {
		ll from, to;
		cin >> from >> to;
		from--;
		to--;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	vec<ll> padres(n, -1), alturas(n, 0);
	vec<vec<ll>> hijos = enraizar(graph, padres, alturas);

	LCA lca(0, graph);



	ll t;
	cin >> t;
	while (t--) {
		ll k;
		cin >> k;
		vec<ll> pibes_abajo(n, 0);
		vec<ll> lugares;
		fore (i,0,k) {
			ll lugar;
			cin >> lugar;
			lugar--;
			pibes_abajo[lugar]++;

			lugares.push_back(lugar);
		}

		vec<ll> lcas;
		for (ll i = 0; i < lugares.size() - 1; i++) {
			lcas.push_back(lca.query(lugar[i], lugar[i+1]));
		}
		ll mini =  *min_element(all(lcas));






		vec<ll> costos(k +1);
		fore (i,1,k+1) cin >> costos[i];

		vec<ll> min_costos = calcular_min_costos(costos);
		vec<ll> costo_por_nodo(n, 0);


		stack<ll> next;
		for (ll i = 0; i < n; i++) {
			if (hijos[i].empty()) next.push(i);
		}

		vec<ll> hijos_llenados(n,0);

		while (!next.empty()) {
			ll curr = next.top();
			next.pop();
			if (hijos_llenados[curr] == hijos[curr].size()) {
				for (ll hijo : hijos[curr]) {
					pibes_abajo[curr] += pibes_abajo[hijo];
					costo_por_nodo[curr] += costo_por_nodo[hijo];
				}

				if (padres[curr] != -1) {
					hijos_llenados[padres[curr]]++;
					next.push(padres[curr]);
					costo_por_nodo[curr] += min_costos[pibes_abajo[curr]];
				}
			}
		}

		cout << costo_por_nodo[0] << endl;
	}



}
