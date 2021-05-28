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

struct Bridge {
	ll length, indice;

	bool operator<(const Bridge& otro) const {
		return this->length < otro.length;
	}
};

struct Intervalo {
	ll isla;
	pair<ll, ll> intervalo;

	bool operator<(const Intervalo& otro) const {
		return this->intervalo.second < otro.intervalo.second;
	}
};

bool comp_princ(const Intervalo& first, const Intervalo& other) {
	return first.intervalo.first < other.intervalo.first;
}


int main() {
	IOS;

	ll n, m;
	cin >> n >> m;

	vector<pair<ll, ll>> islands(n);
	forn (i) {
		cin >> islands[i].first >> islands[i].second;
	}

	vector<Bridge> bridges(m);
	fore (i, 0, m) {
		cin >> bridges[i].length;
		bridges[i].indice = i;
	}

	sort(all(bridges));

	vector<Intervalo> intervalos;
	fore (i, 0, n - 1) {
		ll minimo = islands[i + 1].first - islands[i].second;
		ll maximo = islands[i+1].second - islands[i].first;
		auto it = lower_bound(
			all(bridges), Bridge{minimo, 0}
		);
		ll indice_desde = it - bridges.begin();
		auto otro_it = upper_bound(
			all(bridges), Bridge{maximo, 0}
		);
		ll indice_hasta = otro_it - bridges.begin();

		Intervalo intervalo;
		intervalo.isla = i;
		intervalo.intervalo = {indice_desde, indice_hasta};
		intervalos.push_back(intervalo);
	}

	sort(intervalos.begin(), intervalos.end(), comp_princ);

	multiset<Intervalo> intervalos_actuales;
	vector<ll> puentes_elegidos(n-1, -1);
	ll indice_intervalo = 0;
	fore (i, 0, bridges.size()) {
		while (indice_intervalo < intervalos.size() &&
			intervalos[indice_intervalo].intervalo.first == i
		) {
			intervalos_actuales.insert(
				intervalos[indice_intervalo]
			);
			indice_intervalo++;
		}

		if (!intervalos_actuales.empty()) {
			auto it = intervalos_actuales.begin();
			if (it->intervalo.second <= i) {
				cout << "No" << endl;
				return 0;
			}
			puentes_elegidos[it->isla] = bridges[i].indice;
			intervalos_actuales.erase(it);
		}
	}


	for (ll i = 0; i < n - 1; i++) {
		if (puentes_elegidos[i] == -1) {
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;
	for (ll elegido: puentes_elegidos) {
		cout << elegido + 1 << " ";
	}
	cout << endl;




	return 0;
}
