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
	ll m, d, w;
	cin >> m >> d >> w;

	ll min_num = min(d, m);
	if ((d - 1) % w == 0) {
		cout << min_num * (min_num - 1) / 2 << endl;
	} else {
		ll g = __gcd(d - 1, w);
		w = w / g;
		ll div = min_num / w;
		ll resto = min_num % w;
		ll suma = ((div + 1) * div / 2) * (resto);
		suma += (div * (div - 1) / 2) * (w - resto);
		cout << suma << endl;
	}
}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
