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

vec<vec<ll>> calculate_first_changes(vec<string>& grid) {
	ll n = grid.size();
	ll m = grid[0].size();
	vec<vec<ll>> first_changes(n, vec<ll>(m, -1));
	queue<pair<ll,ll>> next;
	for (ll row = 0; row < n; row++) {
		for (ll col = 0; col < m; col++) {
			if (
				row > 0 && grid[row-1][col] == grid[row][col] ||
				row < n - 1 && grid[row+1][col] == grid[row][col] ||
				col > 0 && grid[row][col - 1] == grid[row][col] ||
				col < m - 1 && grid[row][col + 1] == grid[row][col]
			) {
				next.push({row, col});
				first_changes[row][col] = 1;
			}
		}
	}

	while (!next.empty()) {
		pair<ll,ll> curr = next.front();
		next.pop();
		ll row = curr.first;
		ll col = curr.second;
		if (row > 0 && first_changes[row - 1][col] == -1) {
			first_changes[row-1][col] = first_changes[row][col] + 1;
			next.push({row-1, col});
		}
		if (row < n-1 && first_changes[row + 1][col] == -1) {
			first_changes[row+1][col] = first_changes[row][col] + 1;
			next.push({row+1, col});
		}
		if (col > 0 && first_changes[row][col - 1] == -1) {
			first_changes[row][col-1] = first_changes[row][col] + 1;
			next.push({row, col-1});
		}
		if (col < m- 1 && first_changes[row][col + 1] == -1) {
			first_changes[row][col+1] = first_changes[row][col] + 1;
			next.push({row, col+1});
		}
	}

	return first_changes;
}

int main() {
	IOS;

	ll n, m, t;
	cin >> n >> m >> t;
	vec<string> grid(n);

	forn (i) cin >> grid[i];

	vec<vec<ll>> first_changes = calculate_first_changes(grid);

	while (t--) {
		ll row, col, iteration;
		cin >> row >> col >> iteration;
		row--;
		col--;
		ll changes = max(0ll, iteration - first_changes[row][col] + 1);
		if (first_changes[row][col] == -1) {
			cout << grid[row][col] << endl;
		} else {
			cout << (grid[row][col] - '0' + changes) % 2 << endl;
		}
	}

	return 0;
}
