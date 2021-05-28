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
	vec<ll> capacities(2);
	fore (i, 0, 2) cin >> capacities[i];
	vec<ll> counts(2);
	fore (i, 0, 2) cin >> counts[i];
	vec<ll> weights(2);
	fore (i, 0, 2) cin >> weights[i];
	if (weights[0] > weights[1]) {
		swap(weights[0], weights[1]);
		swap(counts[0], counts[1]);
	}
	ll total = 0;
	for (ll i = 0; i <= counts[0] && i*weights[0] <= capacities[0]; i++) {
		ll curr = i;
		ll cap_first = capacities[0] - i*weights[0];
		ll cap_second = capacities[1];
		ll count = counts[0] - i;
		ll sacados = min(count, cap_second / weights[0]);
		curr += sacados;
		cap_second -= sacados*weights[0];
		sacados = min(counts[1], cap_second / weights[1]);
		count = counts[1] - sacados;
		curr += sacados;
		sacados = min(count, cap_first / weights[1]);
		curr += sacados;
		total = max(total, curr);
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
