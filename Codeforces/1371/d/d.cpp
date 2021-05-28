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
	ll n, k;
	cin >> n >> k;

	vector<vector<ll>> matrix(n, vector<ll>(n, 0));

	ll diff = 0;
	if (k % n != 0) {
		diff = 2;
	}

	cout << diff << endl;

	for (ll start_col = 0; k > 0; start_col++) {
		for (ll move = 0; move < n && k > 0; move++) {
			matrix[move][(start_col + move) % n] = 1;
			k--;
		}
	}

	for (ll row = 0; row < n; row++) {
		fore (col, 0, n) {
			cout << matrix[row][col];
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
