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

ll disminuir(ll a, ll b, ll x, ll y, ll n) {
	ll restado = min(n, a - x);
	a -= restado;
	n -= restado;
	restado = min(n, b - y);
	b -= restado;
	return a*b;
}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) {
		ll a, b, x, y, n;
		cin >> a >> b >> x >> y >> n;

		cout << min(disminuir(a, b, x, y, n), disminuir(b,a,y,x,n)) << endl;
	}
	return 0;
}
