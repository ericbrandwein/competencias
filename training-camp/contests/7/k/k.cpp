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

const ll abcd= 'z' - 'a' + 1;


vector<ll> operator-(const vector<ll>& first, const vector<ll>& second) {
	vector<ll> res = first;
	for (ll i = 0; i < second.size(); i++) {
		res[i] -= second[i];
	}
	return res;
}

vector<ll> operator+(const vector<ll>& first, const vector<ll>& second) {
	vector<ll> res = first;
	for (ll i = 0; i < second.size(); i++) {
		res[i] += second[i];
	}
	return res;
}


void operator+=(vector<ll>& first, const vector<ll>& second) {
	first = first + second;
}

void operator-=(vector<ll>& first, const vector<ll>& second) {
	first = first - second;
}

struct Intervalo {
	ll from, to;
	vector<ll> elems;
	bool asc;

	bool operator<(const Intervalo& otro) const {
		return from < otro.from;
	}

	vector<ll> primeros_asc(ll n) const {
		vector<ll> res(abcd, 0);
		for (ll i = 0; i < elems.size() && n > 0; i++) {
			ll added = min(elems[i], n);
			res[i] = added;
			n -= added;
		}
		return res;
	}

	vector<ll> ultimos_asc(ll n) const {
		vector<ll> res(abcd, 0);
		for (ll i = elems.size() - 1; i >= 0 && n > 0; i--) {
			ll added = min(elems[i], n);
			res[i] = added;
			n -= added;
		}
		return res;
	}

	vector<ll> ultimos(ll n) const {
		if (asc) {
			return ultimos_asc(n);
		} else {
			return primeros_asc(n);
		}
	}

	vector<ll> primeros(ll n) const {
		if (asc) {
			return primeros_asc(n);
		} else {
			return ultimos_asc(n);
		}
	}
};


void agregar_a_intervalos(set<Intervalo>& intervalos, Intervalo& intervalo) {
	auto ultimo_menor = intervalos.upper_bound(intervalo);
	if (ultimo_menor != intervalos.begin()) {
		ultimo_menor--;
	}
	vector<Intervalo> agregados;
	if (ultimo_menor->to > intervalo.to && ultimo_menor->from < intervalo.from) {
		ll dist_antes = intervalo.from - ultimo_menor->from;
		ll dist_despues = ultimo_menor->to - intervalo.to;
		vector<ll> antes = ultimo_menor->primeros(dist_antes);
		vector<ll> despues = ultimo_menor->ultimos(dist_despues);
		vector<ll> restantes = ultimo_menor->elems - antes - despues;
		intervalo.elems = restantes;
		Intervalo int_antes = *ultimo_menor;
		Intervalo int_despues = *ultimo_menor;
		int_antes.elems = antes;
		int_antes.to = intervalo.from - 1;
		int_despues.elems = despues;
		int_despues.from = intervalo.to + 1;
		agregados.push_back(int_antes);
		agregados.push_back(int_despues);
		intervalos.erase(ultimo_menor);
	} else {
		if (ultimo_menor->from < intervalo.from && ultimo_menor->to >= intervalo.from) {
			ll dist = ultimo_menor->to - intervalo.from + 1;
			vector<ll> ultimos = ultimo_menor->ultimos(dist);
			intervalo.elems += ultimos;
			auto it = ultimo_menor;
			ultimo_menor++;
			Intervalo sacado = *it;
			intervalos.erase(it);
			sacado.to = intervalo.from - 1;
			sacado.elems -= ultimos;
			agregados.push_back(sacado);
		}
		while (ultimo_menor != intervalos.end() && ultimo_menor->to <= intervalo.to) {
			intervalo.elems += ultimo_menor->elems;
			auto it = ultimo_menor++;
			intervalos.erase(it);
		}

		if (ultimo_menor != intervalos.end() && ultimo_menor->from <= intervalo.to) {
			ll dist = intervalo.to - ultimo_menor->from + 1;
			vector<ll> add = ultimo_menor->primeros(dist);
			intervalo.elems += add;
			Intervalo anterior = *ultimo_menor;
			anterior.from = intervalo.to + 1;
			anterior.elems -= add;
			intervalos.erase(ultimo_menor);
			agregados.push_back(anterior);
		}
	}

	intervalos.insert(intervalo);
	for (const Intervalo& i : agregados) {
		intervalos.insert(i);
	}
}


int main() {
	IOS;

	ll n, q;
	cin >> n >> q;

	string s;
	cin >> s;

	set<Intervalo> intervalos;

	for (ll i = 0; i < n; i++) {
		vector<ll> elems(abcd, 0);
		ll letra = s[i] - 'a';
		elems[letra]++;
		intervalos.insert({i, i, elems, true});
	}

	fore (i, 0, q) {
		Intervalo intervalo;
		cin >> intervalo.from >> intervalo.to;
		intervalo.from--;
		intervalo.to--;
		ll asc;
		cin >> asc;
		intervalo.asc = asc;
		intervalo.elems = vector<ll>(abcd, 0);

		agregar_a_intervalos(intervalos, intervalo);
	}


	for (const Intervalo& intervalo : intervalos) {
		// los muestro
		const vector<ll>& elems = intervalo.elems;
		if (intervalo.asc) {
			for (ll i = 0; i < elems.size(); i++) {
				for (ll j = 0; j < elems[i]; j++) {
					cout << (char)('a' + i);
				}
			}
		} else {
			for (ll i = elems.size() - 1; i >= 0; i--) {
				for (ll j = 0; j < elems[i]; j++) {
					cout << (char)('a' + i);
				}
			}
		}
	}
	cout << endl;


	return 0;
}
