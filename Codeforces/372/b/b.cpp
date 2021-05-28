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

ll rectangulos[40 + 1][40 + 1][40 + 1][40 + 1];
ll rectangulos_derecha[40 + 1][40 + 1][40 + 1][40 + 1];


ll rectangulos_merge_vertical(ll fila0, ll fila1, ll col) {
	ll primer_negro = fila1;
	while (primer_negro >= fila0 &&
			rectangulos[primer_negro][primer_negro][col][col] == 1) {
		primer_negro--;
	}

	ll cant_blancos = fila1 - primer_negro;
	return cant_blancos;
}

ll rectangulos_merge(ll fila0, ll fila1, ll col0, ll col1) {
	ll total = 0;
	ll primer_blanco = -1;
	for (ll i = fila0; i <= fila1; i++) {
		if (rectangulos[i][i][col1][col1] == 1) {
			if (primer_blanco == -1) {
				primer_blanco = i;
			}
		} else if (primer_blanco != -1) {
			ll ultimo_blanco = i - 1;
			total += rectangulos_derecha[primer_blanco][ultimo_blanco][col0][col1 - 1];
			primer_blanco = -1;
		}
	}
	if (primer_blanco != -1) {
		ll ultimo_blanco = fila1;
		total += rectangulos_derecha[primer_blanco][ultimo_blanco][col0][col1 - 1];
	}

	return total;
}


void calcular_rectangulos(ll fila0, ll fila1, ll col0, ll col1) {
	ll nuevos_rectangulos = 0;
	if (col1 > col0) {
		// Sumo los de la izquierda
		nuevos_rectangulos = rectangulos[fila0][fila1][col0][col1 - 1];
		// Sumo los de la vertical
		ll vertical = rectangulos[fila0][fila1][col1][col1];
		// Sumo el merge
		ll merge = rectangulos_merge(fila0, fila1, col0, col1);
		nuevos_rectangulos += merge + vertical;
		rectangulos_derecha[fila0][fila1][col0][col1] = merge + vertical;
	} else {
		// Sumo los de la vertical anterior
		nuevos_rectangulos = rectangulos[fila0][fila1 - 1][col0][col1];
		// Sumo el merge
		nuevos_rectangulos += rectangulos_merge_vertical(fila0, fila1, col0);
		rectangulos_derecha[fila0][fila1][col0][col1] = nuevos_rectangulos;
	}

	rectangulos[fila0][fila1][col0][col1] = nuevos_rectangulos;
}

int main() {
	IOS;

	ll n, m, q;
	cin >> n >> m >> q;

	vector<string> grilla(n);
	forn (i) {
		cin >> grilla[i];
	}

	// [fila0][fila1][col0][col1]
	forn (i) {
		fore (j, 0, m) {
			if (grilla[i][j] == '0') {
				rectangulos[i][i][j][j] = 1;
			} else {
				rectangulos[i][i][j][j] = 0;
			}
			rectangulos_derecha[i][i][j][j] = rectangulos[i][i][j][j];
		}
	}

	fore (ancho, 0, m) {
		forn (fila0) {
			for (ll fila1 = fila0; fila1 < n; fila1++) {
				fore (col0, 0, m) {
					ll col1 = col0 + ancho;
					if (col1 < m && (fila0 != fila1 || col0 != col1)) {
						calcular_rectangulos(fila0, fila1, col0, col0 + ancho);
					}
				}
			}
		}
	}


	fore (i, 0, q) {
		ll fila0, col0, fila1, col1;
		cin >> fila0 >> col0 >> fila1 >> col1;
		fila0--;
		col0--;
		fila1--;
		col1--;
		cout << rectangulos[fila0][fila1][col0][col1] << endl;
	}



	return 0;
}
