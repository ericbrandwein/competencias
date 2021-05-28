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



vec<ll> get_primes() {
	ll max_num = 100001;
	vec<ll> primos;
	vec<bool> criba(max_num, true);
	for (ll i = 2; i < max_num; i++) {
		if (criba[i]) {
			primos.push_back(i);
			for (ll j = i; j < max_num; j+= i) {
				criba[j] = false;
			}
		}
	}
	return primos;
}


int main() {
	IOS;

	vec<ll> primes = get_primes();

	ll t;
	cin >> t;
	while (t--) {
		ll d;
		cin >> d;
		// primero mayor o igual
		auto it = lower_bound(all(primes), d + 1);
		ll prim_primo = *it;
		auto it2 = lower_bound(it, primes.end(), prim_primo + d);
		ll seg_primo = *it2;
		cout << prim_primo * seg_primo << endl;
	}
}
