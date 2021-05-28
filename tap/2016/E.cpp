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

void decrecer(vec<vec<int>>& g, vec<int>& act){

	for(int i=0; i<g[0].size(); i++){
		
		int color = i;
		set<int> prox;
		for(int i=0; i<g.size(); i++){
			prox.insert( g[i][color] );
		}

		if( prox.size() < act.size() ){
			act = vec<int>(all(prox));
			return;
		}
	}
}

void dfs(int nodo, vec<vec<int>> &g, vec<bool>& visitados){
	if( visitados[nodo] ) return;
	visitados[nodo]=true;
	for(auto it: g[nodo]) dfs(it, g, visitados);
}

int main() {
	IOS;

	int n, m; cin>>n>>m;

	vec< vec<int> > g(n);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int x; cin>>x; x--;
			g[i].push_back(x);
		}
	}

	int nodos = n;
	vec<int> actuales;
	for(int i=0; i<n; i++) actuales.push_back(i);

	while( nodos!=1 ){

		decrecer( g, actuales );

		if( actuales.size() >= nodos ){
			cout<<"N"<<endl;
			return 0;
		}
		nodos = actuales.size();
	}

	vec<bool> visitados(n, false);
	dfs( actuales[0], g, visitados );

	if( visitados[0] ) cout<<"S"<<endl;
	else cout<<"N"<<endl;

	return 0;
}
