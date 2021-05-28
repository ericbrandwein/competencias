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

struct Show {
	int from, to, cost, color;

	bool const operator<(const Show& other) const {
		return from < other.to;
	}
};


int main() {
	IOS;

	ll n;
	cin >> n;
	vec<vec<Show>> stages(n);
	ll max_time = 86400;
	vec<vec<Show>> shows_per_start(max_time + 1);
	forn (i) {
		ll m;
		cin >> m;
		fore (j, 0, m) {
			Show show;
			show.color = i;
			cin >> show.from >> show.to >> show.cost;
			stages[i].push_back(show);
			shows_per_start[show.from].push_back(show);
		}
	}

	ll max_mask = (1LL<<n) - 1;
	vec<vec<int>> max_costs(max_time + 1, vec<int>(max_mask + 1, -1));
	max_costs[max_time][0] = 0;

	for (ll time = max_time - 1; time >= 0; time--) {
		max_costs[time] = max_costs[time + 1];

		for (const Show& show : shows_per_start[time]) {
			ll show_mask = 1<<show.color;
			for (ll mask = 0; mask <= max_mask; mask++) {
				if (mask & show_mask) {
					ll mask_without = mask - show_mask;
					if (max_costs[show.to][mask] != -1) {
						max_costs[time][mask] = max(
							max_costs[time][mask],
							show.cost + max_costs[show.to][mask]
						);
					}
					if (max_costs[show.to][mask_without] != -1) {
						max_costs[time][mask] = max(
							max_costs[time][mask],
							show.cost + max_costs[show.to][mask_without]
						);
					}
				}
			}
		}
	}

	cout << max_costs[0][max_mask] << endl;
}
