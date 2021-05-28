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

int main() {
	IOS;

	int a, b, c; cin>>a>>b>>c;
	vec<int> v = {a, b, c};
	sort(all(v));

	if( v[0]==1 && v[1]==2 ){
		cout<<"S"<<endl;
	}else if( v[0]==1  && v[1]==3 ){
		cout<<"S"<<endl;
	}else if( v[0]==1 && v[1]==4 && v[2]==5 ){
		cout<<"S"<<endl;
	}else if( v[0]==2 && v[1]==3 && v[2]==4 ){
		cout<<"S"<<endl;
	}else{
		cout<<"N"<<endl;
	}

	return 0;
}
