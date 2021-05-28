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


	ll t;
	cin >> t;

	fore (i, 0, t) {
		ll n;
		ll heads;
		cin >> n >> heads;

		ll biggest = -1;
		ll most = -1;
		forn (j) {
			ll di, hi;
			cin >> di >> hi;
			if (di > biggest) {
				biggest = di;
			}
			if (di - hi > most) {
				most = di - hi;
			}
		}


		if (biggest < heads && most <= 0) {
			cout << -1 << endl;
			continue;
		}

		ll count = 1;
		heads -= biggest;
		if (heads > 0) {
			if (heads % most > 0) {
				count++;
			}
			count += heads / most;
		}

		cout << count << endl;
	}

	return 0;
}
