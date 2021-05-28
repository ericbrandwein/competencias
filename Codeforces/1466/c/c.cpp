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
	ll n = s.size();
	// [pos][first_changed][second_changed]
	vec<vec<vec<ll>>> changes(n, vec<vec<ll>>(2, vec<ll>(2, 1000000)));
	changes[0][0][0] = 0;
	changes[0][0][1] = 0;
	changes[0][1][0] = 1;
	changes[0][1][1] = 1;
	for (ll i = 1; i < n; i++) {
		// not changing
		set<ll> firsts = {0, 1};
		if (s[i-1] == s[i]) firsts.erase(0);
		set<ll> seconds = {0,1 };
		if (i > 1 && s[i-2] == s[i]) {
			seconds.erase(0);
		}
		for (ll first : firsts) {
			for (ll second : seconds) {
				changes[i][0][first] = min(
					changes[i][0][first],
					changes[i-1][first][second]
				);
			}
		}
		changes[i][1][0] = min(changes[i-1][0][1], changes[i-1][0][0]) + 1;
		changes[i][1][1] = min(changes[i-1][1][0], changes[i-1][1][1]) + 1;
	}

	cout << min({
		changes[n - 1][0][0],
		changes[n - 1][1][0],
		changes[n - 1][0][1],
		changes[n - 1][1][1]
	}) << endl;
}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}
