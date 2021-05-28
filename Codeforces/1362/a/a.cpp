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
	ll a, b;
	cin >> a >> b;
	ll mini = min(a, b);
	ll maxi = max(a, b);

	if (maxi % mini != 0) {
		cout << -1 << endl;
		return;
	}

	ll missing = maxi / mini;

	ll two_amount = 0;
	while (missing != 1) {
		if (missing % 2 != 0) {
			cout << -1 << endl;
			return;
		}
		missing /= 2;
		two_amount++;
	}

	ll changes = two_amount / 3;
	if (two_amount % 3 != 0) {
		changes++;
	}

	cout << changes << endl;
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
