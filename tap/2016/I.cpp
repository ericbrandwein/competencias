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

void solve(vec<int>& v, int ancho, int lineas){
	int maximo = *max_element(all(v));
	if(maximo>ancho){
		cout<<"N"<<endl;
		exit(0);
	}
	vec<int> resto;
	for(int i=lineas; i<v.size(); i++){
		resto.push_back( v[i] );
	}

	if( resto.size() ){
		solve( resto, ancho-maximo, lineas );
	}
}

int main() {
	IOS;

	int n, l, c; cin>>n>>l>>c;
	vec<int> v(n); forn(i)cin>>v[i];
	sort(all(v)); reverse(all(v));

	solve(v, c, l);
	cout<<"S"<<endl;

	return 0;
}
