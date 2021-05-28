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

#define MOD 1000000007LL

ll mulmod(ll a, ll b) {
	ll res = 0;
	while (b) {
		if (b & 1) {
			res = (res + a) % MOD;
		}
		a = a * 2 % MOD;
		b >>= 1;
	}
	return res;
}

ll powmod(ll base, ll exp) {
	ll res = 1;
	while (exp) {
		if (exp & 1) {
			res = mulmod(res, base);
		}
		base = mulmod(base, base);
		exp >>= 1;		
	}
	return res;
}

int main() {
	IOS;

	ll n, m;
	cin >> n >> m;
	ll ans = powmod(2, m) - 1;
	ans = powmod(ans, n);
	cout << ans << endl;

	return 0;
}
