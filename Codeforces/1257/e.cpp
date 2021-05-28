// //#pragma GCC optimize("Ofast")
// //#pragma GCC optimize("unroll-loops,no-stack-protector")
// //#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #include <bits/stdc++.h>

// #define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
// #define endl '\n'
// #define elif else if
// #define ll long long int
// #define ld long double
// #define vec vector
// #define forn(a) for(ll a=0; a<n; a++)
// #define fore(a, v, n) for(ll a=v; a<n; a++)
// #define all(x) x.begin(), x.end()
// #define presicion(x) cout<<fixed<<setprecision(x)
// #define dbg(x) cerr<<#x<<" = "<<x<<endl
// #define PI 3.14159265358979323
// #define sen(ang) sin((ang)*PI/180)
// //cout<<flush;

// using namespace std;

// int main() {
// 	IOS;

// 	vector<ll> ks(3);
// 	for (ll i = 0; i <3; i++) {
// 		cin >> ks[i];
// 	}

// 	vector<vector<ll>> resueltos(3);

// 	for (ll i = 0; i < 3; i++) {
// 		for (ll j = 0; j < ks[i];j++) {
// 			ll num;
// 			cin >> num;
// 			resueltos[i].push_back(num);
// 		}
// 		sort(all(resueltos[i]));
// 	}


// 	vector<ll> movidos_0;
// 	vector<ll> movidos_1;
// 	for (ll i = 0; i < resueltos[2].size(); i++) {
// 		// primero mayor resuelto por 0
// 		auto it = lower_bound(all(resueltos[0]), resueltos[2][i]);
// 		ll resueltos_mayores_0 = resueltos[0].end() - it;
// 		ll resueltos_menores_0 = it - resueltos[0].begin();

// 		auto it_1 = lower_bound(all(resueltos[1]), resueltos[2][i]);
// 		ll resueltos_mayores_1 = resueltos[1].end() - it;
// 		ll resueltos_menores_1 = it - resueltos[1].begin();

// 		movidos_0.push_back(resueltos_menores_1 + i);
// 		movidos_1.push_back(resueltos_mayores_0 + )

// 	}
// 	return 0;
// }

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;
const int P = 3;

int N;
vector<int> who;
vector<int> prefix_sums[P];
vector<int> dp[P + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int K[P];
	N = 0;

	for (int p = 0; p < P; p++) {
		cin >> K[p];
		N += K[p];
	}

	who.assign(N, -1);

	for (int p = 0; p < P; p++)
		for (int k = 0; k < K[p]; k++) {
			int a;
			cin >> a;
			a--;
			who[a] = p;
		}

	for (int p = 0; p < P; p++) {
		prefix_sums[p].assign(N + 1, 0);

		for (int i = 0; i < N; i++)
			prefix_sums[p][i + 1] = prefix_sums[p][i] + (who[i] == p ? 1 : 0);
	}

	dp[P].assign(N + 1, INF);
	dp[P][N] = 0;

	for (int p = P - 1; p >= 0; p--) {
		dp[p].assign(N + 1, INF);
		dp[p][N] = 0;
		int minimum = INF;

		for (int i = N; i >= 0; i--) {
			int cant_problemas_anteriores = i;
			int cant_problemas_mios_anteriores = prefix_sums[p][i];
			int problemas_no_mios_anteriores = cant_problemas_anteriores - cant_problemas_mios_anteriores;
			// minimum es siempre los problemas que no son míos para p = 2.
			minimum = min(minimum, problemas_no_mios_anteriores + dp[p + 1][i]);

			if (i < N) {
				dp[p][i] = minimum - cant_problemas_anteriores + cant_problemas_mios_anteriores;
			}
		}
	}

	// dp[0][0] es la cantidad mínima de cambios de ownership
	// para poder hacer que estén ordenados.
	// El primer cero es por la persona 0.
	// El segundo es por el problema 0.
	// Ordenamos desde la última persona a la primera.
	cout << dp[0][0] << '\n';
}