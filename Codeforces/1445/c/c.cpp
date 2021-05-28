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

map<ll,ll> factorize(ll n) {
	map<ll,ll> factors;
	ll prime = 2;
	while (prime * prime <= n) {
		while (n % prime == 0) {
			factors[prime]++;
			n/=prime;
		}
		prime++;
	}
	if (n > 1) factors[n]++;
	return factors;
}

ll pow(ll base, ll exponent) {
	ll res = 1;
	fore (i, 0, exponent) {
		res *= base;
	}
	return res;
}

ll amount_factor_in(ll n, ll factor) {
	ll amount = 0;
	while (n % factor == 0) {
		amount++;
		n /= factor;
	}
	return amount;
}

void solve() {
	ll p, q;
	cin >> p >> q;
	if (p % q != 0) {
		cout << p << endl;
	} else {
		map<ll,ll> factors_q = factorize(q);

		ll max_x = 1;
		for (pair<ll,ll> entry: factors_q) {
			ll factor = entry.first;
			ll remaining = entry.second - 1;
			ll removed = amount_factor_in(p, factor) - remaining;
			max_x = max(max_x, p / pow(factor, removed));
		}
		cout << max_x << endl;
	}
}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}
