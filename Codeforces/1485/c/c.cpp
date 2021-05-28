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
	ll x, y;
	cin >> x >> y;

	if (x == 1) {
		cout << 0 << endl;
		return;
	}

	ll res = 0;
	ll b = 2;
	while (b <= y+1 && b <= x) {
		if (b * (b-2) <= x) {
			res += b -2;
			b++;
		} else {
			ll max_k = x / b;
			ll prox_b = x+1;
			prox_b = x / max_k + 1;
			prox_b = min(prox_b, y+2);

			res += max_k * (prox_b - b);
			b = prox_b;
		}
	}

	cout << res << endl;
}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}
