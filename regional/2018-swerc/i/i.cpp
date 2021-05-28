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

bool is_noise(vec<string>& filas, ll fila, ll col) {
	bool noise = filas[fila][col] == '#';
	for (ll curr_fila = fila - 1; curr_fila <= fila + 1; curr_fila++) {
		for (ll curr_col = col - 1; curr_col <= col + 1; curr_col++) {
			if (curr_fila == fila && curr_col == col) continue;
			noise &= filas[curr_fila][curr_col] == '.';
		}
	}
	return noise;
}

void eliminar_borde(vec<string>& filas) {
	stack<pair<ll,ll>> next;
	next.push({0,0});
	filas[0][0] = '.';
	while (!next.empty()) {
		pair<ll,ll> curr = next.top();
		next.pop();
		ll fila = curr.first;
		ll col = curr.second;
		for (ll curr_fila = fila - 1; curr_fila <= fila + 1; curr_fila++) {
			for (ll curr_col = col - 1; curr_col <= col + 1; curr_col++) {
				if (curr_fila == fila && curr_col == col) continue;
				if (
					curr_fila < 0 || curr_col < 0 ||
					curr_fila >= filas.size() || curr_col >= filas[0].size()
				) {
					continue;
				}
				if (filas[curr_fila][curr_col] == '#') {
					filas[curr_fila][curr_col] = '.';
					next.push({curr_fila, curr_col});
				}
			}
		}
	}
}

ll get_borde_col(vec<string>& filas, ll fila, ll col) {
	ll borde = col;
	for (; filas[fila][borde] == '#'; borde++);
	return borde;
}

ll get_borde_fila(vec<string>& filas, ll fila, ll col) {
	ll borde = fila;
	for (; filas[borde][col] == '#'; borde++);
	return borde;
}

void limpiar(vec<string>& filas, ll fila, ll col, ll ult_fila, ll ult_col) {
	for (ll curr_fila = fila; curr_fila < ult_fila; curr_fila++) {
		for (ll curr_col = col; curr_col < ult_col; curr_col++) {
			filas[curr_fila][curr_col] = '.';
		}
	}
}


bool is_a(vec<string>& filas, ll fila, ll col) {
	ll borde_col = get_borde_col(filas, fila, col);
	// borde = primer col sin negro
	ll borde_fila = get_borde_fila(filas, fila, col);

	ll ancho_abajo = get_borde_col(filas, borde_fila - 1, col);
	bool a = ancho_abajo != borde_col;
	if (a) {
		limpiar(filas, fila, col, borde_fila, borde_col);
	}
	return a;
}

bool is_b(vec<string>& filas, ll fila, ll col) {
	ll borde_col = get_borde_col(filas, fila, col);
	// borde = primer col sin negro
	ll borde_fila = get_borde_fila(filas, fila, col);

	ll alto_der = get_borde_fila(filas, fila, borde_col - 1);
	bool b = borde_fila == alto_der;
	if (b) {
		limpiar(filas, fila, col, borde_fila, borde_col);
	}
	return b;
}


bool is_c(vec<string>& filas, ll fila, ll col) {
	ll borde_col = get_borde_col(filas, fila, col);
	// borde = primer col sin negro
	ll borde_fila = get_borde_fila(filas, fila, col);
	limpiar(filas, fila, col, borde_fila, borde_col);
	return true;
}

int main() {
	IOS;

	ll w, h;
	cin >> w >> h;

	vec<string> filas(h);
	fore (i, 0, h) cin >> filas[i];

	fore (fila,2, h-2) {
		fore (col, 2, w-2) {
			if (is_noise(filas, fila, col)) {
				filas[fila][col] = '.';
			}
		}
	}

	eliminar_borde(filas);
	ll a = 0, b = 0, c = 0;

	for (ll fila = 0; fila < h; fila++) {
		for (ll col = 0; col < w; col++) {
			if (filas[fila][col] == '.') continue;
			if (is_a(filas, fila, col)) a++;
			else if (is_b(filas, fila, col)) b++;
			else if (is_c(filas, fila, col)) c++;
		}
	}

	cout << a << " " << b << " " << c << endl;


	return 0;
}
