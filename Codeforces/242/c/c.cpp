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

ll moves(int startx, int starty, int endx, int endy, vec<pair<int, int>>& allowed) {
	ll total = -1;
	queue<int> next;
	auto it = lower_bound(all(allowed), make_pair(startx, starty));
	int first_index = it - allowed.begin();
	next.push(first_index);
	vector<ll> distances(allowed.size(), -1);
	distances[first_index] = 0;
	while (total == -1 && !next.empty()) {
		int current = next.front(); next.pop();
		int current_distance = distances[current];
		if (allowed[current] == make_pair(endx, endy)) {
			total = current_distance;
		} else {
			for (int fila = allowed[current].first - 1;
					fila <= allowed[current].first + 1;
					fila++) {
				auto neighbor = lower_bound(all(allowed), make_pair(fila, allowed[current].second - 1));
				while (neighbor != allowed.end() && neighbor->first == fila &&
						neighbor->second <= allowed[current].second + 1) {
					int neighbor_index = neighbor - allowed.begin();
					if (distances[neighbor_index] == -1) {
						distances[neighbor_index] = current_distance + 1;
						next.push(neighbor_index);
					}

					neighbor++;
				}
			}
		}
	}

	return total;
}


int main() {
	IOS;

	int startx, starty;
	int endx, endy;
	cin >> startx >> starty >> endx >> endy;

	int segments_q;
	cin >> segments_q;
	set<pair<int, int>> allowed;
	for (ll i = 0; i < segments_q; i++) {
		int row, from, to;
		cin >> row >> from >> to;
		for (int j = from; j <= to; j++) {
			allowed.insert({row, j});
		}
	}

	vector<pair<int, int>> allowed_v(allowed.begin(), allowed.end());

	cout << moves(startx, starty, endx, endy, allowed_v) << endl;


	return 0;
}
