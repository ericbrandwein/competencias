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

ll pot(ll num) {
	return num * num * num * num;
}

int main() {
	IOS;

	ll n, m;
	cin >> n >> m;

	vec<vec<ll>> a(n, vec<ll>(m));
	for (ll i = 0; i < n ; i++) {
		fore (j, 0, m) {
			cin >> a[i][j];
		}
	}
	ll mult = 1;
	for (ll i = 1; i <= 16;i++) {
		mult = lcm(mult, i);
	}
	vec<vec<ll>> res(n, vec<ll>(m, mult));
	for (ll diag = 1; diag < n + m; diag+=2) {
		for (ll fila = 0; fila < n; fila++) {
			ll col = diag - fila;
			if (col >= 0 && col < m) {
				res[fila][col] += pot(a[fila][col]);
			}
		}
	}

	forn (i) {
		fore (j, 0, m) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

}
