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

	fore (i, 0, t) {
		string digits;
		cin >> digits;
		ll count = 0;
		vector<ll> ones;
		for (ll j = 0; j < digits.size(); j++) {
			if (digits[j] == '1') {
				ones.push_back(j);
				count++;
			}
		}

		for (ll j = 0; j < ones.size(); j++) {
			if (j >= ones.size()) {
				cout << "ERROR" << endl;
				return 0;
			}
			ll curr_i = ones[j];
			ll curr_num = 1;
			ll zeroes = curr_i;
			if (j != 0) {
				zeroes = curr_i - ones[j - 1] - 1;
			}
			for (ll k = curr_i + 1; k < digits.size(); k++) {
				curr_num *= 2;
				if (digits[k] == '1') {
					curr_num++;
				}
				ll num_dig = k - curr_i + 1 + zeroes;
				if (num_dig >= curr_num) {
					count++;
				} else {
					break;
				}
			}
		}

		cout << count << endl;
	}

	return 0;
}


