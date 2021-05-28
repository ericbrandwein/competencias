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
	string city;
	cin >> city;
	ll first_one = 0;
	for (; first_one < city.size() && city[first_one] == '0'; first_one++);
	if (first_one == city.size()) {
		cout << 0 << endl;
		return;
	}
	vec<ll> clear_segments;
	ll length = 0;
	ll segments = 1;
	for (ll i = first_one; i < city.size(); i++) {
		if (city[i] == '0') {
			length++;
		} else if (length > 0) {
			segments++;
			clear_segments.push_back(length);
			length = 0;
		}
	}

	ll cost = a*segments;
	for (ll segment : clear_segments) {
		if (b*segment < a) {
			cost -= a;
			cost += b*segment;
		}
	}

	cout << cost << endl;

}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--)solve();

	return 0;
}
