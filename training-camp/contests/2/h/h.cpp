// #pragma GCC optimize("Ofast")
// #pragma comment(linker, "/STACK: 20000000")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vec vector
#define all(x) x.begin(), x.end()
#define deb(x) cerr<<#x<<" = "<<x<<endl
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct UF{
	vec<int> f;
	void init(int n){f.clear(); f.insert(f.begin(),n,-1);}
	int comp(int x){return (f[x]==-1?x:f[x]=comp(f[x]));}
	bool join(int i, int j){
		bool con=comp(i)==comp(j);
		if(!con) f[comp(i)]=comp(j);
		return con;
	}
};

/*
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


void dfs(int x, vec<bool>& visited, vec<vec<int>>& g){
	if(visited[x])return;
	visited[x]=true;
	for(auto&child:g[x])dfs(child,visited,g);
}

int main(){IOS;
	int n,m,k;cin>>n>>m>>k;
	vec<int> level(k); for(auto&it:level){
		cin>>it;
		it--;
		}
	vec<vec<int>> g(n);
	while(m--){
		int a,b;cin>>a>>b;a--,b--;
		g[a].push_back(b); g[b].push_back(a);
	}
	int s,t;cin>>s>>t;s--,t--;
	vec<bool> visited(n,false);
	dfs(s,visited,g);
	if(!visited[t]){cout<<-1<<endl;return 0;}

	DisjointSet uf(n);
	int ans = 0;
	while( uf.find(s) != uf.find(t) ){
		ans++;
		vec<int> next_level;
		for(auto&parent:next_level){
			for(auto&child:g[parent]){
				if( uf.find(child) == uf.find(parent) ) continue;
				next_level.push_back(child);
				uf.join(child,parent);
			}
		}
		next_level = level;
	}
	cout<<ans<<endl;
}