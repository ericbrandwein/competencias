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

	vec<ll> a(n);
	bool hay_k = false;
	bool se_puede = false;
	forn (i) {
		cin >> a[i];
		if (a[i] == k) hay_k = true;
		if (a[i] >= k) {
			if (i > 0 && a[i - 1] >= k || i > 1 && a[i-2] >= k) {
				se_puede = true;
			}
		}
	}

	if (hay_k && se_puede || hay_k && a.size() == 1) {
		cout << "yes" << endl;
	} else {
		cout << "no" << endl;
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
