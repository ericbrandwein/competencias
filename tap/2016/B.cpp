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

struct Pos {
	int x, y;
};

ld distancia(Pos& primera, Pos& segunda) {
	ll x_restado = (primera.x - segunda.x);
	ll y_restado = (primera.y - segunda.y);
	return sqrtl(x_restado * x_restado + y_restado * y_restado);
}

int main() {
	IOS;

	ll n, entrada, salida;
	cin >> n >> entrada >> salida;
	entrada--;
	salida--;
	if (salida < entrada) {
		ll temp = entrada;
		entrada = salida;
		salida = temp;
	}
	vector<Pos> posiciones(n);
	forn (i) {
		cin >> posiciones[i].x >> posiciones[i].y;
	}
	
	vector<Pos> derecha, izquierda;
	for (ll i = entrada + 1; i < salida; i++) {
		derecha.push_back(posiciones[i]);
	}

	for (ll i = (entrada - 1 + n) % n;
		i != salida;
		i--, i += n, i %= n) {
		izquierda.push_back(posiciones[i]);
	}

	Pos pos_entrada = posiciones[entrada];
	Pos pos_salida = posiciones[salida];

	// Minimo para llegar a izq pasando por der
	vector<vector<ld>> min_camino_izq(n, vector<ld>(n + 1, numeric_limits<ld>::infinity()));
	// Minimo para llegar a der pasando por izq
	vector<vector<ld>> min_camino_der(n, vector<ld>(n + 1, numeric_limits<ld>::infinity()));
	// min_camino[izq][der]

	if (izquierda.size() > 0) {
		min_camino_izq[0][0] = distancia(pos_entrada, izquierda[0]);
	}
	for (ll i = 1; i < izquierda.size(); i++) {
		min_camino_izq[i][0] = 
			min_camino_izq[i - 1][0] + distancia(izquierda[i - 1], izquierda[i]);
	}

	if (derecha.size() > 0) {
		min_camino_der[0][0] = distancia(pos_entrada, derecha[0]);
	}
	for (ll i = 1; i < derecha.size(); i++) {
		min_camino_der[i][0] = 
			min_camino_der[i - 1][0] + distancia(derecha[i - 1], derecha[i]);
	}

	for (ll i = 0; i < izquierda.size() || i < derecha.size(); i++) {
		// Agarramos i de la derecha y todos de la izq
		if (i < derecha.size()) {
			for (ll j = 1; j <= izquierda.size(); j++) {
				// min camino para llegar hasta el der i pasando por j izq
				if (i > 0) {
					min_camino_der[i][j] = 
						min_camino_der[i - 1][j] + distancia(derecha[i - 1], derecha[i]);
				}
				min_camino_der[i][j] = min(
					min_camino_der[i][j],
					min_camino_izq[j - 1][i] + distancia(izquierda[j - 1], derecha[i]));

			}
		}

		if (i < izquierda.size()) {
			for (ll j = 1; j <= derecha.size(); j++) {
				// min camino para llegar hasta el der i pasando por j izq
				if (i > 0) {
					min_camino_izq[i][j] = 
						min_camino_izq[i - 1][j] + distancia(izquierda[i - 1], izquierda[i]);
				}
				min_camino_izq[i][j] = min(
					min_camino_izq[i][j],
					min_camino_der[j - 1][i] + distancia(derecha[j - 1], izquierda[i]));
			}
		}
	}

	presicion(6);

	ld min_camino = numeric_limits<ld>::infinity();
	if (derecha.size() > 0) {
		min_camino = distancia(pos_salida, derecha[derecha.size() - 1]) +
			min_camino_der[derecha.size() - 1][izquierda.size()];
	}
	if (izquierda.size() > 0) {
		min_camino = min(
			min_camino,
			distancia(pos_salida, izquierda[izquierda.size() - 1]) +
				min_camino_izq[izquierda.size() - 1][derecha.size()]
		);
	}

	if (izquierda.size() == 0 && derecha.size() == 0) {
		cout << distancia(pos_entrada, pos_salida) << endl; 
		return 0;
	}

	cout << min_camino << endl;



	return 0;
}
