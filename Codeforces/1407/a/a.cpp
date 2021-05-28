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
	ll n;
	cin >> n;
	vec<ll> a(n);

	ll ones = 0;
	forn (i) {
		cin >> a[i];
		if (a[i]) {
			ones++;
		}
	}

	vec<ll> res;
	if (ones > n / 2) {
		res = vec<ll>(n/2, 1);
		if ((n / 2) % 2 == 1) {
			res.push_back(1);
		}
	} else {
		res = vec<ll>(n/2, 0);
	}

	cout << res.size() << endl;
	fore (i, 0, res.size()) {
		cout << res[i] << " ";
	}
	cout << endl;
}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
