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

bool dfs(vec<vec<bool>>& posibles, vec<bool>& usados, 
	int jurados_q, int actual, int combinados, int quedan) {
	
	if (actual >= usados.size()) {
		return usados.size() - combinados <= jurados_q;
	}

	if (usados.size() - combinados - quedan / 2 > jurados_q) {
		return false;
	}

	if (!usados[actual]) {
		quedan-=2;
		combinados++;
		for (int i = actual + 1; i < posibles[actual].size(); i++) {
			if (posibles[actual][i] && !usados[i]) {
				usados[i] = true;
				if (dfs(posibles, usados, jurados_q, actual + 1, combinados, quedan)) {
					return true;
				}
				usados[i] = false;
			}
		}
		quedan++;
		combinados--;
	}

	return dfs(posibles, usados, jurados_q, actual + 1, combinados, quedan);
}

bool mismo_tap_diferentes(vec<vec<string>>& taps) {
	fore (i, 0, taps.size()) {
		set<string> nombres;
		fore (j, 0, taps[i].size()) {
			nombres.insert(taps[i][j]);
		}
		if (nombres.size() != taps[i].size()) {
			return false;
		}
	}
	return true;
}

int main() {
	IOS;

	ll taps_q, jurados_q;
	cin >> taps_q >> jurados_q;

	set<string> set_jurados;
	vector<vec<string>> taps(taps_q, vec<string>(jurados_q));
	fore (i, 0, taps_q) {
		fore (j, 0, jurados_q) {
			cin >> taps[i][j];
			set_jurados.insert(taps[i][j]);
			if (set_jurados.size() > 2 * jurados_q) {
				cout << "N" << endl;
				return 0;
			}
		}
	}

	if (!mismo_tap_diferentes(taps)) {
		cout << "N" << endl;
		return 0;
	}

	vector<string> jurados {set_jurados.begin(), set_jurados.end()};
	vector<vec<bool>> posibles(jurados.size(), vec<bool>(jurados.size(), true));

	fore (k, 0, jurados.size()) {
		fore (i, 0, taps.size()) {
			bool contiene = false;
			fore (j, 0, taps[i].size()) {
				if (jurados[k] == taps[i][j]) {
					contiene = true;
				}
			}

			if (contiene) {
				fore (j, 0, taps[i].size()) {
					string& a_buscar = taps[i][j]; 
					ll l = 0;
					for (; l < jurados.size() && jurados[l] != a_buscar; l++);
					posibles[k][l] = false;
				}
			}
		}
	}

	fore (i, 0, posibles.size()) {
		posibles[i][i] = false;
	}

	vec<bool> usados(jurados.size(), false);
	bool se_puede = dfs(posibles, usados, jurados_q, 0, 0, jurados.size());

	if (se_puede) {
		cout << "S" << endl;
	} else {
		cout << "N" << endl;
	}


	
	return 0;
}
