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

void solve () {
	ll n;
	cin >> n;
	ll x, y;
	cin >> x >> y;
	vec<ll> res(n);

	if (y <= n) {
		forn (i) res[i] = i + 1;
	} else if (y - x < n) {
		for (ll i = n - 1; i >= 0; i--) {
			res[i] = y;
			y--;
		}
	} else {
		ll divisor = n - 1;
		for (;divisor > 1 && (y - x) % divisor != 0;divisor--);
		ll restado = (y-x) / divisor;
		ll curr = y;
		ll i = 0;
		for (; i < n && curr > 0; i++) {
			res[i] = curr;
			curr -= restado;
		}
		curr = y + restado;
		for (; i < n;i++) {
			res[i] = curr;
			curr += restado;
		}
	}

	forn (i)  {
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
