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

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) {
		ll n, m;
		cin >> n >> m;

		vector<vector<int>> matrix(n, vector<int>(m, 0));
		fore (i, 0, n) {
			fore (j, 0, m) {
				cin >> matrix[i][j];
			}
		}

		ll free_rows = n;
		fore (i, 0, n) {
			fore (j, 0, m) {
				if (matrix[i][j]) {
					free_rows--;
					break;
				}
			}
		}

		ll free_cols = m;
		fore (i, 0, m) {
			fore (j, 0, n) {
				if (matrix[j][i]) {
					free_cols--;
					break;
				}
			}
		}

		ll min_free = min(free_cols, free_rows);
		min_free = max(0ll, min_free);

		if (min_free % 2 == 0) {
			cout << "Vivek" << endl;
		} else {
			cout << "Ashish" << endl;
		}

	}

	return 0;
}
