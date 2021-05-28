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
	vec<ll> ns(3, 0);
	fore (i, 0, 3) cin >> ns[i];

	string res;
	if (ns[2] > 0) {
		res.push_back('1');
		while (ns[2] > 0) {
			res.push_back('1');
			ns[2]--;
		}
		if (ns[1] > 0) {
			res.push_back('0');
			ns[1]--;
		}
	}

	if (ns[0] > 0) {
		if (res.empty()) {
			res.push_back('0');
		}
		while (ns[0] > 0) {
			res.push_back('0');
			ns[0]--;
		}
	}
	if (ns[1] > 0) {
		ll last = 1;
		if (res.empty()) {
			res.push_back('0' + last);
		} else {
			last = res.back() - '0';
		}

		while (ns[1] > 0) {
			last++;
			last %= 2;
			res.push_back(last + '0');
			ns[1]--;
		}
	}

	cout << res << endl;
}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
