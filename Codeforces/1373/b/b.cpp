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
	bool could_remove = true;
	ll turns = 0;
	while (could_remove) {
		could_remove = false;
		string new_s = "";
		fore (i, 0, s.size()) {
			if (i < (ll) s.size() - 1 && s[i] != s[i + 1]) {
				i = i + 1;
				could_remove = true;
				turns++;
			} else {
				new_s.push_back(s[i]);
			}
		}
		s = new_s;
	}

	cout << (turns % 2 == 0 ? "NET" : "DA") << endl;
}

int main() {
	IOS;

	ll t;
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}
