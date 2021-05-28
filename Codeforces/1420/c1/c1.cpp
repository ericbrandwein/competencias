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

void solve() {
	ll n, q;
	cin >> n >> q;
	vec<ll> a(n);
	forn (i) cin >> a[i];

	vec<ll> best_sumando(n, 0), best_restando(n, 0);
	best_sumando[0] = a[0];
	best_restando[0] = 0;
	fore (i, 1, n) {
		best_sumando[i] = max(
			best_sumando[i-1], best_restando[i-1] + a[i]
		);
		best_restando[i] = max(
			best_sumando[i-1] - a[i], best_restando[i-1]
		);
	}

	cout << best_sumando[n - 1] << endl;
}

int main() {
	IOS;

	ll t;
	cin>>t;
	while (t--) solve();

	return 0;
}
