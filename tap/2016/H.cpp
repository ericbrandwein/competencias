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

double dp[1000][1000];

int main() {
	IOS;
	ll n, x, y;
	cin >> n >> x >> y;

	forn(i)
		dp[0][i] = 1;

	for (ll i = 1; i < n; i++) {
		const ll participantes = n - i + 1;
		forn(j) {
			double ganar = 0;
			for (ll e = j + 1; e < n; e++)
				ganar += dp[i - 1][e] / (participantes - 1);

			dp[i][j] = (participantes - 2.0L) / participantes
				+ 2.0L / participantes * ganar;
			dp[i][j] *= dp[i - 1][j];
		}
	}

	for (ll i = 0; i < n; i++, cout << endl)
	for (ll j = 0; j < n; j++)
		cout << dp[i][j] << ' ';
	return 0;
}
