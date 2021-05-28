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
	string s;
	cin >> s;
	vec<ll> a(n);
	for (ll i = 0; i < s.size(); i++) {
		a[i] = s[i] - '0' - 1;
	}

	ll curr = 0;
	map<ll, ll> ocurr;
	ocurr[0]++;
	ll total = 0;
	for (ll i = 0; i < n; i++) {
		curr += a[i];
		if (ocurr.count(curr) != 0) {
			total += ocurr[curr];
		}
		ocurr[curr]++;
	}


cout << total << endl;



}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
