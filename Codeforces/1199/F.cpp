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

// ancho, alto, fila, columna
ll valores[51][51][50][50];
// fila, columna
ll sumas_parciales_filas[51][51];
ll sumas_parciales_cols[51][51];

bool tiene_negros_col(ll col, ll fila_start, ll fila_end) {
	return sumas_parciales_cols[fila_end][col] - sumas_parciales_cols[fila_start][col] > 0;
}

bool tiene_negros_fila(ll fila, ll col_start, ll col_end) {
	return sumas_parciales_filas[fila][col_end] - sumas_parciales_filas[fila][col_start] > 0;
}

ll calcular(ll ancho, ll alto, ll fila, ll col) {

	ll mejor = max(ancho, alto);
	if (ancho >= alto) {
		// Por cada columna no usada
		fore (col_no_usada, 0, ancho) {
			ll col_no_usada_tabla = col + col_no_usada;
			if (!tiene_negros_col(col_no_usada_tabla, fila, fila + alto)) {

				ll usado_izq = valores[col_no_usada][alto][fila][col];
				ll usado_der = valores[ancho - col_no_usada - 1][alto][fila][col_no_usada_tabla + 1];
				mejor = min(mejor, usado_der + usado_izq);
			}
		}
	} else {
		// Por cada fila no usada
		fore (fila_no_usada, 0, alto) {
			ll fila_no_usada_tabla = fila + fila_no_usada;
			if (!tiene_negros_fila(fila_no_usada_tabla, col, col + ancho)) {
				ll usado_arr = valores[ancho][fila_no_usada][fila][col];
				ll usado_ab = valores[ancho][alto - fila_no_usada - 1][fila_no_usada_tabla + 1][col];
				mejor = min(mejor, usado_ab + usado_arr);
			}
		}
	}

	return mejor;
}

int main() {
	IOS;
	
	ll n;
	cin >> n;
	

	forn (i) {
	    string row;
	    cin >> row;
	    forn (j) {
	        valores[1][1][i][j] = row[j] == '#';
			sumas_parciales_filas[i][j + 1] = 
				sumas_parciales_filas[i][j] + valores[1][1][i][j];
			sumas_parciales_cols[i + 1][j] = 
				sumas_parciales_cols[i][j] + valores[1][1][i][j];
	    }
	}
	

	// Por cada ancho
	fore (ancho, 1, n + 1) {
	    // Por cada alto
	    fore (alto, 1, n + 1) {
			if (ancho * alto > 1) { // Hay columnas que elegir
				// Por cada fila
				fore (fila, 0, n - alto + 1) {
					// Por cada columna
					fore (col, 0, n - ancho + 1) {
						valores[ancho][alto][fila][col] = 
							calcular(ancho, alto, fila, col);
					}
				}
			}
	    }
	}

	cout << valores[n][n][0][0] << endl;
	
	return 0;
}
