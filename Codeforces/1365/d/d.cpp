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

bool replace(vector<vector<char>>& matrix, ll row, ll col) {
	if (matrix[row][col] == 'G') {
		return false;
	} else if(matrix[row][col] == '.') {
		matrix[row][col] = '#';
	}
	return true;
}

bool replace_surrounding(vector<vector<char>>& matrix, ll row, ll col) {
	if (row > 0) {
		if (!replace(matrix, row - 1, col)) {
			return false;
		}
	}
	if (col > 0) {
		if (!replace(matrix, row, col - 1)) {
			return false;
		}
	}
	if (row < matrix.size() - 1) {
		if (!replace(matrix, row + 1, col)) {
			return false;
		}
	}
	if (col < matrix[0].size() - 1) {
		if (!replace(matrix, row, col + 1)) {
			return false;
		}
	}
	return true;
}


void solve() {
	ll n, m;
	cin >> n >> m;

	vector<vector<char>> matrix(n, vector<char>(m));
	forn (i) {
		fore (j ,0 ,m) {
			cin >> matrix[i][j];
		}
	}

	forn (i) {
		fore (j, 0, m) {
			if (matrix[i][j] == 'B') {
				if (!replace_surrounding(matrix, i, j)) {
					cout << "No" << endl;
					return;
				}
			}
		}
	}

	vector<vector<bool>> reached(n, vector<bool>(m, false));
	stack<pair<ll, ll>> positions;
	positions.push({n - 1, m - 1});
	while (!positions.empty()) {
		pair<ll, ll> next_pos = positions.top();
		positions.pop();
		if (matrix[next_pos.first][next_pos.second] != '#' && matrix[next_pos.first][next_pos.second] != 'B' && !reached[next_pos.first][next_pos.second]) {
			if (next_pos.first > 0) {
				positions.push({next_pos.first - 1, next_pos.second});
			}
			if (next_pos.first < n - 1) {
				positions.push({next_pos.first + 1, next_pos.second});
			}
			if (next_pos.second > 0) {
				positions.push({next_pos.first, next_pos.second - 1});
			}
			if (next_pos.second < m - 1) {
				positions.push({next_pos.first, next_pos.second + 1});
			}
		}

		reached[next_pos.first][next_pos.second] = true;
	}

	forn (i) {
		fore (j, 0, m) {
			if (matrix[i][j] == 'G' && !reached[i][j]) {
				cout << "No" << endl;
				return;
			}
		}
	}

	cout << "Yes" << endl;
}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) {
		solve();
	}
 	return 0;
}
