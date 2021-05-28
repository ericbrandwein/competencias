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

void solve() {
	vec<string> sudoku(9);
	fore (i, 0, 9) {
		cin >> sudoku[i];
	}

	for (ll row = 0; row < 3; row++) {
		for (ll cell = 0; cell < 3; cell++) {
			ll row_changed = row * 3 + cell;
			ll col_changed = cell * 3 + row;
			sudoku[row_changed][col_changed]++;
			if (sudoku[row_changed][col_changed] > '9') {
				sudoku[row_changed][col_changed] = '1';
			}
		}
	}

	fore (i, 0, 9) {
		cout << sudoku[i] << endl;
	}
}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
