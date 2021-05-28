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
	ll x, y;
	cin >> x >> y;
	vec<int> costs(6);
	fore (i, 0 , 6) {
		cin >> costs[i];
	}

	fore (i, 0, 6) {
		ll sig = (i + 1) % 6;
		ll ant = (i + 5) % 6;
		costs[i] = min(costs[i], costs[sig] + costs[ant]);
	}

	ll suma = 0;
	ll diag = 0;
	if ((x < 0) == (y < 0)) {
		diag = min(abs(x), abs(y));
	}
	if (x < 0) {
		suma += costs[3] * diag;
	} else {
		suma += costs[0] * diag;
	}

	if (x < 0) {
		x += diag;
		y += diag;
	} else {
		x -= diag;
		y -= diag;
	}

	if (y < 0) {
		suma += abs(y) * costs[4];
	} else {
		suma += abs(y) * costs[1];
	}

	if (x > 0) {
		suma += abs(x) * costs[5];
	} else {
		suma += abs(x) * costs[2];
	}

	cout << suma << endl;

}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}
