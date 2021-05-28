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
	ll n, friends;
	cin >> n >> friends;

	vector<ll> nums(n);
	forn (i) cin >> nums[i];

	vector<ll> space(friends);
	fore (i, 0, friends) {
		cin >> space[i];
	}

	sort(nums.begin(), nums.end());
	sort(space.rbegin(), space.rend());

	ll sum = 0;
	ll biggest = n - friends;
	ll smallest = 0;
	fore (i, 0, friends) {
		ll curr_space = space[i];
		sum += nums[biggest];
		curr_space--;
		if (curr_space > 0) {
			sum += nums[smallest];
			smallest += curr_space;
		} else {
			sum += nums[biggest];
		}
		biggest++;
	}

	cout << sum << endl;

}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
