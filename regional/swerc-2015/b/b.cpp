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

struct Investigation {
	pair<ll,ll> letters;
	ll player;
	ll reply;
};

const ll LETRAS = 'Z' - 'A' + 1;
bool avanzar(vec<ll>& tripla) {
	if (tripla[2] == LETRAS - 1) {
		if (tripla[1] == LETRAS - 2) {
			if (tripla[0] == LETRAS - 3) {
				return false;
			} else {
				tripla[0]++;
				tripla[1] = tripla[0] + 1;
				tripla[2] = tripla[1] + 1;
			}
		} else {
			tripla[1]++;
			tripla[2] = tripla[1] + 1;
		}
	} else {
		tripla[2]++;
	}
	return true;
}

bool colorear(vec<vec<ll>>& graph, vec<ll>& colores, ll color, ll nodo) {
	if (colores[nodo] == color) return true;
	else if (colores[nodo] == 1 - color) return false;
	else {
		bool se_puede = true;
		colores[nodo] = color;
		for (ll child : graph[nodo]) {
			if (!colorear(graph, colores, 1 - color, child)) {
				se_puede = false;
			}
		}
		return se_puede;
	}
}

bool bipartito(vec<vec<ll>>& graph, vec<ll>& colores) {
	bool se_puede = true;
	for (ll i = 0; i < graph.size(); i++) {
		if (colores[i] != -1) {
			for (ll child : graph[i]) {
				se_puede &= colorear(graph, colores, 1- colores[i], child);
			}
		}
	}
	for (ll i = 0; i < graph.size(); i++) {
		if (colores[i] == -1) {
			se_puede &= colorear(graph, colores, 0, i);
		}
	}
	return se_puede;
}

int main() {
	IOS;

	ll n;
	cin >> n;
	ll letras = LETRAS;
	vec<Investigation> investigations(n);
	vec<vec<ll>> graph(letras * 2);
	// -1: no marcado
	// 0: no está
	// 1: está
	vec<ll> color(letras*2, -1);
	bool se_puede = true;
	forn (i) {
		char first, second;
		cin >> first >> second;
		investigations[i].letters.first = first - 'A';
		investigations[i].letters.second = second - 'A';
		cin >> investigations[i].player >> investigations[i].reply;
		investigations[i].player--;
		ll from = investigations[i].player * letras + investigations[i].letters.first;
		ll to = investigations[i].player * letras + investigations[i].letters.second;
		if (investigations[i].reply == 0) {
			if (color[from] == 1 || color[to] == 1) {
				se_puede = false;
			}
			color[from] = color[to] = 0;
		} else if (investigations[i].reply == 2) {
			if (color[from] == 0 || color[to] == 0) {
				se_puede = false;
			}
			color[from] = color[to] = 1;
		} else {
			graph[from].push_back(to);
			graph[to].push_back(from);
		}
	}

	if (!se_puede) {
		cout << 0 << endl;
		return 0;
	}

	for (ll i = 0; i < letras; i++) {
		graph[i].push_back(letras + i);
		graph[letras + i].push_back(i);
	}

	// Por cada tripla copiamos el graph y tratamos de hacerlo bipartito
	vec<ll> tripla = {0, 1, 1};
	ll res = 0;
	while(avanzar(tripla)) {
		se_puede = true;
		for (ll num : tripla) {
			if (color[num] == 1 || color[letras + num] == 1) {
				se_puede = false;
			}
		}
		if (se_puede) {
			vec<vec<ll>> nuevo_graph = graph;
			vec<ll> nuevo_color = color;
			for (ll num : tripla) {
				nuevo_graph[num].pop_back();
				nuevo_graph[letras+num].pop_back();
				nuevo_color[num] = 0;
				nuevo_color[letras+num] = 0;
			}

			if (bipartito(nuevo_graph, nuevo_color)) {
				res++;
			}
		}
	}

	cout << res << endl;


}
