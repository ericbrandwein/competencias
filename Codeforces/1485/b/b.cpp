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

int main() {
	IOS;

	ll n, q, k;
	cin >> n >> q >> k;
	vec<ll> a(n);
	forn (i) cin >> a[i];

	vec<ll> diffs(n, 0);
	fore (i, 1, n) {
		diffs[i] = diffs[i-1] + 2*(a[i] - a[i-1] - 1);
	}

	fore (i, 0, q) {
		ll l ,r ;
		cin >> l >> r;
		l--;
		r--;
		if (l == r) {
			cout << k - 1 << endl;
		} else {
			ll res = 0;
			res += a[l] - 1;
			res += diffs[r] - diffs[l];
			res += k - a[r];
			cout << res << endl;
		}
	}

}
