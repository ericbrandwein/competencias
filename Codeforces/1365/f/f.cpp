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
	vector<ll> a(n), b(n);
	forn (i) {
		cin >> a[i];
	}
	forn (i) {
		cin >> b[i];
	}

	if (n % 2 == 1 && a[n / 2] != b[n / 2]) {
		cout << "No" << endl;
		return;
	}

	multiset<pair<ll, ll>> a_pairs, b_pairs;
	for (ll i = 0; i < n / 2; i++) {
		ll first = a[i];
		ll second = a[n - i - 1];
		a_pairs.insert({
			min(first, second),
			max(first, second)
		});
		first = b[i];
		second = b[n - i - 1];
		b_pairs.insert({
			min(first, second),
			max(first, second)
		});
	}

	if (a_pairs == b_pairs) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}



