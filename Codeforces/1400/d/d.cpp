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
	ll n;
	cin >> n;
	vec<ll> a(n);
	forn (i) cin >> a[i];


	vec<vec<ll>> iguales_despues(n, vec<ll>(n, 0));
	forn (from) {
		for (ll to = n - 2; to > from; to--) {
			iguales_despues[from][to] = iguales_despues[from][to + 1];
			if (a[from] == a[to+1]) iguales_despues[from][to]++;
		}
	}

	ll total = 0;
	for (ll i = n - 2; i > 0; i--) {
		ll posib = 0;
		for (ll j = i - 1;j >= 0; j--) {
			if (a[j] == a[i]) {
				total += posib;
			}
			posib += iguales_despues[j][i];
		}
	}

	cout << total << endl;

}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();


	return 0;
}
