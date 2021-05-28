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

ll distance(ll to, ll from, ll n) {
	if (to < from) {
		return to + n - from;
	} else {
		return to - from;
	}
}

int main() {
	IOS;

	ll n;
	cin >> n;
	vector<ll> cools(n);
	forn (i) {
		cin >> cools[i];
	}

	ll imax = -1;
	ll maxcool = 0;
	ll imin = -1;
	ll mincool = LONG_LONG_MAX;
	for (ll i = 0; i < cools.size(); i++) {
		if (maxcool < cools[i]) {
			imax = i;
			maxcool = cools[i];
		}
		if (mincool > cools[i]) {
			imin = i;
			mincool = cools[i];
		}
	}

	vector<ll> times(n, -1);
	if (maxcool > mincool * 2) {
		ll i = imax + 1;
		for (; i % n != imax && cools[i % n] * 2 >= maxcool ; i++);
		times[imax] = i - imax;

		// sigtes_mayores va a tener una lista estrictamente creciente de números
		// ordenados por aparición en cools.
		// sigtes_menores va a tener una lista estrictamente decreciente de números
		// ordenados por aparición en cools, multiplicados por 2.
		map<ll, ll> sigtes_mayores, sigtes_menores;
		sigtes_mayores[maxcool] = imax;
		sigtes_menores[maxcool * 2] = imax;

		for (ll j = (imax - 1 + n) % n; j != imax; j--) {
			// Tomo el valor del próximo mayor o igual a mí como base.
			auto it_primer_mayor = sigtes_mayores.lower_bound(cools[j]);
			// Siempre existe uno porque está el maxcool.
			assert(it_primer_mayor != sigtes_mayores.end());

			times[j] = times[it_primer_mayor->second] + distance(it_primer_mayor->second, j, n); 

			// Encuentro el primero que sea menor a mi mitad.
			auto it_menor = sigtes_menores.lower_bound(cools[j]);
			if (it_menor != sigtes_menores.begin()) {
				// Si existe, me fijo si la distancia hacia él es mejor que
				// la distancia de mi próximo mayor a su menor.
				it_menor--;
				times[j] = min(times[j], distance(it_menor->second, j, n));
			}

			// Agrego el cools[j] a los maps.
			// Agrego a sigtes_menores y elimino los mayores o iguales.
			sigtes_menores[cools[j] * 2] = j;
			auto it = sigtes_menores.find(cools[j] * 2);
			sigtes_menores.erase(++it, sigtes_menores.end());

			// Agrego a sigtes_mayores y elimino los menores o iguales.
			sigtes_mayores[cools[j]] = j;
			it = sigtes_mayores.find(cools[j]);
			sigtes_mayores.erase(sigtes_mayores.begin(), it);

			if (j == 0) {
				j = n;
			}
		}
	}

	for (ll i = 0; i < times.size(); i++) {
		cout << times[i] << " ";
	}
	cout << endl;


	return 0;
}
