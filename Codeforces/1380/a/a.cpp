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
	vector<ll> p(n);
	forn (i) cin >> p[i];

	ll first_low = -1;
	fore (i, 0, n - 1) {
		if (p[i] < p[i + 1]) {
			first_low = i;
			break;
		}
	}

	if (first_low == -1) {
		cout << "NO" << endl;
		return;
	}

	ll second_low = n;
	fore (i, first_low + 1, n - 1) {
		if (p[i] > p[i+1]) {
			second_low = i+1;
			break;
		}
	}

	if (second_low == n) {
		cout << "NO" << endl;
		return;
	}

	cout << "YES" << endl;
	cout << first_low+1 << " " << second_low << " " << second_low+1 << endl;

}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
