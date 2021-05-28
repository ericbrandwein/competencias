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

	ll n = 14;
	vec<ll> nums(n);
	forn (i) cin >> nums[i];
	ll max_removed = 0;
	forn (i) {
		if (nums[i] > 0) {
			vec<ll> new_nums = nums;
			ll stones_added = nums[i] / 14;
			ll sobra = nums[i] % 14;
			for (ll j = 0; j < n;j++) {
				new_nums[j] += stones_added;
			}
			new_nums[i] -= nums[i];
			for (ll j = (i + 1) % n; sobra > 0; j++, j %= n) {
				new_nums[j]++;
				sobra--;
			}
			ll removed = 0;
			forn (spot) {
				if (new_nums[spot] % 2 == 0) {
					removed += new_nums[spot];
				}
			}
			max_removed = max(max_removed, removed);
		}
	}

	cout << max_removed << endl;


}
