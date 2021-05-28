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

	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll moves;
		cin >> moves;
		ll left;
		cin >> left;

		vector<ll> a(n);
		forn (i) cin >> a[i];

		ll best = 0;
		fore (i, 0, moves+1) {
			best += a[i];
		}
		ll without_pairs = best;

		for (ll i = 1; i <= left && 2*i <= moves; i++) {
			ll curr = without_pairs;

			ll best_pair = 0;
			ll best_pair_sum = 0;
			ll last_pos = moves - 2*i;
			// find the best pair
			for (ll pos = 0; pos <= last_pos; pos++) {
				ll curr_sum = a[pos] + a[pos+1];
				if (best_pair_sum < curr_sum) {
					best_pair_sum = curr_sum;
					best_pair = pos;
				}
			}

			ll with_pair = curr;
			for (ll pos = last_pos + 1; pos <= moves; pos++) {
				with_pair -= a[pos];
			}

			with_pair += best_pair_sum * i;
			best = max(best, with_pair);
		}

		cout << best << endl;

	}

	return 0;
}
