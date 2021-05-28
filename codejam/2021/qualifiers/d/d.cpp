//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
// #define endl '\n'
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

int ask(ll i, ll j, ll k) {
	cout << i << " " << j <<  " " << k << endl;
	ll res;
	cin >> res;
	return res;
}

void solve(vec<ll>& res, ll first, ll second, ll from, ll to, vec<ll>& nums) {
	if (nums.empty()) {
		return;
	}
	if (nums.size() == 1) {
		res[from] = nums[0];
		return;
	}

	vec<ll> left, middle, right;
	for (ll i = 2; i < nums.size(); i++) {
		ll res = ask(first, second, nums[i]);
		if (res == nums[i]) {
			middle.push_back(nums[i]);
		} else if (res == first) {
			left.push_back(nums[i]);
		} else {
			right.push_back(nums[i]);
		}
	}

	ll new_first, new_second;
	if (left.size() > 1) {
		ll ans = ask(first, left[0], left[1]);
		if (ans == left[0]) {
			new_first = left[1];
			new_second = left[0];
		} else {
			new_first = left[0];
			new_second = left[1];
		}
	}
	solve(res, new_first, new_second, from, from + left.size(), left);

	if (middle.size() > 1) {
		ll ans = ask(first, middle[0], middle[1]);
		if (ans == middle[0]) {
			new_first = middle[0];
			new_second = middle[1];
		} else {
			new_first = middle[1];
			new_second = middle[0];
		}
	}
	ll start_mid = from + left.size() + 1;
	solve(res, new_first, new_second, start_mid, start_mid + middle.size(), middle);


	if (right.size() > 1) {
		ll ans = ask(first, right[0], right[1]);
		if (ans == right[0]) {
			new_first = right[0];
			new_second = right[1];
		} else {
			new_first = right[1];
			new_second = right[0];
		}
	}
	ll start_right = start_mid + middle.size() + 1;
	solve(res, new_first, new_second, start_right, to, right);

	res[start_mid - 1] = first;
	res[start_right - 1] = second;

}

void solve(ll n) {
	vec<ll> res(n);
	vec<ll> nums(n);
	for (ll i = 0; i < n; i++) nums[i] = i+1;
	solve(res, 1, 2, 0, n, nums);

	for (ll num : res) {
		cout << num << " ";
	}
	cout << endl;
	ll num;
	cin >> num;

}

int main() {
	IOS;

	ll t, n, q;
	cin >> t >> n >> q;

	while (t--) solve(n);

}
