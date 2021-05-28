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
	ll n, m;
	cin >> n >> m;
	vec<pair<ll,ll>> pos(m);
	map<ll,set<ll>> by_x, by_y;
	fore (i, 0, m) {
		cin >> pos[i].first >> pos[i].second;
		if (pos[i].first != pos[i].second) {
			by_x[pos[i].first].insert(i);
			by_y[pos[i].second].insert(i);
		}
	}

	vec<bool> ocupado_x(m,false);
	vec<bool> ocupado_y(m,false);

	map<ll,set<ll>> ocupados; // lados ocupados, indice
	vec<ll> ocupacion_actual(m, 0);
	ll res = 0;
	fore (i, 0, m) {
		if (pos[i].first != pos[i].second) {
			ocupado_x[i] = !by_x[pos[i].second].empty();
			ocupado_y[i] = !by_y[pos[i].first].empty();
			ll ocupacion = 0;
			if (ocupado_x[i]) ocupacion++;
			if (ocupado_y[i]) ocupacion++;
			ocupados[ocupacion].insert(i);
			ocupacion_actual[i] = ocupacion;
		}
	}


	while (!ocupados.empty()) {
		auto curr = ocupados.begin();
		if (curr->second.empty()) {
			ocupados.erase(curr);
		} else {
			ll curr_i = *(curr->second.begin());
			res++;
			if (curr->first == 2) {
				res++;
			}
			by_x[pos[curr_i].first].erase(curr_i);
			by_y[pos[curr_i].second].erase(curr_i);
			if (by_x[pos[curr_i].first].empty()) {
				for (ll other : by_y[pos[curr_i].first]) {
					// ya no tienen ocupado el y
					if (pos[other].first != pos[other].second) {
						ocupados[ocupacion_actual[other]].erase(other);
						ocupacion_actual[other]--;
						ocupados[ocupacion_actual[other]].insert(other);
					}
				}
			}
			if (by_y[pos[curr_i].second].empty()) {
				for (ll other : by_x[pos[curr_i].second]) {
					// ya no tienen ocupado el y
					if (pos[other].first != pos[other].second) {
						ocupados[ocupacion_actual[other]].erase(other);
						ocupacion_actual[other]--;
						ocupados[ocupacion_actual[other]].insert(other);
					}
				}
			}
			curr->second.erase(curr_i);
		}
	}

	cout << res << endl;


}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();
}
