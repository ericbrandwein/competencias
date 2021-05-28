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
	ll h, c, t;
	cin >> h >> c >> t;

	if (t * 2 <= h + c) {
		cout << 2 << endl;
		return;
	}

	long double best_diff = h - t;
	ll k = 1;

	long double cups = (long double) (t - h) / (c + h - 2 * t);
	vector<ll> poss_cups = {(ll) floor(cups), (ll) ceil(cups)};

	for (ll poss : poss_cups) {
		if (poss > 0) {
			long double new_diff = abs((long double) (poss * c + poss * h + h) / (2*poss + 1) - t);
			if (new_diff < best_diff) {
				best_diff = new_diff;
				k = 2*poss + 1;
			}
		}
	}

	cout << k << endl;
}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) {
		solve();
	}


	return 0;
}
