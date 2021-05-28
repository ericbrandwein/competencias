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
	ll rows, cols;
	cin >> rows >> cols;

	vector<vector<int>> matrix(rows, vector<int>(cols));
	for (ll row = 0; row < rows; row++) {
		for (ll col = 0; col < cols; col++) {
			cin >>matrix[row][col];
		}
	}

	ll total = 0;
	if (rows > cols) {
		for (ll row = 0; row < rows; row++) {
			ll zeroes = 0;
			ll ones = 0;
			ll other_row = rows - row - 1;
			for (ll moved = 0; moved < cols && row - moved > -1; moved++) {
				if (matrix[row - moved][moved] == 1) {
					ones++;
				} else {
					zeroes++;
				}
				if (matrix[other_row + moved][cols - moved - 1] == 1) {
					ones++;
				} else {
					zeroes++;
				}

			}

			if (row - cols + 1 >= other_row) {
				break;
			} else {
				total += min(zeroes, ones);
			}
		}
	} else {
		for (ll col = 0; col < cols; col++) {
			ll zeroes = 0;
			ll ones = 0;
			ll other_col = cols - col - 1;
			for (ll moved = 0; moved < rows && col - moved > -1; moved++) {
				if (matrix[moved][col - moved] == 1) {
					ones++;
				} else {
					zeroes++;
				}
				if (matrix[rows - moved - 1][other_col + moved] == 1) {
					ones++;
				} else {
					zeroes++;
				}

			}

			if (col - rows + 1 >= other_col) {
				break;
			} else {
				total += min(zeroes, ones);
			}
		}
	}

	cout << total << endl;

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
