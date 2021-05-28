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

int main() {
	IOS;

	ll n;
	cin >> n;
	vec<string> nombres(n);
	vec<ll> porcentajes(n);
	forn (i) {
		cin >> nombres[i];
		cin >> porcentajes[i];
		porcentajes[i] *= 100;
	}

	vec<ll> ordenados = porcentajes;
	sort(all(ordenados));

	ll total = 10000;
	ll max_restado = 50;
	ll max_sumado = 49;
	ll suma = 0;
	for (ll i = 0; i < n-1;i++) {
		suma += ordenados[i] + max_sumado;
		if (ordenados[i] == 10000) {
			suma -= max_sumado;
		}
	}
	ll max_porcentaje_0 = min(total, ordenados[n-1] + max_sumado);

	if (suma + max_porcentaje_0 < total) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	ll queda = total - suma;
	ll restado = ordenados[n-1] - queda;
	max_restado = min(max_restado, restado);

	suma = 0;
	for (ll i = 1; i < n;i++) {
		suma += ordenados[i] - max_restado;
		if (ordenados[i] == 0) {
			suma += max_restado;
		}
	}
	ll min_porcentaje_0 = max(0LL, ordenados[0] - max_restado);
	if (suma + min_porcentaje_0 > total) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	queda = total - suma;
	ll sumado = queda - ordenados[0];
	max_sumado = min(max_sumado, sumado);

	presicion(2);
	for (ll i = 0; i < n; i++) {
		ll min_porcentaje = max(0LL, porcentajes[i] - max_restado);
		ll max_porcentaje = min(total, porcentajes[i] + max_sumado);
		cout << nombres[i] << " " << min_porcentaje / (long double)100 << " " << max_porcentaje / (long double)100 << endl;
	}

}
