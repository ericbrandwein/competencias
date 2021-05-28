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
	vec<ll> ultimos;
	ll curr = n;
	while (curr > 2) {
		ultimos.push_back(curr);
		curr = ceil(sqrt((ld)curr));
	}
	vec<pair<ll,ll>> ops;
	for (ll i = 3; i <= n - 1; i++) {
		if (count(ultimos.begin(), ultimos.end(), i) == 0) {
			ops.emplace_back(i, i+1);
		}
	}
	for (ll num : ultimos) {
		ll root = ceil(sqrt((ld)num));
		ops.emplace_back(num, root);
		ops.emplace_back(num, root);
	}

	cout << ops.size() << endl;
	for (pair<ll,ll> op : ops) {
		cout << op.first << " " << op.second << endl;
	}
}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--)solve();


}
