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

bool is_prime(ll num) {
	for (ll i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}


void solve() {
	ll n;
	cin >> n;
	if (n == 1) {
		cout << "FastestFinger" << endl;
	} else if (n % 2 == 1 || n == 2) {
		cout << "Ashishgup" << endl;
	} else {
		ll divisions = 0;
		ll num = n;
		while (num % 2 == 0) {
			num /= 2;
			divisions++;
		}

		if (divisions > 1) {
			if (num > 1) {
				cout << "Ashishgup" << endl;
			} else {
				cout << "FastestFinger" << endl;
			}
		} else {
			// Hay que fijarse si num es primo.
			// Si num es primo, entonces Ashishgup tiene que dividir por él,
			// y gana FastestFinger.
			// Sino, gana Ashishgup.
			if (is_prime(num)) {
				cout << "FastestFinger" << endl;
			} else {
				cout << "Ashishgup" << endl;
			}
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
