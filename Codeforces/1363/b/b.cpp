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

	ll t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;

		vector<ll> ones(s.size());

		ones[0] = s[0] == '1' ? 1 : 0;
		for (ll i = 1; i < s.size(); i++) {
			ones[i] = ones[i - 1];
			if (s[i] == '1') {
				ones[i]++;
			}
		}


		ll total_ones = ones[s.size() - 1];

		// change everything to zeros
		ll min_operations = total_ones;
		for (ll i = 0; i < s.size(); i++) {
			ll left_changed_to_one = i - ones[i] + 1;
			ll right_changed_to_zero = total_ones - ones[i];
			min_operations = min(min_operations, left_changed_to_one + right_changed_to_zero);
			ll left_changed_to_zero = ones[i];
			ll right_changed_to_one = s.size() - i - 1 - (total_ones - ones[i]);
			min_operations = min(min_operations, left_changed_to_zero + right_changed_to_one);
		}


		cout << min_operations<< endl;
	}

	return 0;
}
