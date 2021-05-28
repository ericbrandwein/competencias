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

	ll n;
	cin >> n;
	vec<ll> a(n);
	forn (i) cin >> a[i];

	if (n % 2 == 0) {
		for (ll i = 0; i < n; i++) {
			if (a[i] >= 0) {
				a[i] = -a[i] - 1;
			}
		}
	} else {
		for (ll i = 0; i < n; i++) {
			if (a[i] < 0) {
				a[i] = -a[i] - 1;
			}
			if (a[i] == 0) {
				a[i] = -a[i] - 1;
			}
		}
		bool all_zero = true;
		ll maxi = 0;
		for (ll i = 0; i < n; i++) {
			if (a[i] != -1) {
				all_zero = false;
			}
			if (a[i] > 0 && a[i] > a[maxi]) {
				maxi = i;
			}
		}

		if (all_zero) a[0] = 0;
		else {
			for (ll i = 0; i < n; i++) {
				if (i != maxi && a[i] != -1) {
					a[i] = -a[i] - 1;
				}
			}
		}
	}
	forn (i) {
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}
