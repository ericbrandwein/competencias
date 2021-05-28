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

	if (n <= 3) {
		cout<< -1 << endl;
		return;
	}

	vec<ll> res;
	ll start = 1;
	if (n % 2 == 0) {
		start = 2;
	}
	for (ll i = start; i <= n; i+= 2) {
		res.push_back(i);
	}

	res.push_back(res.back() - 3);
	res.push_back(res.back() + 2);
	ll next = res.back() - 4;
	while (next > 0) {
		res.push_back(next);
		next -= 2;
	}
	fore (i, 0, res.size()) {
		cout << res[i] << " ";
	}
	cout << endl;
}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
