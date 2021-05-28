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

void visit_adj(vec<vec<bool>>& visited, vec<string>& grid, ll row, ll col) {
	if (
		row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() &&
		grid[row][col] == '#' && !visited[row][col]
	) {
		visited[row][col] = true;
		visit_adj(visited, grid, row - 1, col);
		visit_adj(visited, grid, row + 1, col);
		visit_adj(visited, grid, row, col - 1);
		visit_adj(visited, grid, row, col + 1);
	}
}

int main() {
	IOS;

	ll n, m;
	cin >> n >> m;
	vec<string> grid(n);
	forn (i) cin >> grid[i];

	bool row_clear = false;
	forn (i) {
		bool all_dots = true;
		bool cycled = false;
		fore (j, 0, m) {
			if (grid[i][j] == '#') {
				all_dots = false;
				if (cycled) {
					cout << -1 << endl;
					return 0;
				}
			} else if (!all_dots) {
				cycled = true;
			}
		}
		row_clear |= all_dots;
	}

	bool col_clear = false;
	fore (j, 0, m) {
		bool all_dots = true;
		bool cycled = false;
		forn (i) {
			if (grid[i][j] == '#') {
				all_dots = false;
				if (cycled) {
					cout << -1 << endl;
					return 0;
				}
			} else if (!all_dots) {
				cycled = true;
			}
		}
		col_clear |= all_dots;
	}

	if (col_clear != row_clear) {
		cout << -1 << endl;
		return 0;
	}

	vec<vec<bool>> visited(n, vec<bool>(m, false));

	ll total = 0;
	forn (i) {
		fore (j, 0, m) {
			if (grid[i][j] == '#' && !visited[i][j]) {
				total++;
				visit_adj(visited, grid, i, j);
			}
		}
	}

	cout << total << endl;


	return 0;
}
