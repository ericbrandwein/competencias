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

struct Arbol {
	ll raiz, valor;

	bool operator<(const Arbol& otro) const {
		return valor < otro.valor;
	}
};

int main() {
	IOS;

	/*
	n <= 2*10^5
	6
	3 6 3 1 5

	Ahí tengo que:
	1. Ver cuáles no están en la lista. Esas son las hojas.
	   Cada hoja va a generar un árbol de un solo nodo con valor
	   igual a i, y raíz i.
	   No hace falta guardar el 2^i, solo el máximo i del árbol, porque no podés
	   sumar más que 2^i con todos los 2^j menores a i.
	   O sea, si un árbol tiene un i, todo árbol con máximo menor a i
	   tiene suma menor, y todo árbol con máximo mayor a i tiene suma mayor.
	2. Poner en un set los árboles por valor de menor a mayor.
	3. Agarrar el último número k de la lista. Ese está conectado como
	   padre del árbol con menor valor i. Esto genera un nuevo árbol con valor
	   igual a max(k, i), y raíz k.
	   Qué pasa si había ya un árbol con la misma raíz? Hay que unirlos. Cómo
	   saber si había un árbol con la misma raíz? Bueno, podríamos guardar
	   en un vectorcito la raíz y el valor de su subárbol o -1 si no hay subárbol.
	   Entonces, si tiene subárbol, se busca ese subárbol en el set, se elimina, y
	   se crea un nuevo subárbol con raíz k y valor igual al máximo entre los dos
	   valores.
	*/

	ll n;
	cin >> n;

	vector<ll> padres(n);
	vector<bool> presentes(n, false);
	fore (i, 0, n - 1) {
		cin >> padres[i];
		padres[i]--;
		presentes[padres[i]] = true;
	}

	set<Arbol> arboles;
	for (ll i = 0; i < presentes.size(); i++) {
		if (!presentes[i]) {
			// Es una hoja
			arboles.insert(Arbol{i, i});
		}
	}

	vector<ll> valores(n, -1);
	vector<pair<ll, ll>> edges;
	for (ll i = padres.size() - 1; i >= 0; i--) {
		ll padre_actual = padres[i];

		auto it_arbol_mas_chico = arboles.begin();
		edges.push_back({padre_actual, it_arbol_mas_chico->raiz});

		ll valor = max(padre_actual, it_arbol_mas_chico->valor);
		valores[it_arbol_mas_chico->raiz] = -1;
		arboles.erase(it_arbol_mas_chico);
		if (valores[padre_actual] != -1) {
			valor = max(valor, valores[padre_actual]);
			arboles.erase(Arbol{padre_actual, valores[padre_actual]});
		}

		arboles.insert(Arbol{padre_actual, valor});
		valores[padre_actual] = valor;
	}

	cout << padres[0] + 1 << endl;
	for (ll i = 0; i < edges.size(); i++) {
		cout << edges[i].first + 1 << " " << edges[i].second + 1 << endl;
	}






	return 0;
}
