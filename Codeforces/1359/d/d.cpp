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

int main() {
	IOS;

	ll n;
	cin >> n;

	vector<ll> nums(n);
	forn (i) {
		cin >> nums[i];
	}

	// first = removed
	// second = sum
	vector<pair<ll, ll>> bests_for_removed;
	ll best_sum = 0;

	for (ll num : nums) {
		pair<ll, ll> new_pair = {num, 0};
		while (!bests_for_removed.empty() && bests_for_removed.back().first <= num) {
			new_pair.second = max(new_pair.second, bests_for_removed.back().second);
			bests_for_removed.pop_back();
		}
		bests_for_removed.push_back(new_pair);
		fore (i, 0, bests_for_removed.size()) {
			bests_for_removed[i].second += num;
			best_sum = max(best_sum, bests_for_removed[i].second - bests_for_removed[i].first);
		}
	}

	cout << best_sum << endl;

	return 0;
}
