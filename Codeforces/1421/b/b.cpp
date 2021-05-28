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
	ll n;
	cin >> n;
	vec<string> grid(n);
	forn (i) {
		cin >> grid[i];
	}

	ll ones_arriba = (grid[0][1] - '0') + (grid[1][0] - '0');
	ll ones_abajo = (grid[n-1][n - 2] - '0') + (grid[n-2][n-1] - '0');

	vec<pair<int,int>> res;
	vec<pair<int,int>> a_cero;
	vec<pair<int,int>> a_uno;
	if (ones_arriba >= ones_abajo) {
		a_uno.push_back({0, 1});
		a_uno.push_back({1, 0});
		a_cero.push_back({n-1, n-2});
		a_cero.push_back({n-2, n-1});
	} else {
		a_cero.push_back({0, 1});
		a_cero.push_back({1, 0});
		a_uno.push_back({n-1, n-2});
		a_uno.push_back({n-2, n-1});
	}

	for (pair<int,int> pos : a_cero) {
		if (grid[pos.first][pos.second] != '0') {
			res.push_back(pos);
		}
	}

	for (pair<int,int> pos : a_uno) {
		if (grid[pos.first][pos.second] != '1') {
			res.push_back(pos);
		}
	}

	cout << res.size() << endl;
	for (pair<int,int> par : res) {
		cout << par.first + 1 << " " << par.second + 1 << endl;
	}

}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}
