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

ll biggest_spruce(vec<string>& rows, vec<vec<ll>>& asterisks_after, ll row, ll col) {
	ll n = rows.size();
	ll height;
	for (height = 0; height + row < n; height++) {
		ll curr_col = col - height;
		ll curr_row = row + height;
		if (curr_col < 0 || asterisks_after[curr_row][curr_col] < 2*height + 1) break;
	}
	return height;
}

void solve() {
	ll n, m;
	cin >> n >> m;
	vec<string> rows(n);
	forn (i) {
		cin >> rows[i];
	}
	vec<vec<ll>> asterisks_after(n, vec<ll>(m, 0));
	for (ll row = 0; row < n; row++) {
		for (ll col = m-1; col >= 0; col--) {
			if (rows[row][col] == '*') {
				asterisks_after[row][col]++;
				if (col < m - 1) {
					asterisks_after[row][col] += asterisks_after[row][col+1];
				}
			}
		}
	}

	ll total = 0;
	for (ll row = 0; row < n; row++) {
		for (ll col = 0; col < m; col++) {
			total += biggest_spruce(rows, asterisks_after, row, col);
		}
	}

	cout << total << endl;

}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();



}
