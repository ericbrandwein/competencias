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
	ll n, l, r;
	cin >> n >> l >> r;
	map<ll, ll> left;
	map<ll, ll> right;
	for (ll i = 0; i < l; i++) {
		ll num;
		cin >> num;
		left[num]++;
	}
	for (ll i = 0; i < r; i++) {
		ll num;
		cin >> num;
		right[num]++;
	}

	ll cost = 0;
	map<ll,ll> new_left;
	for (auto it : left) {
		ll color = it.first;
		ll amount = it.second;
		ll amount_right = right[color];
		ll removed = min(amount, amount_right);
		ll remaining_left = amount - removed;
		new_left[color] = remaining_left;
		right[color] -= removed;
	}

	// leftsocks are different from right socks
	ll sobran = abs(l - r);
	map<ll,ll> new_new_left, new_new_right;
	if (l > r) {
		for (auto it : new_left) {
			ll color = it.first;
			ll amount = it.second;
			ll removed = min((amount / 2) * 2, sobran);
			sobran -= removed;
			new_new_left[color] = amount - removed;
			cost += removed / 2;
		}
		new_new_right = right;
	} else {
		for (auto it : right) {
			ll color = it.first;
			ll amount = it.second;
			ll removed = min((amount / 2) * 2, sobran);
			sobran -= removed;
			new_new_right[color] = amount - removed;
			cost += removed / 2;
		}
		new_new_left = new_left;
	}

	cost += sobran / 2;
	ll socks = 0;
	for (auto it : new_new_left) {
		socks += it.second;
	}
	for (auto it : new_new_right) {
		socks += it.second;
	}
	cost += socks / 2;
	cout << cost << endl;
	// map<ll,ll> new_right;
	// for (auto it : right) {
	// 	ll color = it.first;
	// 	ll amount = it.second;
	// 	new_right[color] = amount % 2;
	// 	if (amount % 2 == 1) right_socks++;
	// 	cost += amount / 2;
	// }

	// cost += abs(left_socks - right_socks) / 2;
	// cost += (left_socks + right_socks) / 2;
	// cout << cost << endl;


}


int main() {
	IOS;


	ll t;
	cin >> t;
	while (t--) solve();

}
