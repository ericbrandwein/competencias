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

int highest_bit(unsigned int n) {
	return n ? 32 - __builtin_clz(n) : -1;
}


ll min_moves_for(vec<ll>& nums, ll pos) {
	ll n = nums.size();
	vec<pair<ll,ll>> rights; // value, moves
	ll curr = 0;
	ll moves = 0;
	for (ll i = pos + 1; i < n; i++) {
		curr = curr ^ nums[i];
		rights.push_back({curr, moves});
		moves++;
	}

	sort(all(rights));
	vec<ll> min_moves(rights.size());
	ll curr_min = LONG_LONG_MAX;
	for (ll i = 0; i < rights.size(); i++) {
		curr_min = min(curr_min, rights[i].second);
		min_moves[i] = curr_min;
	}

	vec<ll> right_values(rights.size());
	for (ll i = 0; i < rights.size(); i++) {
		right_values[i] = rights[i].first;
	}

	ll res = LONG_LONG_MAX;
	ll curr_left = 0;
	moves = 0;
	for (ll i = pos; i >= 0; i--) {
		curr_left = curr_left ^ nums[i];
		auto primero_mayor_igual = lower_bound(
			right_values.begin(), right_values.end(), curr_left
		);
		if (primero_mayor_igual != right_values.begin()) {
			auto ultimo_menor = primero_mayor_igual-1;
			ll pos_ultimo_menor = ultimo_menor - right_values.begin();
			res = min(res, min_moves[pos_ultimo_menor] + moves);
		}
		moves++;
	}

	return res;

}

int main() {
	IOS;

	ll n;
	cin >> n;
	vec<ll> a(n);
	forn (i) cin >> a[i];

	vec<ll> highest_bits(n);
	for (ll i = 0; i < n; i++) {
		highest_bits[i] = highest_bit(a[i]);
	}

	for (ll i = 0; i <= n - 3; i++) {
		if (
			highest_bits[i] == highest_bits[i+1] &&
			highest_bits[i+1] == highest_bits[i+2] &&
			highest_bits[i] != -1
		) {
			cout << 1 << endl;
			return 0;
		}
	}

	ll min_moves = LONG_LONG_MAX;
	for (ll i = 0; i < n -1 ; i++) {
		if (highest_bits[i] == highest_bits[i+1]) {
			min_moves = min(min_moves, min_moves_for(a, i));
			if (i > 0) {
				min_moves = min(min_moves, min_moves_for(a, i-1));
			}
		}
	}

	if (min_moves == LONG_LONG_MAX) {
		cout << -1 << endl;
	} else {
		cout << min_moves << endl;
	}


}
