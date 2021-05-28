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
	ll n, first, salto;
	cin >> n >> first >> salto;

	vec<bool> plataformas(n, false);
	string plataformas_s;
	cin >> plataformas_s;
	forn (i) {
		plataformas[i] = plataformas_s[i] == '1';
	}

	ll costo_agregar, costo_sacar;
	cin >> costo_agregar >> costo_sacar;

	vec<ll> costos_agregar(n, 0);

	for (ll i = n - 1; i >= 0; i--) {
		if (i + salto < n) {
			costos_agregar[i] += costos_agregar[i + salto];
		}
		if (!plataformas[i]) {
			costos_agregar[i] += costo_agregar;
		}
	}

	ll min_costo = LONG_LONG_MAX;
	ll costo_sacados = 0;
	for (ll i = first-1; i < n; i++) {
		min_costo = min(min_costo, costo_sacados + costos_agregar[i]);
		costo_sacados += costo_sacar;
	}

	cout << min_costo << endl;

}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}
