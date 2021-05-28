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

ll solve(ll n, ll k) {
	ll max_divisor = 1;
	for (ll i = 1; i* i <= n && i <= k; i++) {
		if (n % i == 0) {
			if (i <= k) {
				max_divisor = max(max_divisor, i);
			}
			if (n / i <= k) {
				max_divisor = max(max_divisor, n / i);
			}
		}
	}
	return n / max_divisor;
}


int main() {
	IOS;

	ll t;
	cin >> t;

	for (ll i = 0; i < t; i++) {
		ll n, k;
		cin >> n >> k;

		cout << solve(n, k) << endl;

	}

	return 0;
}
