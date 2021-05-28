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

const ll MOD = 1000'000'000 + 7;
const ll MAX_N = 2*1e6;
vector<ll> max_pintadas(MAX_N + 1, 0);

void solve() {
	ll n;
	cin >> n;
	cout << max_pintadas[n] << endl;
}

void fill_pintadas() {
	// [0] = gastando el padre, [1] = sin gastarlo
	vector<vector<ll>> pintadas(MAX_N + 1, vector<ll>(2, 0));
	fore (i, 3, MAX_N + 1) {
		pintadas[i][0] = pintadas[i-1][1] + 2*pintadas[i-2][1] + 4;
		pintadas[i][0] %= MOD;
		pintadas[i][1] = max_pintadas[i-1] + 2*max_pintadas[i-2];
		pintadas[i][1] %= MOD;
		max_pintadas[i] = max(pintadas[i][0], pintadas[i][1]);
	}
}

int main() {
	IOS;

	ll t;
	cin >> t;
	fill_pintadas();
	while (t--) solve();

	return 0;
}
