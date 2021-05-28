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

	ll n, m, qobstacles;
	cin >> n >> m >> qobstacles;

	map<ll, set<ll>> rows;
	map<ll, set<ll>> cols;
	for (ll i = 0 ; i < qobstacles; i ++) {
		ll row, col;
		cin >> row >> col;
		rows[row - 1].insert(col - 1);
		cols[col - 1].insert(row - 1);
	}

	bool termine = false;
	ll used_rows = 0;
	ll used_cols = 0;
	ll direction = 0;
	ll curr_row = 0;
	ll curr_col = -1;
	ll max_col = m - 1;
	ll max_row = n - 1;
	ll min_col = 0;
	ll min_row = 0;
	while (!termine) {

		ll moved = false;
		if (direction == 0) {
			ll prev_col = curr_col;
			auto it_primer_obs = rows[curr_row].upper_bound(curr_col);
			if (it_primer_obs == rows[curr_row].end() || *it_primer_obs > max_col) {
				curr_col = max_col;
			} else {
				// fijarse que estén todos con obstáculos después de este.
				ll obs_col = *it_primer_obs; 
				ll cubierto = true;
				for (ll i = obs_col; i <= max_col; i++) {
					cubierto &= cols[i].size() == n - used_rows;
				}

				if (!cubierto) {
					termine = true;
					cout << "No" << endl;
					break;
				}

				curr_col = obs_col - 1;
			}
			min_row = curr_row + 1;
			used_rows++;
			moved = prev_col != curr_col;
		} else if (direction == 1) {
			ll prev_row = curr_row;
			auto it_primer_obs = cols[curr_col].upper_bound(curr_row);
			if (it_primer_obs == cols[curr_col].end() || *it_primer_obs > max_row) {
				curr_row = max_row;
			} else {
				// fijarse que estén todos con obstáculos después de este.
				ll obs_row = *it_primer_obs; 
				ll cubierto = true;
				for (ll i = obs_row; i <= max_row; i++) {
					cubierto &= rows[i].size() == m - used_cols;
				}

				if (!cubierto) {
					termine = true;
					cout << "No" << endl;
					break;
				}

				curr_row = obs_row - 1;
			}
			max_col = curr_col - 1;
			used_cols++;
			moved = prev_row != curr_row;
		} else if (direction == 2) {
			ll prev_col = curr_col;
			auto it_primer_obs = rows[curr_row].lower_bound(curr_col);
			if (it_primer_obs == rows[curr_row].begin() || *(--it_primer_obs) < min_col) {
				curr_col = min_col;
			} else {
				// fijarse que estén todos con obstáculos después de este.
				ll obs_col = *it_primer_obs; 
				ll cubierto = true;
				for (ll i = obs_col; i >= min_col; i--) {
					cubierto &= cols[i].size() == n - used_rows;
				}

				if (!cubierto) {
					termine = true;
					cout << "No" << endl;
					break;
				}

				curr_col = obs_col + 1;
			}
			max_row = curr_row - 1;
			used_rows++;
			moved = prev_col != curr_col;
		} else {
			ll prev_row = curr_row;
			auto it_primer_obs = cols[curr_col].lower_bound(curr_row);
			if (it_primer_obs == cols[curr_col].begin() || *(--it_primer_obs) < min_row) {
				curr_row = min_row;
			} else {
				// fijarse que estén todos con obstáculos después de este.
				ll obs_row = *it_primer_obs; 
				ll cubierto = true;
				for (ll i = obs_row; i >= min_row; i--) {
					cubierto &= rows[i].size() == m - used_cols;
				}

				if (!cubierto) {
					termine = true;
					cout << "No" << endl;
					break;
				}

				curr_row = obs_row + 1;
			}
			min_col = curr_col + 1;
			used_cols++;
			moved = prev_row != curr_row;
		}

		if (!moved) {
			cout << "Yes" << endl;
			termine = true;
			break;
		}

		direction++;
		direction %= 4;
	}
	


	return 0;
}
