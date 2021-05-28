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

	ll k;
	cin >> k;
	while (k--) {
		ll n;
		cin >> n;

		string s, t;
		cin >> s >> t;

		vector<pair<int, int>> changes;
		for (ll i = 0; i < s.size() - 1; i++) {

			bool cambiado = false;
			for (ll j = i + 1; j < s.size() && !cambiado; j++) {
				if (s[j] == s[i]) {
					swap(s[j], t[i]);
					changes.push_back({j, i});
					cambiado = true;
				}
			}
			for (ll j = i; j < t.size() && !cambiado; j++) {
				if (t[j] == s[i]) {
					swap(s[i + 1], t[j]);
					changes.push_back({i + 1, j});
					swap(s[i + 1], t[i]);
					changes.push_back({i + 1, i});
					cambiado = true;
				}
			}
		}

		if (s == t) {
			cout << "Yes" << endl;
			cout << changes.size() << endl;
			for (ll i =0; i < changes.size();i++) {
				cout << changes[i].first + 1 << " " << changes[i].second + 1 << endl;
			}
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}
