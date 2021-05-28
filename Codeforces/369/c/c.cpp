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
	ll to;
	bool mala = false;
};

bool calcular_candidatos(ll padre, ll nodo, vector<vector<Arista>>& graph,
		vector<ll>& candidatos) {
	bool hay_candidato = false;
	for (Arista& arista : graph[nodo]) {
		if (arista.to != padre) {
			bool candidato_en_subarbol = calcular_candidatos(
				nodo, arista.to, graph, candidatos);
			if (arista.mala && !candidato_en_subarbol) {
				candidatos.push_back(arista.to);
				candidato_en_subarbol = true;
			}
			hay_candidato |= candidato_en_subarbol;
		}
	}
	return hay_candidato;
}

int main() {
	IOS;

	ll n;
	cin >> n;
	vector<vector<Arista>> graph(n);
	fore (i, 0, n - 1) {
		ll from, to, malo;
		cin >> from >> to >> malo;
		from--;
		to--;
		graph[from].push_back({to, malo == 2});
		graph[to].push_back({from, malo == 2});
	}

	vector<ll> candidatos;
	calcular_candidatos(-1, 0, graph, candidatos);

	cout << candidatos.size() << endl;
	for (ll i = 0; i < candidatos.size(); i++) {
		cout << candidatos[i] + 1 << " ";
	}
	cout << endl;

	return 0;
}
