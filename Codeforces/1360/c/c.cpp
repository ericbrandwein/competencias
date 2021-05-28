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


void solve(ll n, vector<ll>& nums) {
	sort(nums.begin(), nums.end());

	ll evens = 0;

	for (ll i = 0; i < n; i++) {
		if (nums[i] % 2 == 0) {
			evens++;
		}
	}

	if (evens % 2 == 0) {
		cout << "YES" << endl;
	} else {
		for (ll i = 0; i < n - 1; i++) {
			if (nums[i + 1] - nums[i] == 1) {
				cout << "YES" << endl;
				return;
			}
		}
		cout << "NO" << endl;
	}

}


int main() {
	IOS;

	ll t;
	cin >> t;

	for (ll i = 0; i < t; i++) {
		ll n;
		cin >> n;
		vector<ll> nums(n);
		forn (j) {
			cin >> nums[j];
		}
		solve(n, nums);
	}

	return 0;
}
