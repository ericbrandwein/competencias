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
	vec<pair<ll,ll>> filas(n);
	forn (i) {
		cin >> filas[i].first >> filas[i].second;
	}

	multiset<ll> comienzos, finales;
	ll max_cuadrado = 0;
	forn (i) {
		comienzos.insert(filas[i].first);
		finales.insert(filas[i].second);
		ll comienzo = *(--comienzos.end());
		ll final = *finales.begin();
		ll longitud = final - comienzo + 1;
		while (longitud < comienzos.size()) {
			ll primero = i - comienzos.size() + 1;
			comienzos.erase(comienzos.find(filas[primero].first));
			finales.erase(finales.find(filas[primero].second));

			comienzo = *(--comienzos.end());
			final = *finales.begin();
			longitud = final - comienzo + 1;
		}
		max_cuadrado = max(max_cuadrado, (ll)comienzos.size());
	}

	cout << max_cuadrado << endl;


	return 0;
}
