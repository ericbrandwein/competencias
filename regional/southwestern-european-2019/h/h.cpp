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

ll s(ll n) {
	if (n == 0) return 1611516670;
	ll prev = s(n-1);
	cout << prev % 2<< endl;
	return (prev + (prev>>20) + 12345) % 1099511627776;
}

vec<ll> primes(ll n) {
	vec<ll> res;
	for (ll i = 2; i*i <= n; i++) {
		while (n % i == 0) {
			n/=i;
			cout << i << " ";
			res.push_back(i);
		}
	}
	if (n > 1) {
		cout << n << " ";
		res.push_back(n);
	}
	cout << endl;
	return res;
}

int main() {
	IOS;

	// cout << "Primeros: " << endl;
	// primes(1611516670);
	// cout << "Segundos: " << endl;
	// primes(12345);
	// cout << bitset<64>(1611516670)[21] << endl;
	// cout << bitset<64>(12345)[21] << endl;

	cout << s(100) % 2 << endl;
	return 0;
}
