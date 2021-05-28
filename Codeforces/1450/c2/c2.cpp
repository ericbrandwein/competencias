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

const ll INF = 305*305;

struct Node {
	vec<vec<ll>> hor; // o, x
	vec<vec<ll>> ver;
	Node() : hor(2, vec<ll>(3)), ver(2, vec<ll>(3)) {}
};

void llenar_dp(vec<vec<Node>>& dp, ll row, ll col, vec<string>& rows) {
	string chars = "ox";
	for (ll c = 0; c < 2; c++) {
		char char_actual = chars[c];
		char otro_char = chars[(c + 1) % 2];
		Node& actual = dp[row][col];
		actual.hor[c][0] = INF;
		if (rows[row][col] == '.') {
			for (ll cant = 0; cant < 3; cant++) {

			}


		}
	}
}

void solve() {
	ll n;
	cin >> n;
	vec<string> rows(n);
	forn (i) cin >> rows[i];

	vec<vec<Node>> dp(n, vec<Node>(n, Node())); // [row][col]
	for (ll row = n - 1; row >= 0; row--) {
		for (ll col = n - 1; col >= 0; col--) {
			llenar_dp(dp, row, col, rows);
		}
	}


}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}
