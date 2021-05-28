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

struct Elemento {
	ll max_menor_adelante;
	ll cant_max_menor_adelante;
	ll indice;
	ll num;

	const bool operator<(const Elemento& other) const {
		return max_menor_adelante < other.max_menor_adelante ||
			(max_menor_adelante == other.max_menor_adelante &&
			cant_max_menor_adelante < other.cant_max_menor_adelante);
	}
};


bool puedo_ir_atras(vector<Elemento>& a, ll index_a, ll max_num_izq, ll cant_max_num_izq) {
	ll new_index = index_a - 1;
	bool res = false;
	if (new_index >= 0) {
		Elemento& new_elem = a[new_index];
		res = new_elem.max_menor_adelante > max_num_izq ||
			(new_elem.max_menor_adelante == max_num_izq &&
			new_elem.cant_max_menor_adelante > cant_max_num_izq);
	}
	return res;
}

void solve() {
	ll n;
	cin >> n;
	vector<Elemento> a(n);
	forn (i) {
		cin >> a[i].num;
		a[i].indice = i;
	}

	map<ll, ll> num_ocurrences;
	forn (i) {
		num_ocurrences[a[i].num]++;
	}

	map<ll, ll> nums_adelante;
	// alpha: máximo menor adelante mío, y ocurrencias
	// -1: no hay menor a mí adelante mío
	vector<pair<ll, ll>> maximos_menores_adelante(n, {-1, -1});
	for (ll i = n - 1; i >= 0; i--) {
		ll curr = a[i].num;
		nums_adelante[curr]++;
		// Encontramos el maximo menor a mi
		// lower_bound: el primero mayor o igual
		auto ultimo_menor = nums_adelante.lower_bound(curr);
		if (ultimo_menor != nums_adelante.begin()) {
			ultimo_menor--;
			a[i].max_menor_adelante = ultimo_menor->first;
			a[i].cant_max_menor_adelante = ultimo_menor->second;
		}
	}

	sort(all(a));

	vector<ll> orden;
	vector<ll> cant_menores;
	ll cant_actual = 0;
	for (const pair<ll, ll> num : num_ocurrences) {
		orden.push_back(num.first);
		cant_menores.push_back(cant_actual);
		cant_actual += num.second;
	}

	vector<ll> cant_mayores(orden.size(), 0);
	for (ll i = 0; i < cant_mayores.size(); i++) {
		cant_mayores[i] = n - cant_menores[i] - num_ocurrences[orden[i]];
	}

	map<ll, ll> pos_en_orden;
	for (ll i = 0; i < orden.size(); i++) {
		pos_en_orden[orden[i]] = i;
	}

	ll min_con_menores_adelante = LONG_LONG_MAX;
	ll cant_min_con_menores_adelante = 0;
	ll index_a = a.size();

	ll min_moves = n;

	for (ll i_max_num_izq = orden.size() - 1; i_max_num_izq >= 0; i_max_num_izq--) {
		ll max_num_izq = orden[i_max_num_izq];
		for (
			ll cant_max_num_izq = num_ocurrences[max_num_izq];
			cant_max_num_izq >= 0;
			cant_max_num_izq--
		) {
			while (puedo_ir_atras(a, index_a, max_num_izq, cant_max_num_izq)) {
				index_a--;
				if (min_con_menores_adelante > a[index_a].num) {
					min_con_menores_adelante = a[index_a].num;
					cant_min_con_menores_adelante = 1;
				} else if (min_con_menores_adelante == a[index_a].num) {
					cant_min_con_menores_adelante++;
				}
			}

			ll moves_right = cant_min_con_menores_adelante;
			if (min_con_menores_adelante != LONG_LONG_MAX) {
				moves_right += cant_mayores[pos_en_orden[min_con_menores_adelante]];
			}

			ll moves_left = cant_menores[i_max_num_izq] + cant_max_num_izq;
			min_moves = min(min_moves, moves_right + moves_left);
		}
	}

	cout << min_moves << endl;

}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();


	return 0;
}
