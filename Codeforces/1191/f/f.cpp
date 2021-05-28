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

int main() {
	IOS;

	ll n;
	cin >> n;
	map<ll, set<ll>> points; // (y, x)
	forn (i) {
		ll x, y;
		cin >> x >> y;
		points[y].insert(x);
	}

	set<ll> prev_xs;
	auto it = points.rbegin();
	ll total = 0;
	while (it != points.rend()) {
		const set<ll>& curr_x_points = it->second;
		auto curr_point = curr_x_points.begin();
		auto it_up = prev_xs.begin();
		ll combi_antes = 0;
		for (; curr_point != curr_x_points.end();) {
			ll x = *curr_point;
			while (it_up != prev_xs.end() && *it_up < x) {
				it_up++;
				combi_antes++;
			}
			if (it_up != prev_xs.end() && *it_up == x) it_up++;
			// empezar justo acá
			combi_antes++;
			ll combi_despues = 1;
			ll next_x = 1e9 + 1;
			if (++curr_point != curr_x_points.end()) {
				next_x = *curr_point;
			}
			auto it_despues = it_up;
			while (it_despues != prev_xs.end() && *it_despues < next_x) {
				it_despues++;
				combi_despues++;
			}
			total += combi_antes * combi_despues;
		}
		prev_xs.insert(curr_x_points.begin(), curr_x_points.end());
		it++;
	}

	cout << total << endl;


	return 0;
}
