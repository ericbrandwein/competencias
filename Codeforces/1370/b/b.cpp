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

	// index, value
	vector<pair<ll, ll>> odds;
	vector<pair<ll, ll>> evens;
	fore (i, 0, 2*n) {
		ll num;
		cin >> num;
		if (num % 2 == 1) {
			odds.push_back({i, num});
		} else {
			evens.push_back({i, num});
		}
	}

	if (odds.size() % 2 == 0) {
		if (odds.empty()) {
			evens.pop_back();
			evens.pop_back();
		} else {
			odds.pop_back();
			odds.pop_back();
		}
	} else {
		// sacamos un odd y un even
		odds.pop_back();
		evens.pop_back();
	}

	vector<pair<ll, ll>> ops;
	for (ll i = 0; i < odds.size(); i+=2) {
		ops.push_back({odds[i].first, odds[i + 1].first});
	}
	for (ll i = 0; i < evens.size(); i+=2) {
		ops.push_back({evens[i].first, evens[i + 1].first});
	}
	for (pair<ll, ll>& op : ops) {
		cout << op.first+ 1 << " " << op.second + 1 << endl;
	}




}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();


	return 0;
}
