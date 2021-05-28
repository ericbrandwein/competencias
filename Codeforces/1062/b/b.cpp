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

map<ll, ll> get_primes(ll n) {
	ll old_n = n;
	ll d = 2;
	map<ll, ll> primes;
	while (n > 1 && d*d <= old_n) {
		while (n % d == 0) {
			n /= d;
			primes[d]++;
		}
		d++;
	}
	if (n > 1) primes[n]++;
	return primes;
}

ll next_pot_2(ll num, ll& cant) {
	ll res = 1;
	while (res < num) {
		res *= 2;
		cant++;
	}
	return res;
}

int main() {
	IOS;

	ll n;
	cin >> n;

	map<ll,ll> primes = get_primes(n);
	ll max_cant = 0;
	for (pair<ll,ll> prime : primes) {
		max_cant = max(max_cant, prime.second);
	}
	ll total = 0;
	ll cant = 0;
	max_cant = next_pot_2(max_cant, cant);
	total = cant;
	ll mult = 1;
	bool hay_dif = false;
	for (pair<ll,ll> prime : primes) {
		if (max_cant != prime.second) {
			hay_dif = true;
		}
		mult *= prime.first;
	}
	if (hay_dif) total++;

	cout << mult << " " << total << endl;


	return 0;
}
