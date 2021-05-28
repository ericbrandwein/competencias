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

void marcar_anagrama(
	pair<ll,ll>& dir, ll from_fila, ll from_col, ll cant, vec<vec<set<ll>>>& anagramas,
	ll num_palabra
) {
	for (ll i = 0; i < cant; i++) {
		anagramas[from_fila][from_col].insert(num_palabra);
		from_fila -= dir.first;
		from_col -= dir.second;
	}
}

void llenar_anagramas(
	vec<string>& filas, vec<multiset<char>>& bolsas, ll fila, ll col,
	vec<vec<set<ll>>>& anagramas
) {
	ll f = filas.size();
	ll c = filas[0].size();
	vec<pair<ll,ll>> dirs = {{1,0}, {1,1}, {0,1}, {-1,0}, {-1,-1}, {0,-1}, {-1,1}, {1,-1}};
	for (pair<ll,ll> dir : dirs) {
		multiset<char> bolsa_actual;
		ll fila_actual = fila;
		ll col_actual = col;
		while (
			fila_actual >= 0 && fila_actual < f && col_actual >= 0 && col_actual < c && bolsa_actual.size() < 15
		) {

			bolsa_actual.insert(filas[fila_actual][col_actual]);
			for (ll i = 0; i < bolsas.size(); i++) {
				if (bolsas[i] == bolsa_actual) {
					marcar_anagrama(
						dir, fila_actual, col_actual, bolsa_actual.size(), anagramas, i
					);
				}
			}

			fila_actual += dir.first;
			col_actual += dir.second;
		}
	}
}
int main() {
	IOS;

	ll l, c;
	cin >> l >> c;
	vec<string> filas(l);
	fore (i, 0, l) cin >> filas[i];
	ll n;
	cin >> n;

	vec<string> p(n);
	vec<multiset<char>> bolsas(n);
	forn (i) {
		cin >> p[i];
		for(char caracter : p[i]) {
			bolsas[i].insert(caracter);
		}
	}

	vec<vec<set<ll>>> anagramas(l, vec<set<ll>>(c));
	for (ll fila = 0; fila < l; fila++) {
		for (ll col = 0 ; col < c; col++) {
			llenar_anagramas(filas, bolsas, fila, col, anagramas);
		}
	}

	ll res = 0;
	for (ll fila = 0; fila < l; fila++) {
		for (ll col = 0; col < c; col++) {
			if (anagramas[fila][col].size() > 1) res++;
		}
	}

	cout << res << endl;


	return 0;
}
