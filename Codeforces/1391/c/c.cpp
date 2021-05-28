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


ll powmod(ll base, ll exp, ll mod) {
	ll res = 1;
	while (exp) {
		if (exp & 1) {
			res = res * base % mod;
		}
		base = base * base % mod;
		exp >>= 1;
	}
	return res;
}

/**
 * El mod tiene que ser primo.
 * Se basa en fermatito.
 */
ll inverso_mod(ll num, ll mod) {
	return powmod(num, mod - 2ll, mod);
}


int main() {
	IOS;

	ll n;
	cin >> n;
	ll total = 1;
	vector<ll> factoriales(n + 1);
	vector<ll> inversos(n + 1, 1);
	for (ll i = 1; i <= n; i++) {
		total *= i;
		total %= MOD;
		factoriales[i] = total;
		inversos[i] = inverso_mod(total, MOD);
	}

	for (ll i = 0; i < n; i++) {
		ll val = factoriales[n - 1] * inversos[i];
		val %= MOD;
		val *= inversos[n - 1 - i];
		val %= MOD;
		total -= val;
		total %= MOD;
		if (total < 0) total += MOD;
	}

	cout << total << endl;


	return 0;
}
