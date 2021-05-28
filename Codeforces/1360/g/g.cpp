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

void solve(ll rows, ll cols, ll ones_per_row, ll ones_per_col) {
	if (ones_per_row * rows != ones_per_col * cols) {
		cout << "NO" << endl;
		return;
	}

	vector<vector<int>> matrix(rows, vector<int>(cols, 0));
	for (ll starting_row = 0; starting_row; starting_row += ones_per_col)



}


int main() {
	IOS;

	ll t;
	cin >> t;
	for (ll i = 0; i < t; i++) {
		ll rows, cols;
		cin >> rows >> cols;
		ll ones_per_row, ones_per_col;
		cin >> ones_per_col >> ones_per_row;
		solve(rows, cols, ones_per_row, ones_per_col);
	}


	return 0;
}
