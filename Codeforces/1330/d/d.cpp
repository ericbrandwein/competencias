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

ll largest_bit(ll num) {
	ll largest = 0;
	while (num > 0) {
		num /= 2;
		largest++;
	}
	return largest;
}

void solve() {
	ll d, mod;
	cin >> d >> mod;
	ll bits = largest_bit(d);
	ll sobran = d - (1 << (bits - 1)) + 1;
	ll pot = 1;
	ll res = 1;
	for (ll i = 0; i < bits; i++) {
		if (i == bits - 1) {
			res *= (sobran + 1);
			res %= mod;
		} else {
			res *= (pot + 1);
			res %= mod;
			pot *= 2;
			pot %= mod;
		}
	}
	cout << (res + mod -  1) % mod << endl;
}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();
}
