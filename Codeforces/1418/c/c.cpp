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
	ll n;
	cin >> n;
	vec<ll> types(n);
	forn (i) cin >> types[i];

	// 0: amigo, 1: yo
	vec<vec<ll>> min_skip(n + 1, vec<ll>(2));
	min_skip[0][0] = 0;
	min_skip[0][1] = 0;
	min_skip[1][1] = 1000000;
	min_skip[1][0] = types[0];
	fore (i, 2, n + 1) {
		min_skip[i][1] = min_skip[i-1][0];
		min_skip[i][0] = types[i - 1] + min(
			min_skip[i-1][1],
			types[i-2] + min_skip[i-2][1]
		);
		if (i > 2) {
			min_skip[i][1] = min(
				min_skip[i][1],
				min_skip[i-2][0]
			);
		}
	}

	cout << min(min_skip[n][0], min_skip[n][1]) << endl;
}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
