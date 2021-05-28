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

struct Hoja {
	ll altura, hijos_padre, indice;
	bool operator<(const Hoja& other) const {
		return altura < other.altura || (
			altura == other.altura && (
				hijos_padre > other.hijos_padre || (hijos_padre == other.hijos_padre && indice < other.indice)
			)
		);
	}
};

int main() {
	IOS;

	ll n, k;
	cin >> n >> k;
	vec<vec<ll>> hijos(n);
	vec<ll> padres(n);
	forn (i) {
		ll padre;
		cin >> padre;
		padre--;
		if (padre != -1) {
			hijos[padre].push_back(i);
		}
		padres[i] = padre;
	}


	vec<ll> alturas(n);
	stack<ll> next;
	for (ll i = 0; i < n; i++) {
		if (padres[i] == -1) {
			next.push(i);
			alturas[i] = 0;
		}
	}

	while (!next.empty()) {
		ll curr = next.top();
		next.pop();
		for (ll child : hijos[curr]) {
			alturas[child] = alturas[curr] + 1;
			next.push(child);
		}
	}

	ll res = 0;
	set<Hoja> hojas;
	for (ll i = 0; i < n; i++) {
		if (hijos[i].empty()) {
			Hoja nueva = {alturas[i], LONG_LONG_MAX, i};
			if (padres[i] != -1) {
				nueva.hijos_padre = hijos[padres[i]].size();
			}
			hojas.insert(nueva);
		}
	}

	while (!hojas.empty()) {
		vec<Hoja> a_sacar;
		for (auto it = hojas.rbegin(); a_sacar.size() < k && it != hojas.rend(); it++) {
			a_sacar.push_back(*it);
		}

		for (Hoja hoja : a_sacar) {
			hojas.erase(hoja);
			ll indice = hoja.indice;
			ll padre = padres[indice];
			if (padre != -1) {
				hijos[padre].pop_back();
				if (hijos[padre].empty()) {
					Hoja nueva = {alturas[padre], LONG_LONG_MAX, padre};
					if (padres[padre] != -1) {
						nueva.hijos_padre = hijos[padres[padre]].size();
					}
					hojas.insert(nueva);
				}
			}
		}

		res++;
	}

	cout << res << endl;

	return 0;
}
