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

struct Event {
	bool start; // or end
	ll interval_index;
};

int main() {
	IOS;

	ll n, m, prof_len;
	cin >> n >> m >> prof_len;
	vec<pair<ll,ll>> intervals(m);
	vec<vec<Event>> events(n+ 1);
	fore (i, 0, m) {
		cin >> intervals[i].first >> intervals[i].second;
		intervals[i].first--;
		intervals[i].second;
		events[intervals[i].first].push_back({true, i});
		events[intervals[i].second].push_back({false, i});
	}

	vec<bool> first_using(m, false);
	ll first_restando = 0;
	ll first_sumando = 0;
	ll suma = 0;
	for (ll i = 0; i < prof_len-1; i++) {
		for (Event& event : events[i]) {
			if (event.start) {
				first_sumando++;
				first_using[event.interval_index] = true;
			} else {
				first_sumando--;
			}
		}
		suma += first_sumando;
	}

	ll mejor_suma = suma;

	for (ll first_prof_start = 0; first_prof_start + prof_len < n; first_prof_start++) {
		// Agregamos el último
		ll agregado = first_prof_start + prof_len;
		for (Event& event : events[agregado]) {
			if (event.start) {
				first_sumando++;
				first_using[event.interval_index] = true;
			} else {
				first_sumando--;
			}
		}

		suma += first_sumando;
		suma -= first_restando;

		ll suma_total = suma;
		vec<vec<Event>> delayed_events(n + 1);
		ll second_restando = 0;
		ll second_sumando = 0;
		for (ll i = 0; i < prof_len-1; i++) {
			for (Event& event : events[i]) {
				if (event.start) {
					second_sumando++;
					first_using[event.interval_index] = true;
				} else {
					second_sumando--;
				}
			}
			suma += second_sumando;
		}
		for (
			ll second_prof_start = 0; second_prof_start + prof_len < n ; second_prof_start++
		) {


		}


		// Sacamos el primero
		for (Event& event : events[first_prof_start]) {
			if (event.start) {
				first_restando++;
			} else {
				first_restando--;
				first_using[event.interval_index] = false;
			}
		}

	}

	return 0;
}
