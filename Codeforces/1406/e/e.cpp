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

ll opb(ll base) {
	cout << "B " << base << endl << flush;
	ll res;
	cin >> res;
	return res;
}

ll opa(ll base) {
	cout << "A " << base << endl << flush;
	ll res;
	cin >> res;
	return res;
}

vec<ll> criba(ll n) {
	vec<bool> is_prime(n + 1, true);
	vec<ll> primes;
	for (ll i = 2; i <= n; i++) {
		if (is_prime[i]) {
			primes.push_back(i);
			for (ll j = 2*i; j <= n ; j+=i) {
				is_prime[j] = false;
			}
		}
	}
	return primes;
}


void grid(ll n) {
	vec<ll> primes = criba(n);
	vec<bool> tachado(n + 1, false);
	tachado[1] = true;
	ll from = 0;
	ll to = primes.size() - 1;
	ll mid = -1;
	ll total = n;
	ll remaining = total;
	while (remaining == total && remaining > 1) {
		from = mid + 1;
		mid = (to + from) / 2;
		for (ll i = from; i <= mid; i++) {
			ll prime = primes[i];
			opb(prime);
			total--;
			for (ll j = prime*2; j<=n; j+= prime) {
				if (!tachado[j]) {
					total--;
					tachado[j] = true;
				}
			}
		}
		remaining = opa(1);
	}
	ll res = 1;
	if (remaining != 1) {
		// remaining > total, o sea que entre from y mid están nuestros
		// factores primos.
		for (ll i = from; i <= mid && res * i <= n; i++) {
			ll prime = primes[i];
			ll biggest = 1;
			for (ll pot = prime; pot <= n; pot*=prime) {
				ll amount = opa(pot);
				if (amount) {
					biggest = pot;
				} else {
					break;
				}
			}
			res *= biggest;
		}
	}

	cout << "C " << res << endl;
}


int main() {
	IOS;

	ll n;
	cin >> n;

	grid(n);
	return 0;
}
