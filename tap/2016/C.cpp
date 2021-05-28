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

struct Materia {
	bool registrada = true;
	vector<ll> hijos;
};

ll desregistrar(ll materia, vector<Materia>& materias) {
	stack<ll> dfs;
	dfs.push(materia);
	ll cant = 0;
	while (!dfs.empty()) {
		ll actual = dfs.top(); dfs.pop();
		if (materias[actual].registrada) {
			cant++;
			fore (i, 0, materias[actual].hijos.size()) {
				dfs.push(materias[actual].hijos[i]);
			}
			materias[actual].registrada = false;
		}
	}
	return cant;
}

int main() {
	IOS;

	ll n, m;
	cin >> n >> m;
	vector<Materia> materias(n);
	fore (i, 0, m) {
		ll desde, hasta;
		cin >> desde >> hasta;
		materias[desde - 1].hijos.push_back(hasta - 1);
	}

	vector<ll> aprobadas(n);
	forn (i) {
		cin >> aprobadas[i];
		aprobadas[i]--;
	}

	vector<ll> registradas = {n};


	for (ll i = n - 1; i > 0; i--) {
		ll desregistradas = desregistrar(aprobadas[i], materias);
		registradas.push_back(registradas[registradas.size() - 1] - desregistradas);
	}

	for (ll i = registradas.size() - 1; i >= 0; i--) {
		cout << registradas[i] << endl;
	}

	return 0;
}
