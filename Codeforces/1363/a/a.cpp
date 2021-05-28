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

		vector<ll> nums(n);
		ll odds = 0;
		forn (i) {
			cin >> nums[i];
			if (nums[i] % 2 == 1) {
				odds++;
			}
		}

		if (n == x) {
			if (odds % 2 == 0) {
				cout << "No" << endl;
			} else {
				cout << "Yes" << endl;
			}
		} else if (odds == 0) {
			cout << "No" << endl;
		} else if (odds != n) {
			cout << "Yes" << endl;
		} else if (x % 2 == 0) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
		}


	}

	return 0;
}
