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
	ll n, m;
	cin >> n >> m;
	vec<string> filas(n);
	forn (i) cin >> filas[i];

	vec<vec<ll>> ops;
	for (ll fila = 0; fila < n - 1; fila++) {
		for (ll col = 0; col < m - 1; col++) {
			if (filas[fila][col] == '1') {
				ops.push_back({fila, col, fila+1, col, fila+1, col+1});
				ops.push_back({fila, col, fila+1, col, fila, col+1});
				ops.push_back({fila, col, fila, col+1, fila+1, col+1});
			}
		}
	}
	for (ll col = 0; col < m - 1; col++) {
		ll fila = n-1;
		if (filas[fila][col] == '1') {
			ops.push_back({fila, col, fila, col + 1, fila-1, col+1});
			ops.push_back({fila, col, fila-1, col, fila, col+1});
			ops.push_back({fila, col, fila-1, col, fila-1, col+1});
		}
	}

	for (ll fila = 0; fila < n - 1; fila++) {
		ll col = n-1;
		if (filas[fila][col] == '1') {
			ops.push_back({fila, col, fila, col - 1, fila+1, col-1});
			ops.push_back({fila, col, fila, col-1, fila+1, col});
			ops.push_back({fila, col, fila+1, col, fila+1, col-1});
		}
	}
	if (filas[n-1][m-1] == '1') {
		ll fila = n-1;
		ll col = m-1;
		ops.push_back({fila, col, fila, col - 1, fila-1, col-1});
		ops.push_back({fila, col, fila, col-1, fila-1, col});
		ops.push_back({fila, col, fila-1, col, fila-1, col-1});
	}

	cout << ops.size() << endl;
	for (const vec<ll>& op : ops) {
		for (ll num : op) {
			cout << num +1 << " ";
		}
		cout << endl;
	}
}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
