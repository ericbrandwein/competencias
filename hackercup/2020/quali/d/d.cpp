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
	ll n, length;
	cin >> n >> length;
	vector<ll> costs(n);
	forn (i) cin >> costs[i];

	if (length >= n - 1) {
		cout << 0 << endl;
		return;
	}

	vector<ll> cost_of_taking(n, 0);
	multiset<ll> last_costs;
	cost_of_taking[0] = 0;
	last_costs.insert(0);
	for (ll i = 1; i < length; i++) {
		cost_of_taking[i] = costs[i];
		if (cost_of_taking[i] != 0) {
			last_costs.insert(cost_of_taking[i]);
		}
	}
	for (ll i = length; i < n - 1; i++) {
		if (last_costs.empty()) {
			cout << -1 << endl;
			return;
		}

		if (costs[i] != 0) {
			ll min_ant = *last_costs.begin();
			cost_of_taking[i] = min_ant + costs[i];
			last_costs.insert(cost_of_taking[i]);
		}

		auto to_remove = last_costs.find(cost_of_taking[i - length]);
		if (to_remove != last_costs.end()) {
			last_costs.erase(to_remove);
		}
	}

	if (last_costs.empty()) {
		cout << -1 << endl;
		return;
	} else {
		ll best_cost = *last_costs.begin();
		cout << best_cost << endl;
	}




}


int main() {
	IOS;

	ll t;
	cin >> t;
	fore (i, 0, t) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}
	return 0;
}
