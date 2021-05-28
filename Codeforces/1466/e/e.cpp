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

ll mulmod(ll a, ll b, ll mod) {
	ll res = 0;
	while (b) {
		if (b & 1) {
			res = (res + a) % mod;
		}
		a = a * 2 % mod;
		b >>= 1;
	}
	return res;
}


void solve() {
	ll n;
	cin >> n;
	vec<ll> nums(n);
	vec<bitset<60>> bits(n);
	vec<ll> cuantos(60,0);
	forn (i) {
		cin >> nums[i];
		bits[i] = bitset<60>(nums[i]);
		for (ll j = 0; j < 60; j++) {
			cuantos[j] += bits[i][j];
		}
	}

	ll res = 0;
	vec<ll> sumas(60);
	ll pot = 1;
	for (ll j = 0; j < 60; j++) {
		sumas[j] = mulmod(cuantos[j], pot, MOD);
		pot <<= 1;
	}

	forn (i) {
		ll suma = mulmod(nums[i], n, MOD);
		for (ll j = 0; j < 60; j++) {
			if (!bits[i][j]) {
				suma += sumas[j];
				suma %= MOD;
			}
		}
		pot = 1;
		ll izq = 0;
		for (ll j = 0; j < 60; j++) {
			if (bits[i][j]) {
				izq += sumas[j];
				izq %= MOD;
			}
			pot <<= 1;
		}
		res += mulmod(izq, suma, MOD);
		res %= MOD;
	}

	cout << res << endl;


}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}
