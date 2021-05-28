// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
const ll MAXN = 500;


int combis_fila_db[2][MAXN + 1][MAXN + 1];
int combis_tablero_db[2][MAXN + 1][MAXN + 1];

int main() {
	IOS;

	ll n;
	cin >> n;
	ll k;
	cin >> k;

	if (k == 1) {
		cout << "0" << endl;
		return 0;
	}

	// ancho_max, ancho_act
	memset(combis_fila_db, 0, sizeof(combis_fila_db));

	combis_fila_db[1][1][1] = 1;
	for (ll pos = 1; pos < n; pos++) {
		for (ll ancho = 1; ancho < k && ancho <= n; ancho++) {
			int& combi_actual = combis_fila_db[(pos + 1) % 2][ancho][1];
			// Haber puesto uno del color contrario.
			for (ll ancho_ant = 1; ancho_ant < k && ancho_ant <= n; ancho_ant++) {
				combi_actual += combis_fila_db[pos%2][ancho][ancho_ant];
				combi_actual %= MOD;
			}

			// Poner uno del mismo color
			for (ll ancho_act = 2; ancho_act <= ancho; ancho_act++) {
				combis_fila_db[(pos + 1) % 2][ancho][ancho_act] =
					combis_fila_db[pos%2][ancho][ancho_act - 1];
				if (ancho == ancho_act) {
					combis_fila_db[(pos + 1) % 2][ancho][ancho_act] +=
						combis_fila_db[pos%2][ancho - 1][ancho_act - 1];
				}
				combis_fila_db[(pos + 1) % 2][ancho][ancho_act] %= MOD;
			}
		}
	}

	// ancho, alto
	memset(combis_tablero_db, 0, sizeof(combis_tablero_db));
	// Para la primera fila
	for (ll ancho = 1; ancho < min(k, n + 1);ancho++) {
		int& combis_act = combis_tablero_db[1][ancho][1];
		for (ll ancho_fin = 1; ancho_fin < min(k, n + 1); ancho_fin++) {
			combis_act += combis_fila_db[n % 2][ancho][ancho_fin];
			combis_act %= MOD;
		}
	}

	for (ll fila = 1; fila < n; fila++) {
		for (ll ancho = 1; ancho < min(k, n+1); ancho++) {
			// Doy vuelta la línea
			int& combis_act = combis_tablero_db[(fila+1)%2][ancho][1];
			for (ll alto = 1; alto < n + 1; alto++) {
				combis_act += combis_tablero_db[fila%2][ancho][alto-1];
				combis_act %= MOD;
			}

			// No doy vuelta la línea, agergo uno al alto
			for (ll alto = 2; alto < n + 1 && alto*ancho < k; alto++) {
				combis_tablero_db[(fila+1)%2][ancho][alto] =
					combis_tablero_db[fila%2][ancho][alto - 1];
			}
		}
	}

	int total = 0;
	for (ll ancho = 1; ancho < n + 1; ancho++) {
		for (ll alto = 1; alto < n + 1; alto++) {
			total += combis_tablero_db[n%2][ancho][alto];
			total %= MOD;
		}
	}


	cout << (total * 2) % MOD<< endl;

	cout << sizeof(combis_tablero_db) << endl;

	return 0;
}
