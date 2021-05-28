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

	ll n, m;
	cin >> n >> m;
	ll left_col = 1;
	ll right_col = m;
	while (right_col > left_col) {
		ll left_row = 1;
		ll right_row = n;
		cout << left_row <<" " << left_col << endl;
		for (ll i = 0; i < n-1; i++) {
			cout << right_row << " " <<  right_col << endl;
			left_row++;
			cout << left_row << " " <<  left_col<< endl;
			right_row--;
		}
		cout << right_row << " " << right_col<< endl;
		left_col++;
		right_col--;
	}
	if (left_col == right_col) {
		ll top_row = n;
		ll bottom_row = 2;
		cout << 1 << " " << left_col << endl;
		while (top_row > bottom_row) {
			cout << top_row << " "  << left_col  <<endl;
			top_row--;
			cout <<bottom_row << " " << left_col << endl;
			bottom_row++;
		}
		if (top_row == bottom_row) {
			cout  << top_row << " " << left_col << endl;
		}
	}




	return 0;
}
