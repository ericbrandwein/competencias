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
	vector<ll> a(n);

	map<ll, ll> nums_ocurr;
	forn (i) {
		cin >> a[i];
		nums_ocurr[a[i]]++;
	}

	vector<ll> nums;
	for (pair<ll, ll> ocurr : nums_ocurr) {
		nums.push_back(ocurr->first);
	}

	map<ll, ll> pos_in_order;
	for (ll i = 0; i < nums.size(); i++) {
		pos_in_order[nums[i]] = i;
	}

	forn (i) {
		a[i] = pos_in_order[a[i]];
	}

	vector<ll> smaller(nums.size());
	ll curr = 0;
	for (pair<ll, ll> num : nums_ocurr) {
		smaller[pos_in_order[num.first]] = curr;
		ll amount = num.second;
		curr += amount;
	}

	vec<ll> biggest_smaller_after(n, -1);
	set<ll> nums_after;
	nums_after.insert(a[n-1]);
	for (ll i = n - 2; i >= 0; i--) {
		// it = el primero mayor o igual
		auto it = nums_after.lower_bound(a[i]);
		if (it != nums_after.begin()) {
			it--;
			biggest_smaller_after[i] = *it;
		}

		nums_after.insert(a[i]);
	}

	vector<pair<ll,ll>> sorted_by_smaller_after;
	for (ll i = 0; i < biggest_smaller_after.size(); i++) {
		sorted_by_smaller_after.push_back({biggest_smaller_after[i], pos_in_order[a[i]]});
	}
	sort(all(sorted_by_smaller_after));


	auto it = nums.end();
	it--;
	ll num_to_right = it->first;
	auto it = sorted_by_smaller_after.end();
	it--;

	ll min_moves = LONG_LONG_MAX;
	auto it_to_left = nums.end();
	while (it_to_left != nums.begin()) {
		it_to_left--;
		ll num_to_left = it_to_left->first;

		while (it != sorted_by_smaller_after.begin()) {

			auto before = it;
			before--;
			if (before->)
		}
	}
	for (ll i = nums.size() - 1; i >= 0; i--) {


		ll max_left = nums[i];
		ll min_right = LONG_LONG_MAX;
		for (ll j = 0; j < a.size(); j++) {
			if (biggest_smaller_after[j] > max_left) {
				min_right = min(min_right, a[j]);
			}
		}

		ll moves_right = 0;
		if (min_right != LONG_LONG_MAX) {
			moves_right = nums.size() - order_pos[min_right];
		}

		min_moves = min(min_moves, i + moves_right);
	}

cout << min_moves << endl;

}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
