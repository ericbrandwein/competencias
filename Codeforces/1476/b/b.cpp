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
	vec<ll> p(n);
	forn (i) cin >> p[i];
	ll suma = p[0];
	ll res = 0;
	fore (i, 1, n) {
		ll falta = (p[i] * 100 - (suma * k));
		if (falta > 0) {
			suma += falta / k;
			res += falta / k;
			if (falta % k != 0){
				suma++;
				res++;
			}
		}
		suma += p[i];
	}

	cout << res << endl;

}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}
