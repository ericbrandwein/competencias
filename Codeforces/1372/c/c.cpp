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
	vector<ll> a(n);
	forn (i) {
		cin >> a[i];
	}
	ll first_diff = -1;
	for (ll i = 0; i < n; i++) {
		if (a[i] != i + 1) {
			first_diff = i;
			break;
		}
	}

	ll last_diff = n;
	for (ll i = n - 1; i >= 0; i--) {
		if (a[i] != i + 1) {
			last_diff = i;
			break;
		}
	}

	if (first_diff == -1) {
		cout << 0 << endl;
	} else {
		bool mid_eq = false;
		for (ll i = first_diff + 1; i < last_diff; i++) {
			if (a[i] == i + 1) mid_eq = true;
		}
		if (mid_eq) {
			cout << 2 << endl;
		} else {
			cout << 1 << endl;
		}
	}
}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
