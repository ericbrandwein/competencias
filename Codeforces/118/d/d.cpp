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

#define MOD 100000000
using namespace std;


int main() {
	IOS;

	vector<ll> ns(2);
	fore (i, 0, 2) {
		cin >> ns[i];
	}

	vector<ll> max_seguidos(2);
	fore (i, 0, 2) {
		cin >> max_seguidos[i];
	}

	ll largo = ns[0] + ns[1];

	// posib_con_seguidos[tipo][seguidos][ns[tipo] usados en total]
	vector<vector<vector<ll>>> posib_con_seguidos(2);
	posib_con_seguidos[0] = vector<vector<ll>>(max_seguidos[0] + 1, vector<ll>(ns[0] + 1, 0));
	posib_con_seguidos[1] = vector<vector<ll>>(max_seguidos[1] + 1, vector<ll>(ns[1] + 1, 0));
	posib_con_seguidos[0][1][1] = 1;
	posib_con_seguidos[1][1][1] = 1;
	fore (largo_actual, 2, largo + 1) {
		vector<vector<vector<ll>>> nuevas_posib(2);
		nuevas_posib[0] = vector<vector<ll>>(max_seguidos[0] + 1, vector<ll>(ns[0] + 1, 0));
		nuevas_posib[1] = vector<vector<ll>>(max_seguidos[1] + 1, vector<ll>(ns[1] + 1, 0));
		for (ll tipo = 0; tipo < 2; tipo++) {
			ll otro_tipo = (tipo + 1) % 2;

			for (ll seguidos = 1; seguidos <= max_seguidos[otro_tipo]; seguidos++) {
				for (ll usados = 0; usados <= ns[otro_tipo]; usados++) {
					ll usados_tipo = largo_actual - usados;
					if (usados_tipo > 0 && usados_tipo <= ns[tipo]) {
						nuevas_posib[tipo][1][usados_tipo] +=
							posib_con_seguidos[otro_tipo][seguidos][usados];
						nuevas_posib[tipo][1][usados_tipo] %= MOD;
					}
				}
			}

			for (ll seguidos = 1; seguidos < max_seguidos[tipo]; seguidos++) {
				for (ll usados = 0; usados < ns[tipo]; usados++) {
					nuevas_posib[tipo][seguidos + 1][usados + 1] =
						posib_con_seguidos[tipo][seguidos][usados];
				}
			}
		}

		posib_con_seguidos = nuevas_posib;
	}

	ll total = 0;
	for (ll tipo = 0; tipo < 2; tipo++) {
		for (ll cant = 0; cant < max_seguidos[tipo] + 1; cant++) {
			for (ll usados = 0; usados <= ns[tipo]; usados++) {
				total += posib_con_seguidos[tipo][cant][usados];
				total %= MOD;
			}
		}
	}

	cout << total << endl;

	return 0;
}
