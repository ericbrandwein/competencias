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

int main() {
	IOS;

	ll n;
	cin >> n;
	vector<string> nombres(n);
	forn (i) {
		cin >> nombres[i];
	}

	string chars = "DR";

	vector<ll> empieza(n, -1);
	vector<ll> termina(n, -1);
	forn (i) {
		string& nombre = nombres[i];
		string nuevo_nombre = "";

		ll char_actual = -1;
		fore (j, 0, nombre.size()) {
			if (char_actual == -1) {
				if (nombre[j] == chars[0]) {
					char_actual = 1;
					nuevo_nombre.push_back(nombre[j]);
					empieza[i] = 0;
				} else if (nombre[j] == chars[1]) {
					char_actual = 0;
					nuevo_nombre.push_back(nombre[j]);
					empieza[i] = 1;
				}
			} else if (nombre[j] == chars[char_actual]) {
				char_actual++;
				char_actual %= 2;
				nuevo_nombre.push_back(nombre[j]);
			}
		}
		termina[i] = (char_actual + 1) % 2;

		nombre = nuevo_nombre;
	}

	vector<vector<ll>> start(2);
	ll total = 0;
	
	forn (i) {
		if (empieza[i] == 0) {
			if (termina[i] == 1) {
				total += nombres[i].size() / 2;
			} else {
				start[0].push_back(i);
			}
		} else if (empieza[i] == 1) {
			start[1].push_back(i);
		}
	}

	ll com_firma = 0;
	vector<ll> indexes = {0, 0}; 
	
	bool terminar = false;
	while (!terminar) {
		while (indexes[com_firma] < start[com_firma].size()) {
			ll indice_palabra = start[com_firma][indexes[com_firma]];
			if (com_firma == 1) {
				total++;
				total += (nombres[indice_palabra].size() - 1) / 2;
			} else {
				total += nombres[indice_palabra].size() / 2;
			}
			dbg(com_firma);
			dbg(nombres[indice_palabra]);
			dbg(total);
			indexes[com_firma]++;
			com_firma = (termina[indice_palabra] + 1) % 2;
		}
		// Nos quedamos sin de com_firma
		com_firma++;
		com_firma %= 2;
		if (indexes[com_firma] < start[com_firma].size()) {
			ll indice_palabra = start[com_firma][indexes[com_firma]];
			if (com_firma == 0) {
				// Le sacamos una D
				total += nombres[indice_palabra].size() / 2;
			} else {
				// Le sacamos una R
				total += (nombres[indice_palabra].size() - 1) / 2;
			}
			indexes[com_firma]++;
			com_firma = (termina[indice_palabra] + 1) % 2;
		} else {
			terminar = true;
		}
	}

	cout << total << endl;

	return 0;
}
