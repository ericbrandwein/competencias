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

double mean_de(ll fila, ll columna, ll dado, vector<vector<double>>& means,
	vector<vector<ll>>& stairs) {
	if (fila % 2 == 0) {
		// Mirar para atrás.
		if (dado > columna) {
			fila--;
			columna = dado - columna - 1;
		} else {
			columna -= dado;
		}
	} else {
		// Mirar para adelante.
		if (dado + columna >= 10) {
			fila--;
			columna = 10 - dado + 10 - columna - 1;
		} else {
			columna += dado;
		}
	}
	double mean = min(
		means[fila][columna],
		means[fila - stairs[fila][columna]][columna]
	);
	return mean;
}

double mean_de(ll fila, ll col, vector<vector<double>>& means, vector<vector<ll>>& stairs) {
	double mean = 0;
	for (ll dado = 1; dado <= 6; dado++) {
		mean += mean_de(fila, col, dado, means, stairs);
	}
	return mean / 6.0 + 1.0;
}

int main() {
	IOS;

	vector<vector<ll>> grid(10, vector<ll>(10));
	fore (i, 0, 10) {
		fore (j, 0, 10) {
			cin >> grid[i][j];
		}
	}

	vector<vector<double>> means(10, vector<double>(10, 0));
	means[0][1] = 6;
	means[0][2] = (1.0 + 6.0 + 5.0) / 2.0;
	means[0][3] = (4.0 + 1.0 + 6.0 + 1.0 + means[0][2]) / 3.0;
	means[0][4] = (1.0 + 1.0 + 6.0 + 1.0 + means[0][2] + 1.0 + means[0][3] + 2.0) / 4.0;
	means[0][5] = (1.0 + 1.0 + 6.0 + 1.0 + means[0][2] + 1.0 + means[0][3] + 1.0 + means[0][4] + 1.0) / 5.0;

	for (ll i = 0; i < 10; i++) {
		if (i % 2 == 0) {
			ll j = 6;
			if (i > 0) j = 0;
			for (; j < 10; j++) {
				means[i][j] = mean_de(i, j, means, grid);
			}
		} else {
			for (ll j = 9; j >= 0; j--) {
				means[i][j] = mean_de(i, j, means, grid);
			}
		}
	}

	presicion(10);
	cout << means[9][0] << endl;
	return 0;
}
