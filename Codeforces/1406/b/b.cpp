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

	vec<ll> biggest = a;
	vec<ll> smallest = a;
	for (ll i = 1; i < 5; i++) {
		ll smallest_yet = smallest[i - 1];
		ll biggest_yet = biggest[i-1];
		for (ll pos = i; pos < n; pos++) {
			ll new_biggest = max(biggest_yet * a[pos], smallest_yet * a[pos]);
			ll new_smallest = min(biggest_yet * a[pos], smallest_yet * a[pos]);
			smallest_yet = min(smallest_yet, smallest[pos]);
			biggest_yet = max(biggest_yet, biggest[pos]);
			biggest[pos] = new_biggest;
			smallest[pos] = new_smallest;
		}
	}

	ll res = LONG_LONG_MIN;
	for (ll i = 4; i < n; i++) {
		res = max(res, biggest[i]);
	}

	cout << res << endl;
}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
