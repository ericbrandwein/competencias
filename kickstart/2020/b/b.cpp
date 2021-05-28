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
	vec<ll> nums(n);
	forn (i) cin >> nums[i];

	vec<ll> dif_der(n, LONG_LONG_MAX), dif_izq(n, LONG_LONG_MAX);
	vec<ll> eq_izq(n, 0), eq_der(n, 0);
	for (ll i = 1; i < n; i++) {
		dif_izq[i] = nums[i] - nums[i-1];
	}
	for (ll i = 0; i < n - 1; i++) {
		dif_der[i] = nums[i+1] - nums[i];
	}
	for (ll i = 1; i < n; i++) {
		eq_izq[i] = 1;
		if (dif_izq[i-1] == dif_izq[i]) {
			eq_izq[i] += eq_izq[i-1];
		}
	}
	for (ll i = n-2; i >= 0; i--) {
		eq_der[i] = 1;
		if (dif_der[i+1] == dif_der[i]) {
			eq_der[i] += eq_der[i+1];
		}
	}

	ll res = 2;
	for (ll i = 0; i < n; i++) {
		ll maxi = 2;
		if (i > 0 && i < n-1 && (nums[i+1] - nums[i-1]) % 2 == 0) {
			maxi = 3;
		}
		if (i > 0) {
			maxi = max(maxi, eq_izq[i-1] + 2);
		}
		if (i < n - 1) {
			maxi = max(maxi, eq_der[i+1] + 2);
		}
		if (i > 0 && i < n-1) {
			if (i-1> 0 && nums[i+1] - nums[i-1] == dif_izq[i-1] * 2) {
				if (dif_der[i+1] == dif_izq[i-1]) {
					maxi = max(maxi, eq_der[i+1] + eq_izq[i-1] + 3);
				} else {
					maxi = max(maxi, eq_izq[i-1] + 3);
				}
			} else if (i + 1 < n -1 && nums[i + 1] - nums[i-1] == dif_der[i+1] * 2) {
				maxi = max(maxi, eq_der[i+1] + 3);
			}
		}
		res = max(res, maxi);
	}
	cout << res << endl;

}


int main() {
	IOS;

	ll t;
	cin >> t;
	fore (i, 0, t) {
		cout << "Case #" << i + 1 << ": ";
		solve();
	}


}
