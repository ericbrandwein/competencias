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

ll cant_combis_mayores_a(ll suma_max, vec<ll>& pesos, ll k, ll mayor_disponible, vec<vec<ll>>& combinatorios) {
	if (k == 0) return 0;
	ll i_peso_max = mayor_disponible;
	while (i_peso_max >= 0 && pesos[i_peso_max] > suma_max) {
		i_peso_max--;
	}
	ll primero_mayor = i_peso_max + 1;
	ll res = 0;
	for (ll i = primero_mayor; i <= mayor_disponible; i++) {
		res += combinatorios[i][k-1];
	}

	if (i_peso_max >= 0) {
		res += cant_combis_mayores_a(suma_max - pesos[i_peso_max], pesos, k-1, i_peso_max - 1, combinatorios);
	}
	return res;
}



vec<vec<ll>> get_combinatorios(ll n) {
	vec<vec<ll>> combinatorios(n+1, vec<ll>(n+1, 0));
	for (ll i = 0; i <= n; i++) {
		combinatorios[i][i]= 1;
		combinatorios[i][0]= 1;
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j < i;j++) {
			combinatorios[i][j] = combinatorios[i-1][j-1] + combinatorios[i-1][j];
		}
	}
	return combinatorios;
}

int main() {
	IOS;

	ll n;
	cin >> n;
	ll k;
	cin >> k;

	if (k > n) {
		cout << 0 << endl;
		return 0;
	}

	vec<vec<ll>> combinatorios = get_combinatorios(n);


	vec<ll> pesos(n);
	forn (i) cin >> pesos[i];
	sort(all(pesos));
	ll a, b;
	cin >> a >> b;

	ll combis_totales = combinatorios[n][k];
	ll combis_mayores = cant_combis_mayores_a(b, pesos, k, n-1, combinatorios);
	ll combis_menores = combis_totales - cant_combis_mayores_a(a-1, pesos, k, n-1, combinatorios);


	ll res = combis_totales - combis_mayores - combis_menores;

	cout << res << endl;

	return 0;
}
