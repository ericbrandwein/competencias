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

bool intersect(ll first, ll second, ll k) {
	return first < second + k && second < first + k;
}

void solve() {
	ll n, k;
	cin >> n >> k;
	vec<ll> h(n);
	forn (i) cin >> h[i];

	vec<ll> placements = h;
	for (ll i = 1; i < n - 1; i++) {
		ll min_place = max(h[i], placements[i-1] - k + 1);
		ll max_place = min(h[i] + k - 1, placements[i-1] + k - 1);
		if (h[i + 1] < h[i]) {
			placements[i] = min_place;
		} else {
			placements[i] = max_place;
		}
	}

	fore (i, 0, n-1) {
		if (!intersect(placements[i], placements[i+1], k)) {
			cout << "NO" << endl;
			return;
		}
	}
	forn (i) {
		if (placements[i] < h[i] || placements[i] > h[i] + k - 1) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();



}
