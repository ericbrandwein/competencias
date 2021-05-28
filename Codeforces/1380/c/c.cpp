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
	ll n, x;
	cin >> n >> x;

	vector<ll> skills(n);
	forn (i) {
		cin >> skills[i];
	}

	sort(skills.rbegin(), skills.rend());

	vector<ll> best_teams(n + 1, 0);
	fore (i, 1, n + 1) {
		ll skill_i = i - 1;
		ll back = x / skills[skill_i];
		if (x % skills[skill_i] != 0) back++;
		if (i - back >= 0) {
			best_teams[i] = best_teams[i - back] + 1;
		}
		best_teams[i] = max(best_teams[i], best_teams[i - 1]);
	}
	cout << best_teams[n] << endl;




}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
