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


struct Arista {
	ll nodo, costo, prestigio;
};



int main() {
	IOS;

	ll max_peso, n;
	cin >> max_peso >> n;

	vec<string> nombres;
	map<string, ll> indices;
	vec<vec<Arista>> hijos, padres;
	forn (i) {
		string nombre, base, ingr;
		ll costo, prestigio;
		cin >> nombre >> base >> ingr >> costo >> prestigio;
		if (indices.count(nombre) == 0) {
			indices[nombre] = nombres.size();
			nombres.push_back(nombre);
			hijos.emplace_back();
			padres.emplace_back();
		}
		if (indices.count(base) == 0) {
			indices[base] = nombres.size();
			nombres.push_back(base);
			hijos.emplace_back();
			padres.emplace_back();
		}
		hijos[indices[base]].push_back({indices[nombre], costo, prestigio});
		padres[indices[nombre]].push_back({indices[base], costo, prestigio});
	}

	vec<ll> costos(nombres.size(), LONG_LONG_MAX), prestigios(nombres.size(), -1);
	vec<ll> padres_visitados(nombres.size(), 0);
	stack<ll> next;
	for (ll i = 0; i < nombres.size(); i++) {
		if (padres[i].empty()) {
			costos[i] = prestigios[i] = 0;
			next.push(i);
		}
	}

	while (!next.empty()) {
		ll curr = next.top();
		next.pop();

		for (Arista& padre : padres[curr]) {
			ll nodo_padre = padre.nodo;
			ll nuevo_costo = padre.costo + costos[nodo_padre];
			ll nuevo_prestigio = padre.prestigio + prestigios[nodo_padre];
			if (costos[curr] > nuevo_costo ||
				(costos[curr] == nuevo_costo && prestigios[curr] < nuevo_prestigio)
			) {
				costos[curr] = nuevo_costo;
				prestigios[curr] = nuevo_prestigio;
			}
		}

		for (Arista& hijo : hijos[curr]) {
			padres_visitados[hijo.nodo]++;
			if (padres_visitados[hijo.nodo] == padres[hijo.nodo].size()) {
				next.push(hijo.nodo);
			}
		}
	}

	// tengo los costos y los prestigios, hay que hacer mochila
	vec<ll> prestigio_por_costo(max_peso + 1, -1);
	prestigio_por_costo[0] = 0;
	for (ll i = 0; i < nombres.size(); i++) {
		ll peso_actual = costos[i];
		for (ll peso = max_peso - peso_actual; peso >= 0; peso--) {
			if (prestigio_por_costo[peso] != -1) {
				prestigio_por_costo[peso + peso_actual] = max(
					prestigio_por_costo[peso + peso_actual],
					prestigio_por_costo[peso] + prestigios[i]
				);
			}
		}
	}

	ll mejor_peso = 0;
	for (ll i = 0; i <= max_peso; i++) {
		if (prestigio_por_costo[mejor_peso] < prestigio_por_costo[i]) {
			mejor_peso = i;
		}
	}

	cout << prestigio_por_costo[mejor_peso] << endl;
	cout << mejor_peso << endl;




}
