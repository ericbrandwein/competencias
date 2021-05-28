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

struct Path {
	ll moves, changes;
	const bool operator<(const Path& other) const {
		return moves < other.moves || moves== other.moves && changes < other.changes;
	}
};

struct Pos {
	ll num;
	pair<ll,ll> coords;
	const bool operator<(const Pos& other) const {
		return num < other.num;
	}
};


void calculate_min_paths(Pos& prev, Pos& curr, vec<vec<vec<Path>>>& min_paths) {
	ll min_with_rook = 2;
	if (prev.coords.first == curr.coords.first || prev.coords.second == curr.coords.second) {
		min_with_rook = 1;
	}

	ll min_with_bishop = LONG_LONG_MAX;
	if (prev.coords.first + prev.coords.second == curr.coords.first + curr.coords.second ||
		prev.coords.first - prev.coords.second == curr.coords.first - curr.coords.second
	) {
		min_with_bishop = 1;
	} else if (
		(prev.coords.first + prev.coords.second) % 2 == (curr.coords.first + curr.coords.second) % 2
	) {
		min_with_bishop = 2;
	}

	ll min_with_horse = LONG_LONG_MAX;
	for (ll dir = 0; dir < 4; dir++) {
		pair<ll,ll> new_pos = prev.coords;
		if (dir % 2 == 0) {
			ll mult = 1;
			if (dir % 4 == 3) {
				mult = -1;
			}
			new_pos.first += mult * 2;
		} else {
			ll mult = 1;
			if (dir % 4 == 2) {
				mult = -1;
			}
			new_pos.second += mult * 2;
		}
		for (ll left = 0; left < 2; left++) {
			ll sum = left * 2 - 1;
			if (dir % 2 == 0) {
				new_pos.second += sum;
			} else {
				new_pos.first += sum;
			}
			if (new_pos == curr.coords) {
				min_with_horse = 1;
			} else {
				for (ll dir = 0; dir < 4; dir++) {
					if (dir % 2 == 0) {
						ll mult = 1;
						if (dir % 4 == 3) {
							mult = -1;
						}
						new_pos.first += mult * 2;
					} else {
						ll mult = 1;
						if (dir % 4 == 2) {
							mult = -1;
						}
						new_pos.second += mult * 2;
					}
					for (ll left = 0; left < 2; left++) {
						ll sum = left * 2 - 1;
						if (dir % 2 == 0) {
							new_pos.second += sum;
						} else {
							new_pos.first += sum;
						}
						if (new_pos == curr.coords) {
							min_with_horse = min(min_with_horse, 2ll);
						}
					}
				}
			}
		}
	}

	vec<ll> mins = {min_with_rook, min_with_bishop, min_with_rook};
	ll min_total = *min_element(all(mins));
	for (ll curr_piece = 0; curr_piece < 3; curr_piece++) {
		Path new_path = {LONG_LONG_MAX, LONG_LONG_MAX};
		for (ll prev_piece = 0; prev_piece < 3; prev_piece++) {
			Path prev_path = min_paths[prev.coords.first][prev.coords.second][prev_piece];
			if (prev_piece == curr_piece) {
				if (mins[prev_piece] == LONG_LONG_MAX) {
					prev_path.changes += 2;
					prev_path.moves += min_total + 2;
				}
			} else {
				prev_path.changes++;
				prev_path.moves++;
				prev_path.moves += min(mins[prev_piece], mins[curr_piece]);
			}
			new_path = min(new_path, prev_path);
		}
		min_paths[curr.coords.first][curr.coords.second][curr_piece] = new_path;
	}
}


int main() {
	IOS;


	ll n;
	cin >> n;
	vec<Pos> pos;
	forn (i) {
		forn (j) {
			ll num;
			cin >> num;
			pos.push_back({num, {i, j}});
		}
	}
	sort(all(pos));
	// 0: rook, 1: bishop, 2: horse
	vec<vec<vec<Path>>> min_paths(n, vec<vec<Path>>(n, vec<Path>(3)));
	pair<ll,ll> first = pos[0].coords;
	for (ll i = 0; i < 3; i++) {
		min_paths[first.first][first.second][i] = {0,0};
	}
	for (ll i = 1; i < pos.size(); i++) {
		calculate_min_paths(pos[i-1], pos[i], min_paths);
	}

	vec<Path>& min_path_vec = min_paths[pos.back().coords.first][pos.back().coords.second];
	Path& min_path = *min_element(all(min_path_vec));
	cout << min_path.moves << " " << min_path.changes << endl;


	return 0;
}
