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


bool can_remove(vec<ll>& a, ll start_i, vec<pair<ll,ll>>& ops) {
	multiset<ll> available(all(a));
	ops.push_back({a.back(), a[start_i]});
	available.erase(available.find(a.back()));
	available.erase(available.find(a[start_i]));

	ll current_sum = a.back();
	for (ll i = (ll)a.size() - 2; i >= 0; i--) {
		if (available.count(a[i]) > 0) {
			available.erase(available.find(a[i]));
			ll searched = current_sum - a[i];
			auto it = available.find(searched);
			if (it == available.end()) {
				return false;
			} else {
				ops.push_back({a[i], searched});
				available.erase(it);
			}
			current_sum = a[i];
		}
	}
	return true;
}

void solve() {
	ll n;
	cin >> n;
	vec<ll> a(2*n);
	fore (i, 0, 2*n) cin >> a[i];
	sort(all(a));
	fore (i, 0, a.size() - 1) {
		vec<pair<ll,ll>> ops;
		if (can_remove(a, i, ops)) {
			cout << "YES" << endl;
			cout << a.back() + a[i] << endl;
			for (pair<ll,ll> op : ops) {
				cout << op.first << " " << op.second << endl;
			}
			return;
		}
	}
	cout << "NO" << endl;
}


int main() {
	IOS;

	ll t;
	cin >> t;
	while(t--) solve();

}
