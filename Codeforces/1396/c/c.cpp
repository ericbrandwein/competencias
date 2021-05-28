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
	vec<ll> recharge(3);
	fore (i, 0, 3) cin >> recharge[i];

	ll dist;
	cin >> dist;

	vec<ll> monsters(n);
	forn (i) cin >> monsters[i];
	vec<ll> killed(n);
	vec<ll> alive(n);

	forn (i) {
		alive[i] = min(recharge[1], recharge[0]*(monsters[i] + 1));
		killed[i] = recharge[0]*monsters[i] + recharge[2];
	}

	ll cost_of_killing = recharge[0];
	// dead, alive
	vec<vec<ll>> costs(n, vec<ll>(2));
	forn (i) {
		// asumo los anteriores muertos.
		ll cost_dead = killed[i];
		ll cost_alive = alive[i];
		if (i > 0) {
			cost_alive = dist;
			cost_dead = dist;

			ll cost_ret = 2*dist;
			cost_alive += alive[i] + min(
				cost_ret + costs[i-1][1] + cost_of_killing, costs[i-1][0]
			);
			ll cost_dead_dead = costs[i-1][0] + min(
				killed[i], cost_ret + alive[i] + cost_of_killing
			);
			ll cost_alive_dead = costs[i-1][1] + cost_of_killing + cost_ret + min(
				alive[i] + cost_of_killing,
				killed[i]
			);
			if (i == n-1) {
				cost_alive_dead = min(
					cost_alive_dead,
					costs[i-1][1] + cost_of_killing + dist + killed[i]
				);
			}
			cost_dead += min(cost_dead_dead, cost_alive_dead);
		}

		costs[i][0] = cost_dead;
		costs[i][1] = cost_alive;
	}

	cout << costs[n-1][0] << endl;


	return 0;
}
