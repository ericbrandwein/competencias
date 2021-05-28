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

map<ll, ll> factorize(ll n) {
	map<ll, ll> factors;
	ll prime = 2;
	ll orig = n;
	while (n > 1 && prime * prime <= orig) {
		while (n % prime == 0) {
			n /= prime;
			factors[prime]++;
		}
		prime++;
	}
	if (n > 1) {
		factors[n]++;
	}
	return factors;
}


int main() {
	IOS;

	ll n;
	cin >> n;
	map<ll, ll> factors = factorize(n);

	if (factors.empty()) {
		cout << "NO" << endl;
		return 0;
	}

	ll odds = 0;
	for (pair<ll, ll> elem : factors) {
		if (elem.second % 2 != 0) odds++;
	}

	if (odds > 1) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
	}

	return 0;
}
