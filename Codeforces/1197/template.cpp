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

#define MOD 1000000000 + 7

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

	vector<ll> mejor_espacio(n, LONG_LONG_MAX);
	vector<ll> cant_con_mejor(n, 0);
	vector<bool> usado(n, false);
	ll current_out = 0;

	forn (i) {
		Matrioshka& doll = dolls[i];
		ll mejor_llenando = doll.in;
		ll cantidad_llenando = 1;
		if (i > 0) {
			Matrioshka searched_doll;
			searched_doll.out = doll.in; 
			auto it_best_fit = upper_bound(all(dolls), searched_doll);
			if (it_best_fit != dolls.begin()) {
				it_best_fit--;
				ll sobrante = doll.in - it_best_fit->out;
				ll index_best_fit = it_best_fit - dolls.begin();
				mejor_llenando = mejor_espacio[index_best_fit] + sobrante;
				cantidad_llenando = cant_con_mejor[index_best_fit];
			}

			ll mejor_hasta_ahora = mejor_espacio[i - 1];
			ll diferencia_de_outs = doll.out - dolls[i - 1].out;
			ll mejor_con_anterior = mejor_hasta_ahora + diferencia_de_outs;
			ll cantidad_con_anterior = cant_con_mejor[i - 1];

			if (mejor_con_anterior < mejor_llenando) {
				mejor_espacio[i] = mejor_con_anterior;
				cant_con_mejor[i] = cantidad_con_anterior;
			} else if (mejor_llenando < mejor_con_anterior) {
				mejor_espacio[i] = mejor_llenando;
				cant_con_mejor[i] = cantidad_llenando;
			} else {

			}
			
		}
		current_out = doll.out;
	}



	return 0;
}
