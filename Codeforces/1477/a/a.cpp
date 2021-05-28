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

void solve() {
	ll n, k;
	cin >> n >> k;
	ll g = 0;
	vec<ll> nums(n);
	forn (i) {
		cin >> nums[i];
		if (g == 0) g = nums[i];
		else g = __gcd(g, nums[i]);
	}

	if (k % g == 0) {

		forn (i) nums[i] /= g;
		k /= g;

		set<ll> restos;
		forn (i) {
			ll resto = nums[i] % k;
			restos.insert(resto);
		}
		for (ll resto: restos) {
			ll resto_doble = (2*resto) % k;
			if (restos.count(resto_doble) > 0) {
				cout << "YES" << endl;
				return;
			}
		}


		cout << "YES" << endl;
	}
	cout << "NO" << endl;
}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}
