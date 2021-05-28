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

ll cost_of_height(ll height, vec<ll> h, ll a, ll r, ll m) {
	ll big = h.size() - 1;
	ll cost = 0;
	for (ll small = 0; small < big && h[big] > height && h[small] < height; small++) {
		while (h[small] < height && big > small && h[big] > height) {
			ll added = min(height - h[small], h[big] - height);
			h[small] += added;
			h[big] -= added;
			if (h[big] == height) big--;
			cost += added*m;
		}
	}

	for (ll i = 0; i < h.size(); i++) {
		if (h[i] < height) {
			cost += a*(height-h[i]);
		} else {
			cost += r*(h[i]- height);
		}
	}
	return cost;
}

int main() {
	IOS;

	ll n, a, r, m;
	cin >> n >> a >> r >> m;
	m = min(m, a+r);
	vec<ll> h(n);
	forn (i) cin >> h[i];
	sort(all(h));
	ll from = 0;
	ll to = *(max_element(all(h))) + 1;
	while (from+2 < to) {
		ll jump = (to-from) /3;
		ll first_cost = cost_of_height(from + jump, h, a, r, m);
		ll second_cost = cost_of_height(from + 2*jump, h, a, r, m);
		if (first_cost <= second_cost) {
			to = from +2*jump;
		} else {
			from += jump + 1;
		}
	}

	ll mini = LONG_LONG_MAX;
	for (ll i = from; i < to; i++) {
		mini = min(mini, cost_of_height(i, h, a ,r ,m));
	}
	cout << mini << endl;

}
