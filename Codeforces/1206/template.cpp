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

	ll n; cin>>n;

	if( (n%2)==0 ){
		cout<<"NO"<<endl;
		return 0;
	}

	ll magia = 2;
	vec<ll> primero(n);
	for(ll i=0; i<n; i+=2){
		primero[i] = magia;
		if(i < (n-1)){
			primero[i+1] = magia+1;
		}
		magia += 4;
	}

	vec<ll> segundo(n);
	for(ll i=0; i<n; i+=2){
		segundo[i] = primero[i]-1;
		if(i<(n-1)) segundo[i+1] = primero[i]+2;
	}
	reverse(all(primero));

	cout<<"YES"<<endl;
	for(ll i=0; i<n; i++) cout<<segundo[i]<<" ";
	for(ll i=n-1; i>=0; i--) cout<<primero[i]<<" ";
	cout<<endl;

	return 0;
}
