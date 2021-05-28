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
	ll n, k;
	cin >> n >> k;

	string occupied;
	cin >> occupied;

	vector<ll> distances;
	ll distance = k;
	for (ll i = 0; i < n; i++) {
		if (occupied[i] == '1') {
			distances.push_back(distance);
			distance = 0;
		} else {
			distance++;
		}
	}
	distances.push_back(distance + k);

	ll added = 0;
	for (ll distance: distances) {
		if (distance > k) {
			added += distance / (k + 1) - 1;
			if (distance % (k + 1) == k) {
				added++;
			}
		}
	}
	cout << added << endl;

}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
