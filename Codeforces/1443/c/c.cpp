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
	vec<pair<ll,ll>> couriers(n);
	vec<ll> petya(n);
	forn (i) {
		cin >> couriers[i].first;
		couriers[i].second = i;
	}
	forn(i) cin >> petya[i];

	sort(couriers.rbegin(), couriers.rend());

	ll time_bigger = 0;
	ll best_time = couriers[0].first;
	for (ll i = 0; i < couriers.size(); i++) {
		time_bigger += petya[couriers[i].second];
		ll curr_time = time_bigger;
		if (i < couriers.size() - 1) {
			curr_time = max(curr_time, couriers[i+1].first);
		}
		best_time = min(best_time, curr_time);
	}

	cout << best_time << endl;
}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--)solve();


	return 0;
}
