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

bool is_prime(ll n) {
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

ll prime_before(ll n) {
	while (!is_prime(n)) {
		n--;
	}
	return n;
}

ll prime_after(ll n) {
	while (!is_prime(n)) n++;
	return n;
}

void solve() {
	ll z;
	cin >> z;

	ll root = sqrt(z);
	ll first = prime_before(root);
	ll second = prime_after(first + 1);
	if (first * second > z) {
		second = prime_before(first - 1);
	}

	cout << first * second;

}


int main() {
	IOS;

	ll t;
	cin >> t;
	fore (i, 0, t) {
		cout << "Case #" << i + 1 << ": ";
		solve();
		cout << endl;
	}


}
