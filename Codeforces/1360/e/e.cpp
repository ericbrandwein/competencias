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


string solve(vector<string>& polygon) {
	ll n = polygon.size();
	for (ll row = 0; row < n - 1; row++) {
		for (ll col = 0; col < n - 1; col++) {
			if (polygon[row][col] == '1') {
				if (polygon[row + 1][col] != '1' && polygon[row][col + 1] != '1') {
					return "NO";
				}
			}
		}
	}
	return "YES";
}

int main() {
	IOS;

	ll t;
	cin >> t;

	for (ll i =0; i < t; i++) {
		ll n;
		cin >> n;
		vector<string> polygon(n);

		for (ll row = 0; row < n; row++) {
			cin >> polygon[row];
		}

		cout << solve(polygon) << endl;
	}

	return 0;
}
