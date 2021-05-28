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

const ll MOD = 998244353;

ll combis(string& x, string& y) {
	vec<ll> repe_der(y.size(), y.size() - 1);
	for (ll i = y.size() - 2; i >= 0; i--) {
		repe_der[i] = repe_der[i+1];
		if (y[i] == y[i+1]) {
			repe_der[i] = i;
		}
	}

	vec<vec<ll>> combi_desde(x.size(), vec<ll>(y.size() + 1, 0));
	ll res = 0;
	for (ll i = x.size() - 1; i >= 0; i--) {
		for (ll j = 0; j < y.size() + 1; j++) {
			ll der = 0;
			if (j < y.size() && y[j] != x[i]) {
				der = repe_der[j] - j + 1;
			}
			combi_desde[i][j] += der;
			combi_desde[i][j] %= MOD;
			res += der % MOD;
			res %= MOD;
		}

		if (j < y.size()) {
			combi_desde[i][j] += combi_desde[i][j+1];
		}


	}
}

int main() {
	IOS;

	string x, y;
	cin >> x >> y;

}
