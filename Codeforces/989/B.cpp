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
#define deb(x) cerr<<#x<<" = "<<x<<endl
#define PI 3.14159265358979323
#define sen(ang) sin((ang)*PI/180)
//cout<<flush;

using namespace std;

int main() {
	IOS;

	int n, p; cin>>n>>p;
	vec<char> v(n);
	forn(i)cin>>v[i];

	bool posible = false;
	forn(i){
		if((i+p)>=n) break;
		if( v[i]=='0' && v[i+p]=='1'){
			posible = true;
		}else if(v[i]=='1' && v[i+p]=='0'){
			posible = true;
		}else if( v[i]=='.' && v[i+p]=='1' ){
			v[i]='0'; posible=true;
		}else if( v[i]=='.' && v[i+p]=='0' ){
			v[i]='1'; posible=true;
		}else if( v[i]=='1' && v[i+p]=='.' ){
			v[i+p]='0'; posible=true;
		}else if( v[i]=='0' && v[i+p]=='.' ){
			v[i+p]='1'; posible=true;
		}else if( v[i]=='.' && v[i+p]=='.' ){
			v[i]='1'; v[i+p]='0'; posible=true;
		}
	}

	if(!posible)cout<<"No"<<endl;
	else{
		for(auto it: v){
			if(it=='.') cout<<'1';\
			else cout<<it;	
		}cout<<endl;
	}


	return 0;
}
