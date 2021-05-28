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

bool bad(ll a, ll b, ll c) {
	return (a < b && c < b) || (a > b && c > b);
}

void solve() {
	ll n;
	cin >> n;
	vec<ll> a(n);
	forn (i) cin >> a[i];
	ll max_removed = 0;
	ll bads = 0;
	for (ll i = 0; i < n; i++) {
		ll removed = 0;
		if (i > 0 && i < n-1) {
			if (
				bad(a[i-1], a[i], a[i+1])
			) {
				removed++;
				bads++;
			}
		}
		ll removed_left = removed;
		if (i > 0) {
			if (i > 1 && bad(a[i-2], a[i-1], a[i])) {
				removed_left++;
			}
			if (i < n - 2){
				bool bad_before = bad(a[i], a[i+1], a[i+2]);
				bool bad_after = bad(a[i-1], a[i+1], a[i+2]);
				if (bad_before && !bad_after) {
					removed_left++;
				} else if (!bad_before && bad_after) {
					removed_left--;
				}
			}
		}
		ll removed_right = removed;
		if (i < n - 1) {
			if (i < n - 2 && bad(a[i], a[i+1], a[i+2])) {
				removed_right++;
			}
			if (i > 1) {
				bool bad_before = bad(a[i-2], a[i-1], a[i]);
				bool bad_after = bad(a[i-2], a[i-1], a[i+1]);
				if (bad_before && !bad_after) {
					removed_right++;
				} else if (!bad_before && bad_after) {
					removed_right--;
				}
			}
		}
		max_removed = max({max_removed, removed_right, removed_left});
	}
	cout << bads - max_removed << endl;

}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}
