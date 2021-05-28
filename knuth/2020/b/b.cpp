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

void normalize(vector<ll>& nums) {
	ll min_elem = *min_element(all(nums));
	for (ll i = 0; i < nums.size(); i++) {
		nums[i] -= min_elem;
	}
}

void buscar_con_uno(
	map<vector<ll>, ll>& first_pos, vector<ll>& para, ll pos, ll& from, ll& to, ll& distance) {

	for (ll mayor = 0; mayor < 4; mayor++) {
		for (ll conjunto = 0; conjunto < 7; conjunto++) {
			vector<ll> buscado = para;
			ll bits = conjunto;
			buscado[mayor]--;
			for (ll i = 0; i < 4; i++) {
				if (i != mayor) {
					if (bits & 1) {
						buscado[i]--;
					}
					bits >>= 1;
				}
			}

			normalize(buscado);
			if (first_pos.count(buscado) != 0) {
				ll pos_ant = first_pos[buscado];
				ll new_distance = pos - pos_ant;
				if (new_distance > distance) {
					distance = new_distance;
					from = pos_ant;
					to = pos;
				}
			}
		}
	}
}

int main() {
	IOS;

	string s;
	cin >> s;
	vector<ll> nums(s.size());
	map<char, ll> pos;
	pos['R'] = 0;
	pos['G'] = 1;
	pos['B'] = 2;
	pos['Y'] = 3;
	for (ll i = 0; i < s.size(); i++) {
		nums[i] = pos[s[i]];
	}

	map<vector<ll>, ll> first_pos;
	first_pos[{0,0,0,0}] = 0;
	vector<vector<ll>> acum(s.size() + 1, vec<ll>(4, 0));

	bool con_cero = false;
	ll distance = 1;
	ll from = 0, to = 1;
	for (ll i = 0; i < nums.size(); i++) {
		acum[i + 1] = acum[i];
		acum[i + 1][nums[i]]++;

		normalize(acum[i+1]);
		if (first_pos.count(acum[i+1]) == 0) {
			if (!con_cero) {
				// buscamos uno con 1
				buscar_con_uno(first_pos, acum[i+1], i+1, from, to, distance);
			}

			first_pos[acum[i+1]] = i+1;
		} else {
			// hay uno con cero

			ll pos_ant = first_pos[acum[i+1]];
			ll new_distance = i + 1 - pos_ant;
			if (!con_cero || new_distance > distance) {
				distance = new_distance;
				from = pos_ant;
				to = i + 1;
			}
			con_cero = true;
		}

	}


	ll min_sum = 1;
	if (con_cero) min_sum = 0;
	cout << min_sum << " " << distance << endl;
	cout << from + 1 << " " << to << endl;
	// cout << min_sum << " " << to - from << endl;
	// cout << from + 1 << " " << to << endl;









	return 0;
}
