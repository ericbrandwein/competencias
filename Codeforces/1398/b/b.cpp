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
	string s;
	cin >> s;

	vec<ll> lengths;
	ll curr = 0;
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] == '1') {
			curr++;
		} else if (curr > 0) {
			lengths.push_back(curr);
			curr = 0;
		}
	}
	if (curr > 0) {
		lengths.push_back(curr);
	}

	sort(lengths.rbegin(), lengths.rend());

	ll total = 0;
	for (ll i = 0; i < lengths.size(); i+=2) {
		total += lengths[i];
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
