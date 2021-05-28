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
};// usage: ST st(a); st.set(i,v); st.query(q_l,q_r); []


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


int main() {
	IOS;

	ll n, k;
	cin >> n >> k;
	vec<vec<int>> graph(n);
	vec<int> parents(n);
	int raiz = 0;
	forn (i) {
		ll padre;
		cin >> padre;
		padre--;
		if (padre == -1) {
			raiz = i;
		} else {
			graph[padre].push_back(i);
		}
		parents[i] = padre;
	}



	DisjointSet sets(n);
	vec<pair<ll,ll>> consec(k);
	vec<ll> next(n, -1);
	vec<ll> prev(n, -1);
	fore (i, 0, k) {
		cin >> consec[i].first >> consec[i].second;
		consec[i].first--;
		consec[i].second--;
		sets.join(consec[i].first, consec[i].second);
		next[consec[i].first] = consec[i].second;
		prev[consec[i].second] = consec[i].first;
	}


	vec<vec<ll>> sets_orders(n);
	vec<bool> visited(n, false);
	for (ll i = 0; i < n; i++) {
		if (prev[i] == -1) {
			ll curr_set = sets.find(i);
			ll curr = i;
			while (curr != -1) {
				if (visited[curr]) {
					cout << 0 << endl;
					return 0;
				}
				sets_orders[curr_set].push_back(curr);
				visited[curr] = true;
				curr = next[curr];
			}
		}
	}

	LCA lca(raiz, graph);
	fore (i, 0, k) {
		ll ancestro = lca.query(consec[i].first, consec[i].second);
		if (
			(ancestro == consec[i].first && ancestro != parents[consec[i].second]) ||
			ancestro == consec[i].second
		) {
			cout << 0 << endl;
			return 0;
		}
	}



	vec<set<ll>> dependencies(n);
	vec<set<ll>> children_per_set(n);
	for (ll i = 0; i < n; i++) {
		if (parents[i] != -1) {
			ll set_de_nodo = sets.find(i);
			if (sets_orders[set_de_nodo].empty()) {
				cout << 0 << endl;
				return 0;
			}
			ll set_de_padre = sets.find(parents[i]);
			if (set_de_padre != set_de_nodo) {
				dependencies[set_de_nodo].insert(set_de_padre);
				children_per_set[set_de_padre].insert(set_de_nodo);
			}
		}
	}

	vec<ll> dependency_amount(n);
	set<pair<ll,ll>> parents_per_set;
	for (ll i = 0; i < n; i++) {
		dependency_amount[i] = dependencies[i].size();
		parents_per_set.insert({dependencies[i].size(), i});

	}


	vec<ll> res;
	vec<bool> usado(n, false);
	while (!parents_per_set.empty()) {
		pair<ll,ll> next_set = *(parents_per_set.begin());
		if (next_set.first != 0) {
			cout << 0 << endl;
			return 0;
		}

		ll curr_set = next_set.second;
		for (ll node : sets_orders[curr_set]) {
			res.push_back(node);
			if (usado[node]) {
				cout << 0 << endl;
				return 0;
			}
			usado[node] = true;
		}

		for (ll child_set : children_per_set[curr_set]) {
			parents_per_set.erase({dependency_amount[child_set], child_set});
			dependency_amount[child_set]--;
			parents_per_set.insert({dependency_amount[child_set], child_set});
		}
		parents_per_set.erase(next_set);
	}

	for (ll node : res) {
		cout << node + 1 << " ";
	}
	cout << endl;







}
