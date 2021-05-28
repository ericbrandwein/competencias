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
	string a, b;
	cin >> a >> b;

	vec<vec<ll>> amounts(2, vec<ll>('z' - 'a' + 1, 0));
	for (ll i = 0; i < n; i++) {
		amounts[0][a[i] - 'a']++;
		amounts[1][b[i] - 'a']++;
	}

	bool possible = true;
	for (ll i = 0; i < amounts[0].size(); i++) {
		ll queda = amounts[0][i] - amounts[1][i];
		if (queda < 0 || queda % k != 0) {
			possible = false;
			break;
		}
		if (i < amounts[0].size() - 1) {
			amounts[0][i+1] += queda;
		}
	}

	if (possible) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}
