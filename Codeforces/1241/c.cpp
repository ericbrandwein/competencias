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

	ll q;
	cin >> q;
	while (q--) {
		ll n;
		cin >> n;
		vector<ll> p(n);
		for (ll i = 0;i<n;i++) {
			cin >> p[i];
			p[i] /= 100;
		}

		ll a, b;
		ll x, y;
		cin >> x>>a;
		cin >>y>>b;

		sort(all(p));
		ll k;
		cin >> k;

		vector<ll> acum(n + 1);
		acum[0] = 0;
		ll suma = 0;
		for (ll i = 1;i<=n;i++){
			suma += p[i - 1];
			acum[i] = suma;
		}

		ll amasb = b * (a / __gcd(a, b));

		bool fin = false;
		for (ll i = 1;i <= n && !fin;i++) {
			ll rec = 0;
			ll cant_amasb = i / amasb;
			ll por_amasb = acum[n] - acum[n - cant_amasb];
			rec += por_amasb * (x + y);

			ll ultimo = n - cant_amasb;
			ll canta = i / a - cant_amasb;
			ll cantb = i / b - cant_amasb;
			if (x > y) {
				ll por_a = acum[ultimo] - acum[ultimo - canta];
				rec += por_a * x;
				ultimo -= canta;
				ll por_b = acum[ultimo] - acum[ultimo - cantb];
				rec += por_b * y;
			} else {
				ll por_b = acum[ultimo] - acum[ultimo - cantb];
				rec += por_b * y;
				ultimo -= cantb;
				ll por_a = acum[ultimo] - acum[ultimo - canta];
				rec += por_a * x;
			}

			if (rec >= k) {
				cout << i << endl;
				fin = true;
			}
		}
		if (!fin) {
			cout << -1 << endl;
		}
	}
	return 0;
}
