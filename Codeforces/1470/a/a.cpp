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
	ll n, m;
	cin >> n >> m;
	vec<ll> friends(n), presents(m);
	forn (i) {
		cin >> friends[i];
		friends[i]--;
	}
	fore (i, 0, m) cin >> presents[i];
	sort(all(friends));
	ll total = 0;
	forn (i) {
		total += presents[friends[i]];
	}

	ll min_total = total;
	ll max_offset = LONG_LONG_MAX;
	fore (i, 0, m) {
		if (i > n - 1) break;
		total += presents[i];
		total -= presents[friends[n - i - 1]];
		min_total = min(min_total, total);
		max_offset--;
		max_offset = min(max_offset, friends[n - i - 1]);
		if (max_offset == 0) {
			break;
		}

	}

	cout << min_total << endl;








}


int main() {
	IOS;
	ll t;
	cin >> t;
	while (t--) solve();
}
