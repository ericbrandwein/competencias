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

ll chopped(vector<vec<bool>>& trees, ll row, ll col, ll height, ll width) {
	ll rows = trees.size();
	ll cols = trees[0].size();

	if (row + height <= rows && col + width <= cols) {
		ll chopped = 0;
		for (ll i = row; i < row + height; i++) {
			for (ll j = col; j < col + width; j++) {
				if (trees[i][j]) chopped++;
			}
		}
		return chopped;
	} else {
		return LONG_LONG_MAX;
	}

}

ll chopped_both(vector<vec<bool>>& trees, ll x, ll y, ll a, ll b) {
	return min(chopped(trees, x, y, a, b), chopped(trees, x, y, b, a));
}


int main() {
	IOS;


	ll n, m;
	cin >> n >> m;
	vector<vector<bool>> trees(n, vector<bool>(m, false));
	forn (i) {
		fore (j, 0, m) {
			ll tree;
			cin >> tree;
			trees[i][j] = tree;
		}
	}

	ll a, b;
	cin >> a >> b;

	ll min_chopped = LONG_LONG_MAX;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			min_chopped = min(min_chopped, chopped_both(trees, i, j, a, b));
		}
	}

	cout << min_chopped << endl;



	return 0;
}
