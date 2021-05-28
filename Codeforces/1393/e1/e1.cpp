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

const ll MOD = 1e9 + 7;

void llenar_posib(vec<string>& a, vec<vec<ll>>& posib, ll i_actual) {
	// la ultima es no eliminar ninguna
	string& actual = a[i_actual];
	string& siguiente = a[i_actual + 1];
	vector<ll>& posib_actual = posib[i_actual];
	vector<ll>& posib_siguiente = posib[i_actual + 1];
	posib_actual.resize(actual.size(), 0);

	vec<ll> primer_dif_mismo(actual.size());
	vec<bool> dif_mismo_menor(actual.size());
	ll ultimo_dif = actual.size();
	bool menor = false;
	for (ll i = actual.size() - 1; i >= 0; i--) {
		if (i >= siguiente.size() || actual[i] != siguiente[i]) {
			ultimo_dif = i;
			menor = i < siguiente.size() && actual[i] > siguiente[i];
		}
		primer_dif_mismo[i] = ultimo_dif;
		dif_mismo_menor[i] = menor;
	}

	vec<ll> primer_dif_prox(actual.size());
	vec<bool> dif_prox_menor(actual.size());
	ultimo_dif = actual.size();
	menor = false;
	for (ll i = actual.size() - 1; i >= 0; i--) {
		ll i_prox = i + 1;
		if (i_prox >= siguiente.size() || actual[i] != siguiente[i_prox]) {
			ultimo_dif = i;
			menor = i_prox < siguiente.size() && actual[i] > siguiente[i_prox];
		}
		primer_dif_prox[i] = ultimo_dif;
		dif_prox_menor[i] = menor;
	}

	vec<ll> primer_dif_ant(actual.size());
	vec<bool> dif_ant_menor(actual.size());
	ultimo_dif = actual.size();
	menor = false;
	for (ll i = actual.size() - 1; i > 0; i--) {
		ll i_ant = i - 1;
		if (i_ant >= siguiente.size() || actual[i] != siguiente[i_ant]) {
			ultimo_dif = i;
			menor = i_ant < siguiente.size() && actual[i] > siguiente[i_ant];
		}
		primer_dif_ant[i] = ultimo_dif;
		dif_ant_menor[i] = menor;
	}

	// Los iguales
	for (ll sacado_actual = 0; sacado_actual < a.size(); sacado_actual++) {
		if (sacado_actual < siguiente.size()) {
			ll primer_dif_atras = primer_dif_mismo[sacado_actual];
			ll primer_dif_adelante = primer_dif_mismo[sacado_actual];
			if (primer_dif_atras < sacado_actual) {
				if (actual[primer_dif_atras] <= siguiente[primer_dif_atras]) {
					posib_actual[sacado_actual] += posib_siguiente[sacado_actual];
				}
			} else if ()
		}
	}

	// Primero actual, después siguiente
	for (ll sacado_actual = 0; sacado_actual <= actual.size(); sacado_actual++) {
		// mismo hasta sacado_actual - 1, ant hasta sacado_siguiente - 1, mismo hasta el fin
		for (ll sacado_siguiente = sacado_actual; sacado_siguiente <= siguiente.size(); sacado_siguiente++) {
			if (primer_dif_mismo[0] < sacado_actual) {
				if (!dif_mismo_menor[0]) {
					posib_actual[sacado_actual] += posib_siguiente[sacado_siguiente];
				}
			} else if (primer_dif_ant[sacado_actual] < sacado_siguiente) {
				if (!dif_ant_menor[sacado_actual]) {
					posib_actual[sacado_actual] += posib_siguiente[sacado_siguiente];
				}
			} else if (sacado_siguiente < actual.size() && primer_dif_mismo[sacado_siguiente] < )

			posib_actual[sacado_actual] %= MOD;
		}

	}

}

int main() {
	IOS;

	ll n;
	cin >> n;
	vector<string> a(n);
	forn (i) cin >> a[i];

	vector<vec<ll>> posib(n);
	for (ll i = 0; i <= a[n -1].size(); i++) {
		posib[n-1].push_back(1);
	}

	for (ll i = n - 2; i >= 0; i--) {
		llenar_posib(a, posib, i);
	}
	ll total = 0;
	for (ll i = 0; i < posib[0].size(); i++) {
		total += posib[0][i];
		total %= MOD;
	}

	cout << total << endl;


	return 0;
}
