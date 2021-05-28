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

	ll a,b,c,d;
	cin >> a >> b >> c >> d;
	ll res = 0;
	for (ll z = c; z <= d; z++) {
		ll y = c;
		ll necesito = z + 1 - y;
		if (necesito < a) {
			ll cant_full = min(a - necesito, c - b + 1);
			res += cant_full * (b-a+1);
			y -= cant_full;
			necesito += cant_full;
		}
		ll x = max(necesito, a);

		if (y >= b && x <= b) {
			ll mayores = b - x + 1;
			res += mayores*(mayores+1)/2;
			ll menores = y - b + 1;
			ll restados = max(0LL,mayores - menores);
			res -= restados*(restados+1) / 2;
		}
	}
	cout << res << endl;

}
