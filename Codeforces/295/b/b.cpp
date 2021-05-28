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
	vector<vector<ll>> weights(n, vector<ll>(n));
	forn (i) {
		forn (j) {
			cin >> weights[i][j];
		}
	}

	vector<ll> deleted(n);
	forn (i) {
		cin >> deleted[i];
		deleted[i]--;
	}

	vector<ll> sums;
	vector<vector<ll>> min_paths(n, vector<ll>(n, LONG_LONG_MAX));
	for (ll addedi = (ll)deleted.size() - 1; addedi >= 0; addedi--) {
		ll sum = 0;
		ll added = deleted[addedi];

		for (ll finali = (ll)deleted.size() - 1; finali > addedi; finali--) {
			ll final = deleted[finali];
			for (ll middlei = (ll)deleted.size() - 1; middlei > addedi; middlei--) {
				ll middle = deleted[middlei];
				// Hay que ver si nos conviene:
				// 1. Ir para middle primero
				min_paths[added][final] = min(
					min_paths[added][final],
					weights[added][middle] + min_paths[middle][final]
				);

				// 2. Que vengan por middle último
				min_paths[final][added] = min(
					min_paths[final][added],
					min_paths[final][middle] + weights[middle][added]
				);
				// 3. Todos los edges son positivos, así que no hace falta
				//	  fijarse si hay ciclos negativos
			}
			sum += min_paths[added][final];
			sum += min_paths[final][added];
		}

		min_paths[added][added] = 0;


		// 4. Pasar por el added entre dos cualquiera para llegar
		//    al otro.
		for (ll fromi = (ll)deleted.size() - 1; fromi > addedi; fromi--) {
			ll from = deleted[fromi];
			for (ll toi = (ll)deleted.size() - 1; toi > addedi; toi--) {
				ll to = deleted[toi];
				min_paths[from][to] = min(
					min_paths[from][to],
					min_paths[from][added] + min_paths[added][to]
				);
				sum += min_paths[from][to];
			}
		}

		sums.push_back(sum);
	}

	for (ll i = (ll)sums.size() - 1; i >= 0; i--) {
		cout << sums[i] << " ";
	}
	cout << endl;


	return 0;
}
