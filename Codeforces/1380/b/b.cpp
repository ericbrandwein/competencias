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
		ll R = 0;
		ll P = 0;
		ll S = 0;

		for (char& c : s) {
			if (c == 'R') R++;
			if (c == 'P') P++;
			if (c == 'S') S++;
		}

		char best;
		if (R > P && R > S) {
			best = 'P';
		} else if (P> S) {
			best = 'S';
		} else {
			best = 'R';
		}

		fore (i, 0, s.size()) {
			cout << best;
		}
		cout << endl;
	}

	return 0;
}
