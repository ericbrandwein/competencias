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
	ll n, cost;
	cin >> n >> cost;
	vec<ll> nums(n);
	forn (i) nums[i] = i + 1;

	cost -= n - 1;
	if (cost < 0) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}

	for (ll i = n - 2; i >= 0 && cost > 0; i--) {
		ll sacado = min(cost, n - i - 1);
		ll j = i + sacado;
		reverse(nums.begin() + i, nums.begin() + j + 1);
		cost -= sacado;
	}

	if (cost > 0) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		for (ll num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}
}


int main() {
	IOS;

	ll t;
	cin >> t;
	fore (i, 0, t) {
		cout << "Case #" << i + 1 << ": ";
		solve();
	}

}
