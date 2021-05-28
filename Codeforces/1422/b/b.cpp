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

ll moves_to(vec<ll>& values, ll to) {
	ll moves = 0;
	for (ll elem: values) {
		moves += abs(to - elem);
	}
	return moves;
}


ll moves_for(ll row, ll col, vec<vec<ll>>& matrix) {
	ll n = matrix.size();
	ll m = matrix[0].size();
	if (m - col - 1 < col || n - row - 1 < row) return 0;
	vec<ll> values;
	values.push_back(matrix[row][col]);
	if (m-col-1 > col) {
		values.push_back(matrix[row][m-col-1]);
	}
	if (n-row-1 > row) {
		values.push_back(matrix[n - row-1][col]);

	}
	if (m-col-1 > col && n-row-1 > row) {
		values.push_back(matrix[n - row-1][m-col-1]);
	}
	sort(all(values));
	ll moves = LONG_LONG_MAX;
	for (ll i = 0; i < values.size(); i++) {
		moves = min(moves, moves_to(values, values[i]));
	}
	return moves;
}


void solve() {
	ll n, m;
	cin >> n >> m;
	vec<vec<ll>> matrix(n, vec<ll>(m));
	forn (i) {
		fore (j, 0, m) {
			cin >> matrix[i][j];
		}
	}

	ll moves = 0;
	for (ll row = 0; row <= n/2; row++) {
		for (ll col = 0; col <= m / 2; col++) {
			moves += moves_for(row, col, matrix);
		}
	}

	cout << moves << endl;


}


int main() {
	IOS;


	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
