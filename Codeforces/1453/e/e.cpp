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

vec<vec<ll>> enraizar(vec<vec<ll>>& graph) {
	ll n = graph.size();
	vec<ll> padres(n, -1);
	vec<vec<ll>> hijos(n);
	stack<ll> next;
	next.push(0);
	while (!next.empty()) {
		ll curr = next.top();
		next.pop();
		for (ll child : graph[curr]) {
			if (padres[curr] != child) {
				hijos[curr].push_back(child);
				padres[child] = curr;
				next.push(child);
			}
		}
	}
	return hijos;
}

ll calcular_altura_min(vec<ll>& alturas_min, ll nodo, vec<vec<ll>>& hijos) {
	if (hijos[nodo].empty()) {
		alturas_min[nodo] = 0;
	} else {
		alturas_min[nodo] = LONG_LONG_MAX;
	}
	ll max_min_saltos = 0;
	for (ll hijo : hijos[nodo]) {
		max_min_saltos = max(max_min_saltos, calcular_altura_min(alturas_min, hijo, hijos));
		alturas_min[nodo] = min(alturas_min[nodo], alturas_min[hijo] + 1);
		max_min_saltos = max(max_min_saltos, alturas_min[hijo] + 1);
		if (hijos[nodo].size() > 1 && nodo != 0) {
			max_min_saltos = max(max_min_saltos, alturas_min[hijo] + 2);
		}
	}
	return max_min_saltos;
}

void solve() {
	ll n;
	cin >> n;
	vec<vec<ll>> graph(n);
	fore (i, 0, n-1) {
		ll from, to;
		cin >> from >> to;
		from--;
		to--;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	vec<vec<ll>> hijos = enraizar(graph);
	vec<ll> alturas_min(n);
	ll k = max(calcular_altura_min(alturas_min, 0, hijos), alturas_min[0]);
	ll hijos_k = 0;
	for (ll hijo : hijos[0]) {
		if (alturas_min[hijo] == k - 1) hijos_k++;
	}
	if (hijos_k > 1) k++;

	cout << k << endl;

}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}
