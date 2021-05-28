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
	ll n, starting, operations_q;
	cin >> n >> starting >> operations_q;
	vector<pair<ll, ll>> ops(operations_q);

	for (ll i = 0; i < operations_q; i++) {
		cin >> ops[i].first >> ops[i].second;
	}

	pair<ll, ll> interval = {-1, -1};

	for (pair<ll, ll>& op : ops) {
		if (op.second >= interval.first && op.first <= interval.second) {
			interval.first = min(op.first, interval.first);
			interval.second = max(op.second, interval.second);
		} else if (starting <= op.second && starting >= op.first) {
			interval = op;
		}
	}

	cout << interval.second - interval.first + 1 << endl;
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
