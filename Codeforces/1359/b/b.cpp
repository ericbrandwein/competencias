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
	ll rows, cols, price1, price2;
	cin >> rows >> cols >> price1 >> price2;

	price2 = min(price1 * 2, price2);
	ll total_price = 0;

	vector<string> matrix(rows);
	fore (i, 0, rows) {
		cin >> matrix[i];
	}

	for (string& row : matrix) {
		ll starting = 0;
		fore (i, 0, row.size()) {
			if (row[i] == '*') {
				ll length = i - starting;
				total_price += length / 2 * price2;
				if (length % 2 == 1) {
					total_price += price1;
				}
				starting = i + 1;
			}
		}
		ll length = cols - starting;
		total_price += length / 2 * price2;
		if (length % 2 == 1) {
			total_price += price1;
		}
	}

	cout << total_price << endl;



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
