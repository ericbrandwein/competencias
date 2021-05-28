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

void calc_altura(vec<vec<ll>>& arbol, vec<set<pair<ll,ll>>>& graph, ll from, ll padre) {
	for (ll child : arbol[from]) {
		calc_altura(arbol, graph, child, from);
	}

	ll max_altura = 1;
	for (pair<ll,ll> child : graph[from]) {
		max_altura = max(max_altura, child.first + 1);
	}
	graph[padre].insert({max_altura, from});
}


ll sacar_mafias(vec<set<pair<ll,ll>>>& graph) {
	ll sacados = 1;
	ll nodo = 0;
	pair<ll,ll> mas_grande = *(--graph[nodo].end());
	graph[nodo].erase(mas_grande);
	nodo = mas_grande.second;
	while (!graph[nodo].empty()) {
		mas_grande = *(--graph[nodo].end());
		for (pair<ll,ll> hijo : graph[nodo]) {
			if (hijo != mas_grande) {
				graph[0].insert(hijo);
			}
		}

		graph[nodo].clear();

		nodo = mas_grande.second;
		sacados++;
	}
	return sacados;
}


int main() {
	IOS;

	ll n, k;
	cin >> n >> k;
	vec<vec<ll>> arbol(n+1);
	fore (i ,2, n+1) {
		ll superior;
		cin >> superior;
		arbol[superior].push_back(i);
	}

	vec<set<pair<ll,ll>>> graph(n+1); // altura, indice
	calc_altura(arbol, graph, 1, 0);

	ll total = 0;
	while (k--) total += sacar_mafias(graph);


	cout << total << endl;
	return 0;
}
