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

ll dp(vec<vec<vec<ll>>>& max_using, vec<ll> pos, vec<vec<ll>>& nums) {
	ll& curr = max_using[pos[0]][pos[1]][pos[2]];
	if (curr != -1) {
		return curr;
	}

	curr = 0;
	for (ll i = 0; i < 3; i++) {
		ll next = (i + 1) % 3;
		if (pos[i] < nums[i].size() && pos[next] < nums[next].size()) {
			ll total = nums[i][pos[i]] * nums[(i + 1) % 3][pos[(i + 1) % 3]];
			vec<ll> new_pos = pos;
			new_pos[i]++;
			new_pos[next]++;
			total += dp(max_using, new_pos, nums);
			curr = max(curr, total);
		}
	}

	return curr;
}

int main() {
	IOS;


	vec<ll> cant(3);
	for (ll i = 0; i < 3; i++) {
		cin >> cant[i];
	}

	vec<vec<ll>> nums(3);
	for (ll i = 0; i < 3; i++) {
		nums[i].resize(cant[i]);
		for (ll j = 0; j < cant[i]; j++) {
			cin >> nums[i][j];
		}
		sort(nums[i].rbegin(), nums[i].rend());
	}



	vec<vec<vec<ll>>> max_using(cant[0] + 1, vec<vec<ll>>(cant[1] + 1, vec<ll>(cant[2] + 1, -1)));

	cout << dp(max_using, {0, 0, 0}, nums) << endl;



	return 0;
}
