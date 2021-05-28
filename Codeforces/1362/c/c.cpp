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

// changes[i] = differences when reaching 2^i
vector<ll> changes(61);

void build_changes() {
	changes[0] = 1;
	fore (i, 1, 61) {
		changes[i] = changes[i - 1] * 2 + 1;
	}
}

void solve() {
	ll n;
	cin >> n;

	ll changes_amount = 0;

	ll bit = 0;
	while (n >= 1) {
		if (n % 2 == 1) {
			changes_amount += changes[bit];
		}
		n /= 2;
		bit++;
	}

	cout << changes_amount << endl;
}


int main() {
	IOS;

	build_changes();

	ll t;
	cin >> t;
	while (t--) {
		solve();
	}


	return 0;
}
