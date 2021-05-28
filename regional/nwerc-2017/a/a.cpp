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

void llenar_dp(vec<ll>& dp, ll orden, vec<vec<ll>>& posiciones, vec<ll>& h) {
	ll nums_diferentes = posiciones.size();
	if (orden == nums_diferentes - 1) {
		for (ll posicion : posiciones[orden]) {
			dp[posicion] = 0;
		}
	} else {
		set<pair<ll,ll>> maxs; // num, pos
		for (ll posicion : posiciones[orden + 1]) {
			ll curr_sum = dp[posicion];
			if (posicion > 0 && h[posicion - 1] == orden) {
				curr_sum++;
			}
			maxs.insert({curr_sum, posicion});
			if (maxs.size() > 2) {
				maxs.erase(maxs.begin());
			}
		}

		for (ll posicion : posiciones[orden]) {
			pair<ll,ll> primer_max = *(--maxs.end());
			dp[posicion] = primer_max.first;
			if (primer_max.second == posicion + 1 && posiciones[orden].size() > 1) {
				dp[posicion] = primer_max.first - 1;
				if (maxs.size() > 1) {
					pair<ll,ll> segundo_max = *(maxs.begin());
					dp[posicion] = max(dp[posicion], segundo_max.first);
				}
			}
		}
	}
}


int main() {
	IOS;

	ll n;
	cin >> n;
	vec<ll> h(n);
	forn (i) cin >> h[i];

	auto new_end = unique(h.begin(), h.end());
	h.erase(new_end, h.end());

	vec<ll> sorted = h;
	sort(all(sorted));
	auto new_end_sorted = unique(sorted.begin(), sorted.end());
	sorted.erase(new_end_sorted, sorted.end());
	map<ll,ll> num_a_orden;
	for (ll i = 0; i < sorted.size(); i++) {
		num_a_orden[sorted[i]] = i;
	}
	for (ll i = 0; i < h.size(); i++) {
		h[i] = num_a_orden[h[i]];
	}

	ll nums_diferentes = num_a_orden.size();
	vec<vec<ll>> posiciones(nums_diferentes);
	for (ll i = 0; i < h.size(); i++) {
		posiciones[h[i]].push_back(i);
	}

	vec<ll> dp(h.size(), 0);
	for (ll orden = num_a_orden.size() - 1; orden >= 0; orden--) {
		llenar_dp(dp, orden, posiciones, h);
	}

	ll max_no_sacadas = 0;
	for (ll posicion : posiciones[0]) {
		max_no_sacadas = max(max_no_sacadas, dp[posicion]);
	}

	cout << h.size() - 1 - max_no_sacadas << endl;


}
