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
	string s;
	cin >> s;
	ll jump;
	cin >> jump;

	string res(s.size(), '1');
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			if (i - jump >= 0) {
				res[i-jump] = '0';
			}
			if (i+jump < s.size()) {
				res[i+jump] = '0';
			}
		}
	}

	for (ll i = 0; i < s.size(); i++) {
		if (s[i] == '1') {
			bool possible = false;
			if (i - jump >= 0) {
				possible |= res[i-jump] == '1';
			}
			if (i+jump < s.size()) {
				possible |= res[i+jump] == '1';
			}
			if (!possible) {
				cout << -1 << endl;
				return;
			}
		}
	}

	cout << res << endl;
}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
