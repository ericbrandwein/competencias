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
	vec<ll> a(n);
	vec<ll> amounts(n+1, 0);
	forn (i) {
		cin >> a[i];
		amounts[a[i]]++;
	}
	ll biggest_2 = 0;
	fore (i, 1, n) {
		if (amounts[i] > 2 || (i > 1 && amounts[i-1] < amounts[i])) {
			cout << 0 << endl;
			return;
		}
		if (amounts[i] == 2) {
			biggest_2 = i;
		}
	}

	if (biggest_2 == 0) {
		cout << 0 << endl;
		return;
	}
	set<ll> nums;
	vec<ll> res;
	fore (i, 0, n-1) {
		if (nums.count(a[i]) > 0) {
			break;
		}
		nums.insert(a[i]);
		ll biggest = *(--nums.end());
		if (biggest == nums.size() && biggest >= biggest_2 &&
			(amounts[biggest] == 2 || biggest == n || amounts[biggest + 1] == 0)) {
			res.push_back(i);
		}
	}

	cout << res.size() << endl;
	for (ll num : res) {
		cout << num + 1 << " " << n - num -1 << endl;
	}
 }


int main() {
	IOS;


	ll t;
	cin >> t;
	while (t--) solve();

}
