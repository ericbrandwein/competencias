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

#define P 998244353LL

ll f(vec<ll>&a, vec<ll>&b, ll i){
	return (a[i-1LL]*b[i-1LL])%P;
}

int main() {
	IOS;

	ll n; cin>>n;
	
	vec<ll> a(n);
	forn(i)cin>>a[i];
	sort(all(a));

	vec<ll> b(n);
	forn(i)cin>>b[i];
	sort(all(b));

	//acomodar a,b

	vec<ll> ans;
	ans.push_back(f(a, b, 1LL));
	for(ll i=2LL; i<=n; i++){
		ans.push_back( f(a,b,i)*i + ans.back() );
	}

	ll sum = 0LL;
	for(auto it: ans) sum+=it;

	//cout<<sum<<endl;
	
	return 0;
}
