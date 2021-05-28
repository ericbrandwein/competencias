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

	vec<ll> cants(3);
	fore (i ,0, 3) {
		cin >> cants[i];
	}
	vec<vec<ll>> bolsas(3);
	vec<ll> sumas(3, 0);
	ll suma_total = 0;
	fore(i, 0, 3) {
		for (ll j = 0; j < cants[i]; j++) {
			ll num;;
			cin >> num;
			bolsas[i].push_back(num);
			sumas[i] += num;
		}
		sort(all(bolsas[i]));
		suma_total += sumas[i];
	}

	ll res = LONG_LONG_MIN;
	for (ll sumada = 0; sumada < 3; sumada++) {
		ll curr = suma_total;
		// O agarramos el mínimo de las dos bolsas que quedan, o restamos
		// una bolsa entera.
		ll restado = 0;
		for (ll i = 0; i < 3; i++) {
			if (i != sumada) {
				restado += 2*bolsas[i][0];
			}
		}
		for (ll i = 0; i < 3; i++) {
			if (i != sumada) {
				restado = min(restado, 2*sumas[i]);
			}
		}

		curr -= restado;
		res = max(res, curr);
	}

	cout << res << endl;



}
