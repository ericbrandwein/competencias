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

const ll MOD = 998244353;

ll powmod(ll base, ll exp, ll mod) {
	ll res = 1;
	while (exp) {
		if (exp & 1) {
			res = (res * base)% mod;
		}
		base = (base * base) % mod;
		exp >>= 1;
	}
	return res;
}

/**
 * El mod tiene que ser primo.
 * Se basa en fermatito.
 */
ll inverso_mod(ll num) {
	return powmod(num, MOD - 2ll, MOD);
}

ll factorial(ll num) {
	ll res = 1;
	fore (i, 1, num + 1) {
		res *= i;
		res %= MOD;
	}
	return res;
}

int main() {
	IOS;

	ll n;
	cin >> n;
	vec<ll> a(2*n);
	fore (i, 0, 2*n) cin >> a[i];
	sort(all(a));

	ll inverso = inverso_mod(factorial(n));
	ll combi = ((factorial(2*n) * inverso) % MOD) * inverso;
	combi %= MOD;

	ll suma = 0;
	for (ll i = 0; i < n; i++) {
		ll restado = a[i];
		suma -= restado;
		suma %= MOD;

		ll sumado = a[2*n - i - 1];
		suma += sumado;
		suma %= MOD;
	}

	cout << (suma * combi) % MOD << endl;

}
