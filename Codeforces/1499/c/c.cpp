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
	vec<ll> c(n);
	forn (i) cin >> c[i];

	ll min_even = c[0];
	ll min_odd = c[1];
	ll min_tot = min_even*n + min_odd*n;
	ll sum_tot = min_even + min_odd;
	ll quedan_even = n - 1;
	ll quedan_odd = n - 1;
	for (ll i = 2; i < n; i++) {
		if (i % 2 == 0) {
			min_even = min(min_even, c[i]);
			quedan_even--;
		} else {
			min_odd = min(min_odd, c[i]);
			quedan_odd--;
		}
		sum_tot += c[i];
		min_tot = min(
			min_tot,
			sum_tot + quedan_even*min_even + quedan_odd*min_odd
		);
	}

	cout << min_tot << endl;
}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}
