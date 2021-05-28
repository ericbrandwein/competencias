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
	ll n;
	cin >> n;
	vec<ll> a(n);
	forn (i) cin >> a[i];

	ll prev_gcd = 0;
	vec<ll> res(n);
	vec<bool> visited(n, false);
	forn (i) {
		ll best_j = -1;
		ll best_gcd = 1;
		forn (j) {
			if (!visited[j]) {
				ll curr_gcd = __gcd(prev_gcd, a[j]);
				if (best_j == -1 || curr_gcd > best_gcd) {
					best_j = j;
					best_gcd = curr_gcd;
				}
			}
		}

		res[i] = a[best_j];
		visited[best_j] = true;
		prev_gcd = __gcd(prev_gcd, a[best_j]);
	}

	forn (i) {
		cout << res[i] << " ";
	}
	cout << endl;

}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
