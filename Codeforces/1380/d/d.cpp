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

ll moves_for(vector<ll>& a, ll from, ll to, ll fcost, ll frange, ll bcost) {
	ll max_edge = 0;
	if (from > -1) {
		max_edge = a[from];
	}
	if (to < a.size()) {
		max_edge = max(a[to], max_edge);
	}

	ll max_inside = 0;
	fore (i, from + 1, to) {
		max_inside = max(max_inside, a[i]);
	}

	bool can_use_all_b = max_inside < max_edge;
	ll length = to - from - 1;
	bool can_use_f = length >= frange;
	if (!can_use_all_b && !can_use_f) {
		return -1;
	}

	ll min_cost = LONG_LONG_MAX;

	if (can_use_all_b) {
		min_cost = length * bcost;
	} else {
		min_cost = fcost + bcost * (length - frange);
	}

	ll fit_f = length / frange;
	min_cost = min(min_cost, fit_f * fcost + bcost * (length - fit_f * frange));
	return min_cost;
}


int main() {
	IOS;

	ll n, m;
	cin >> n >> m;
	ll fcost, frange, bcost;
	cin >> fcost >> frange >> bcost;
	vector<ll> a(n), b(m);
	forn (i) cin >> a[i];
	fore (i, 0, m) cin >> b[i];

	ll total = 0;
	ll b_index = 0;
	ll prev_index = -1;
	forn (i) {
		if (b_index < m && a[i] == b[b_index]) {
			ll moves = moves_for(a, prev_index, i, fcost, frange, bcost);
			if (moves == -1) {
				cout << -1 << endl;
				return 0;
			}
			total += moves;
			prev_index = i;
			b_index++;
		}
	}
	ll moves = moves_for(a, prev_index, n, fcost, frange, bcost);
	if (moves == -1 || b_index < m) {
		cout << -1 << endl;
		return 0;
	}
	total += moves;
	cout << total << endl;

	return 0;
}
