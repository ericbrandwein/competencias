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
	while (t--) {
		ll n, x;
		cin >> n >> x;

		ll total_sum = 0;
		bool all_divisible = true;
		ll bad_elements_beggining = 0;
		ll bad_elements_end = 0;
		vector<ll> a(n);
		forn (i) {
			cin >> a[i];
			total_sum += a[i];
			if (a[i] % x != 0) {
				all_divisible = false;
				bad_elements_end++;
			} else {
				bad_elements_end = 0;
			}
		}

		if (all_divisible) {
			cout << -1 << endl;
		} else if (total_sum % x == 0) {
			cout << n - 1 << endl;
		} else {
			cout << n << endl;
		}


	}


	return 0;
}
