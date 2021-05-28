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

ll max_dress_for(
	vec<vec<ll>>& max_dresses,
	vec<string>& grilla,
	vec<vec<ll>>& iguales_diag_prin,
	vec<vec<ll>>& iguales_diag_sec,
	ll row, ll col
) {
	ll max_dress = 1;
	if (col > 0 && grilla[row][col - 1] == grilla[row][col]) {
		ll prev_max_dress = max_dresses[row][col-1];
		ll max_curr_dress = min(
			iguales_diag_prin[row][col], iguales_diag_sec[row][col]
		);
		max_dress = min(max_curr_dress, prev_max_dress);
		if (max_curr_dress > prev_max_dress) {
			ll new_dress_len = prev_max_dress+ 1;
			ll len_abajo = iguales_diag_prin[row + new_dress_len - 1][col - new_dress_len + 1];
			ll len_arriba = iguales_diag_sec[row - new_dress_len + 1][col - new_dress_len + 1];
			if (min(len_arriba, len_abajo) >= new_dress_len) {
				max_dress = new_dress_len;
			}
		}
	}
	return max_dress;
}

int main() {
	IOS;

	ll n, m;
	cin >> n >> m;
	vec<string> grilla(n);
	forn (i) {
		cin >> grilla[i];
	}

	vec<vec<ll>> iguales_diag_sec(n, vec<ll>(m, 1));
	for (ll diag = 0; diag <= n + m - 2; diag++) {
		for (ll row = min(n - 2, diag); row >= 0; row--) {
			ll col = diag - row;
			if (col > 0 && col < m) {
				ll prev_row = row + 1;
				ll prev_col = col - 1;
				if (grilla[prev_row][prev_col] == grilla[row][col]) {
					iguales_diag_sec[row][col] +=
						iguales_diag_sec[prev_row][prev_col];
				}
			}
		}
	}

	vec<vec<ll>> iguales_diag_prin(n, vec<ll>(m, 1));
	for (ll diag = 0; diag <= n + m - 2; diag++) {
		for (ll col = 0; col <= diag && col < m; col++) {
			ll row = n - diag + col - 1;
			if (row > 0 && col > 0) {
				ll prev_row = row - 1;
				ll prev_col = col - 1;
				if (grilla[prev_row][prev_col] == grilla[row][col]) {
					iguales_diag_prin[row][col] +=
						iguales_diag_prin[prev_row][prev_col];
				}
			}
		}
	}


	ll total = 0;
	vec<vec<ll>> max_dress(n, vec<ll>(m, 1));
	for (ll row = 0; row < n; row++) {
		for (ll col = 0; col < m; col++) {
			ll val = max_dress_for(
				max_dress, grilla, iguales_diag_prin, iguales_diag_sec,
				row, col
			);
			max_dress[row][col] = val;
			total += val;
		}
	}

	cout << total << endl;

	return 0;
}
