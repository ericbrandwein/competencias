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
	vec<ll> nums(3);
	ll total = 0;
	fore (i, 0, 3) {
		cin >> nums[i];
		if (nums[i] > 0) {
			total++;
			nums[i]--;
		}
	}

	sort(all(nums));
	if (nums[2] > 0 && nums[0] > 0) {
		nums[2]--;
		nums[0]--;
		total++;
	}
	if (nums[2] > 0 && nums[1] > 0) {
		nums[2]--;
		nums[1]--;
		total++;
	}
	if (nums[1] > 0 && nums[0] > 0) {
		nums[1]--;
		nums[0]--;
		total++;
	}
	if (*min_element(all(nums)) > 0) {
		total++;
	}

	cout << total << endl;

}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();


	return 0;
}
