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

	ll n, mod;
	cin >> n >> mod;

	vector<ll> a(n), b(n);
	forn (i) {
		cin >> a[i];
	}
	forn (i) {
		cin >> b[i];
	}

	multiset<ll> ordered_b(all(b));

	ll min_x = LONG_LONG_MAX;
	ll selected_b = b[0];
	forn (i) {
		ll selected_a = a[i];

		ll to_sum = selected_b - selected_a;
		if (to_sum < 0) {
			to_sum += mod;
		}

		if (to_sum < min_x) {
			multiset<ll> remaining = ordered_b;
			forn (j) {
				auto it = remaining.find((a[j] + to_sum) % mod);
				if (it != remaining.end()) {
					remaining.erase(it);
				}
			}
			if (remaining.empty()) {
				min_x = to_sum;
			}
		}
	}

	cout << min_x << endl;

	return 0;
}
