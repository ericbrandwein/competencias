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

ll increase(string& prev, string& curr) {
	if (curr.size() > prev.size()) {
		return 0;
	}

	ll res = 0;
	ll curr_size = curr.size();
	for (ll i = 0; i < prev.size() - curr_size; i++) {
		curr.push_back('0');
		res++;
	}

	for (ll i = 0; i < curr_size; i++) {
		if (curr[i] < prev[i]) {
			curr.push_back('0');
			res++;
			return res;
		} else if (curr[i] > prev[i]) {
			return res;
		}
	}
	for (ll i = curr_size; i < prev.size(); i++) {
		curr[i] = prev[i];
	}

	for (ll i = prev.size() - 1; i >= curr_size; i--) {
		if (curr[i] == '9') {
			curr[i] = '0';
		} else {
			curr[i]++;
			return res;
		}
	}
	res++;
	curr.push_back('0');
	return res;

}


void solve() {
	ll n;
	cin >> n;
	vec<string> nums(n);
	forn (i) {
		cin >> nums[i];
	}

	ll total = 0;
	fore (i, 1, n) {
		total += increase(nums[i-1], nums[i]);
	}

	cout << total << endl;
}

int main() {
	IOS;

	ll t;
	cin >> t;
	fore (i, 0, t) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}

}
