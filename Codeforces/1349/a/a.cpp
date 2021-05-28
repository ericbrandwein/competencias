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

const int MAX_NUM = 200'000;

vec<int> sieve(int n) {
	vec<int> primes;
	vec<bool> possible(n + 1, true);
	for (int i = 2; i <= n; i++) {
		if (possible[i]) {
			for (int j = i + i; j <= n; j += i) {
				possible[j] = false;
			}
			primes.push_back(i);
		}
	}
	return primes;
}

map<int,int> factorize(int n, vec<int>& primes) { // O(sqrt(n)) ~= 450
	int i = 0;
	int d = primes[i];
	map<int,int> factors;
	while (n > 1 && d*d <= n) {
		while (n % d == 0) {
			factors[d]++;
			n /= d;
		}
		i++;
		d = primes[i];
	}

	if (n > 1) factors[n]++;
	return factors;
}


int main() {
	IOS;

	int n;
	cin >> n;
	vec<int> a(n);
	forn (i) cin >> a[i];

	vec<int> primes = sieve(MAX_NUM);
	map<int, vec<int>> cants;
	forn (i) {
		map<int, int> factors = factorize(a[i], primes);
		for (pair<int,int> factor : factors) {
			int prime = factor.first;
			int cant = factor.second;
			cants[prime].push_back(cant);
		}
	}

	ll total = 1;
	for (const pair<int,vec<int>>& prime : cants) {
		ll min_cant = LONG_LONG_MAX;
		ll second_min = LONG_LONG_MAX;
		if (prime.second.size() <= n - 2) {
			second_min = 0;
		} else {
			if (prime.second.size() <= n - 1) {
				min_cant = 0;
			}
			for (int cant : prime.second) {
				if (cant < min_cant) {
					second_min = min_cant;
					min_cant = cant;
				} else if (cant < second_min) {
					second_min = cant;
				}
			}
		}

		for (ll i = 0; i < second_min; i++) {
			total *= prime.first;
		}
	}

	cout << total << endl;



	return 0;
}
