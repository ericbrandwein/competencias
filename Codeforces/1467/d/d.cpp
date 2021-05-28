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

const ll MOD = 1e9 + 7;

int main() {
	IOS;

	ll n, k, q;
	cin >> n >> k >> q;
	vec<ll> a(n);
	forn (i) cin >> a[i];

	vec<vec<ll>> cant_secuencias(n, vec<ll>(k + 1, 0)); // [pos][pasos]
	for (ll i = 0; i < n; i++) {
		cant_secuencias[i][0] = 1;
	}
	for (ll paso = 1; paso <= k; paso++) {
		for (ll i = 0; i < n; i++) {
			if (i > 0) {
				cant_secuencias[i][paso] += cant_secuencias[i-1][paso-1];
				cant_secuencias[i][paso] %= MOD;
			}
			if (i < n-1) {
				cant_secuencias[i][paso] += cant_secuencias[i+1][paso-1];
				cant_secuencias[i][paso] %= MOD;
			}
		}
	}

	vec<ll> apariciones(n, 0);
	for (ll i = 0; i < n; i++) {
		for (ll orden = 0; orden <= k; orden++) {
			ll cant_llegan = cant_secuencias[i][orden];
			ll cant_salen = 0;
			if (orden < k) {
				if (i > 0) {
					cant_salen += cant_secuencias[i-1][k - orden - 1];
				}
				if (i < n-1) {
					cant_salen += cant_secuencias[i+1][k - orden - 1];
					cant_salen %= MOD;
				}
			} else {
				cant_salen = 1;
			}

			apariciones[i] += (cant_llegan * cant_salen) % MOD;
			apariciones[i] %= MOD;
		}
	}

	ll suma = 0;
	for (ll i = 0; i < n; i++) {
		suma += (apariciones[i] * a[i]) % MOD;
		suma %= MOD;
	}

	while (q--) {
		ll index, value;
		cin >> index >> value;
		index--;
		ll ant = a[index];
		a[index] = value;
		ll added = value - ant;
		suma += (apariciones[index] * added) % MOD;
		suma %= MOD;
		if (suma < 0) suma += MOD;
		cout << suma << endl;
	}

}
