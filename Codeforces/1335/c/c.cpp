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
	map<ll, ll> ocurr;
	ll max_ocurr = 0;
	forn (i) {
		cin >> a[i];
		ocurr[a[i]]++;
		max_ocurr = max(max_ocurr, ocurr[a[i]]);
	}

	ll diffs = ocurr.size();
	if (diffs < max_ocurr) {
		cout << diffs << endl;
	} else if (diffs == max_ocurr) {
		cout << max_ocurr - 1 << endl;
	} else {
		cout << max_ocurr << endl;
	}



}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
