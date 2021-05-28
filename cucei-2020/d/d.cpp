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

vec<vec<pair<ll,ll>>> enraizar(vec<vec<pair<ll,ll>>>& graph, vec<ll>& padres) {
	ll n = graph.size();
	vec<vec<pair<ll,ll>>> hijos(n);
	stack<ll> next;
	next.push(0);
	while (!next.empty()) {
		ll curr = next.top();
		next.pop();

		for (pair<ll,ll> par : graph[curr]) {
			ll hijo = par.first;
			if (padres[curr] != hijo) {
				hijos[curr].push_back(par);
				padres[hijo] = curr;
				next.push(hijo);
			}
		}
	}

	return hijos;
}

vec<ll> rotar(vec<ll>& orig, ll cant) {
	ll n = orig.size();
	vec<ll> nuevo(n);
	for (ll i = 0; i < n; i++) {
		nuevo[(i+cant) % n] = orig[i];
	}
	return nuevo;
}

vec<ll> multiplicar(vec<ll>& uno, vec<ll> otro) {
	ll n = uno.size();
	vec<ll> res(n, 0);
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			res[(i+j) % n] += (uno[i]*otro[j]) % MOD;
			res[(i+j) % n] %= MOD;
		}
	}
	return res;
}


vec<ll> sacar_combis(vec<vec<pair<ll,ll>>>& graph) {
	ll n = graph.size();
	vec<ll> combis(n, 0);

	vec<ll> padres(n, -1);
	vec<vec<pair<ll,ll>>> hijos = enraizar(graph, padres);
	vec<ll> hijos_visitados(n, 0);
	stack<ll> next;
	for (ll i = 0; i < n; i++) {
		if (hijos[i].empty()) next.push(i);
	}

	vec<map<ll,vec<ll>>> combinaciones(n); // [nodo][padre][resto]

	while (!next.empty()) {
		ll curr = next.top();
		next.pop();

		if (hijos_visitados[curr] == hijos[curr].size() && padres[curr] != -1) {
			vec<ll> valores = {1, 0, 0, 0, 0};
			for (pair<ll,ll> par : hijos[curr]) {
				ll hijo = par.first;
				ll dist = par.second;
				vec<ll> rotado = rotar(combinaciones[hijo][curr], dist);
				rotado[0]++;
				rotado[0] %= MOD;
				valores = multiplicar(valores, rotado);
			}
			combinaciones[curr][padres[curr]] = valores;
			hijos_visitados[padres[curr]]++;
			next.push(padres[curr]);
		}
	}

	// Llene las combinaciones para todos los nodos habiendo enraizado,
	// tengo que rellenarlas para todas sus otras raíces, yendo del 0 para abajo.
	next.push(0);
	while (!next.empty()) {
		ll curr = next.top();
		next.pop();

		for (pair<ll,ll> par : hijos[curr]) {
			ll hijo = par.first;
			vec<ll> valores = {1, 0, 0, 0, 0};
			for (pair<ll,ll> otro_par : graph[curr]) {
				ll otro_hijo = otro_par.first;
				if (otro_hijo != hijo) {
					ll otro_dist = otro_par.second;
					vec<ll> rotado = rotar(combinaciones[otro_hijo][curr], otro_dist);
					rotado[0]++;
					rotado[0] %= MOD;
					valores = multiplicar(valores, rotado);
				}
			}
			combinaciones[curr][hijo] = valores;

			next.push(hijo);
		}

		vec<ll> valores = {1, 0, 0, 0, 0};
		for (pair<ll,ll> par : graph[curr]) {
			ll hijo = par.first;
			ll dist = par.second;
			vec<ll> rotado = rotar(combinaciones[hijo][curr], dist);
			rotado[0]++;
			rotado[0] %= MOD;
			valores = multiplicar(valores, rotado);
		}
		combis[curr] = valores[0];
	}

	return combis;

}

int main() {
	IOS;

	ll n;
	cin >> n;
	vec<vec<pair<ll,ll>>> graph(n); // to, cost
	fore (i, 0, n-1) {
		ll from, to, cost;
		cin >> from >> to >> cost;
		from--;
		to--;
		cost %= 5;
		graph[from].push_back({to, cost});
		graph[to].push_back({from, cost});
	}

	vec<ll> combi = sacar_combis(graph);

	ll q;
	cin >> q;
	while (q--) {
		ll node;
		cin >> node;
		node--;
		cout << combi[node] << endl;
	}

}
