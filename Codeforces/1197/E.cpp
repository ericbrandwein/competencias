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

#define MOD 1000000007

struct Matrioshka {
	ll in, out;

	bool operator<(const Matrioshka& other) const {
		return out < other.out;
	}
};

int main() {
	IOS;

	ll n;
	cin >> n;

	vector<Matrioshka> dolls;
	forn (i) {
		Matrioshka doll;
		cin >> doll.out >> doll.in;
		dolls.push_back(doll);
	}

	sort(all(dolls));

	vector<ll> outs;
	outs.push_back(dolls[0].out);
	fore (i, 1, n) {
		if (outs[outs.size() - 1] != dolls[i].out) {
			outs.push_back(dolls[i].out);
		}
	}

	// Ahora tenemos que ver quiénes son los más grandes.
	ll max_in = 0;
	forn (i) {
		max_in = max(max_in, dolls[i].in);
	}
	ll indice_primero_mas_grande = 0;
	for (; 
		indice_primero_mas_grande < dolls.size() &&
		dolls[indice_primero_mas_grande].out <= max_in; 
		indice_primero_mas_grande++);


	vector<ll> mejor_espacio(outs.size(), LONG_LONG_MAX);
	vector<ll> cant_con_mejor(outs.size(), 0);
	ll indice_out_actual = 0;

	forn (i) {
		Matrioshka& doll = dolls[i];
		bool nuevo_out = false;
		if (doll.out != outs[indice_out_actual]) {
			indice_out_actual++;
			nuevo_out = true;
		}

		ll mejor_con_actual = doll.in;
		ll cantidad_con_actual = 1;

		if (indice_out_actual > 0) {
			auto it_best_fit = upper_bound(all(outs), doll.in);
			if (it_best_fit != outs.begin()) {
				it_best_fit--;
				ll sobrante = doll.in - *it_best_fit;
				ll index_best_fit = it_best_fit - outs.begin();
				mejor_con_actual = mejor_espacio[index_best_fit] + sobrante;
				cantidad_con_actual = cant_con_mejor[index_best_fit];
			}

			// Tenemos que ver si sumar al anterior solo si somos los primeros
			// con este out, y si no somos de los más grandes
			if (nuevo_out && i < indice_primero_mas_grande) {
				ll mejor_hasta_ahora = mejor_espacio[indice_out_actual - 1];
				ll diferencia_de_outs = doll.out - outs[indice_out_actual - 1];
				ll mejor_con_anterior = mejor_hasta_ahora + diferencia_de_outs;
				ll cantidad_con_anterior = cant_con_mejor[indice_out_actual - 1];

				if (mejor_con_anterior < mejor_con_actual) {
					mejor_con_actual = mejor_con_anterior;
					cantidad_con_actual = cantidad_con_anterior;
				} else if (mejor_con_actual == mejor_con_anterior) {
					cantidad_con_actual = 
						(cantidad_con_actual + cantidad_con_anterior) % MOD;
				}
			}
		}

		// actualizamos mejor_espacio y cant_con_mejor
		if (mejor_con_actual < mejor_espacio[indice_out_actual]) {
			mejor_espacio[indice_out_actual] = mejor_con_actual;
			cant_con_mejor[indice_out_actual] = cantidad_con_actual;
		} else if (mejor_con_actual == mejor_espacio[indice_out_actual]) {
			cant_con_mejor[indice_out_actual] = 
				(cant_con_mejor[indice_out_actual] + cantidad_con_actual) % MOD;
		}
	}


	// Buscamos el mejor entre los que son más grandes
	ll out_primero_mas_grande = dolls[indice_primero_mas_grande].out;
	auto it_mas_grande = lower_bound(all(outs), out_primero_mas_grande);
	ll indice_mas_grande = it_mas_grande - outs.begin();
	ll minimo = LONG_LONG_MAX;
	ll cant_min = 0;
	for (; indice_mas_grande < outs.size(); indice_mas_grande++) {
		if (mejor_espacio[indice_mas_grande] < minimo) {
			minimo = mejor_espacio[indice_mas_grande];
			cant_min = cant_con_mejor[indice_mas_grande];
		} else if (mejor_espacio[indice_mas_grande] == minimo) {
			cant_min = (cant_min + cant_con_mejor[indice_mas_grande]) % MOD;
		}
	}

	cout << cant_min << endl;

	return 0;
} 
