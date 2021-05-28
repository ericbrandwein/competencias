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

ll M = 1000000007LL;

int main() {
	IOS;

	ll n; cin>>n;
	vec<ll> p(n);
	forn(i) cin>>p[i]; sort(all(p));
	vec<ll> c(n);
	forn(i) cin>>c[i]; sort(all(c));

	ll ans = 1;
	ll pasados = 0;
	for(ll i=n-1; i>=0; i--){
		//cuantos mas grandes en c de p[i]
		auto it = lower_bound(all(c), p[i]);
		//dbg(*it);
		ll cuantos = c.end()-it;
		//dbg(cuantos);
		if( (cuantos-pasados)<=0 ){
			cout<<0<<endl; return 0;
		}
		ans *= (cuantos - pasados);
		ans %= M;
		pasados++;
	}

	cout<<ans<<endl;


	return 0;
}
