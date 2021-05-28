//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define elif else if
#define ll int
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

ll get_cycle_width(
	vec<vec<vec<pair<ll, ll>>>>& parents, vec<vec<vec<pair<ll, ll>>>>& children,
	vec<pair<ll,ll>>& cycle, pair<ll, ll>& node_in_cycle
) {
	stack<pair<ll,ll>> next;
	next.push(cycle[0]);
	map<pair<ll,ll>, ll> pos;
	pos[cycle[0]] = 0;
	while (!next.empty()) {
		pair<ll,ll> curr = next.top();
		next.pop();
		for (pair<ll,ll> child: children[curr.first][curr.second]) {
			if (pos.count(child) > 0) {
				node_in_cycle = child;
				return pos[curr] - pos[child] + 1;
			} else {
				pos[child] = pos[curr] + 1;
				next.push(child);
			}
		}
	}
}



void count_for_cycle(
	vec<vec<vec<pair<ll, ll>>>>& parents, vec<vec<vec<pair<ll, ll>>>>& children,
	vec<string>& colors, vec<pair<ll,ll>>& cycle, ll& total, ll& blacks
) {
	pair<ll,ll> node_in_cycle;
	ll cycle_width = get_cycle_width(parents, children, cycle, node_in_cycle);

	map<pair<ll,ll>, ll> pos;
	vector<pair<ll,ll>> in_cycle;
	in_cycle.push_back(node_in_cycle);
	pos[node_in_cycle] = 0;
	pair<ll,ll> curr = children[node_in_cycle.first][node_in_cycle.second].back();
	ll curr_pos = 0;
 	while (curr != node_in_cycle) {
		in_cycle.push_back(curr);
		curr_pos++;
		pos[curr] = curr_pos;
		curr = children[curr.first][curr.second].back();
	}

	vec<bool> blacks_with_pos(cycle_width, false);
	for (ll i = 0; i < in_cycle.size(); i++) {
		pair<ll,ll>& child = in_cycle[i];
		stack<pair<ll,ll>> next_parents;
		next_parents.push(child);
		while (!next_parents.empty()) {
			pair<ll,ll> curr= next_parents.top();
			next_parents.pop();
			ll curr_pos = pos[curr];
			if (colors[curr.first][curr.second] == '0') {
				blacks_with_pos[curr_pos] = true;
			}
			curr_pos--;
			if (curr_pos < 0) curr_pos = cycle_width - 1;
			for (const pair<ll,ll>& parent : parents[curr.first][curr.second]) {
				if (pos.count(parent) == 0) {
					next_parents.push(parent);
					pos[parent] = curr_pos;
				}
			}
		}
	}


	total += cycle_width;
	for (ll i = 0; i < blacks_with_pos.size(); i++) {
		if (blacks_with_pos[i]) blacks++;
	}
}


vec<pair<ll,ll>> make_cycle(
	vec<vec<vec<pair<ll, ll>>>>& parents, vec<vec<vec<pair<ll, ll>>>>& children,
	vec<vec<bool>>& visited, ll row, ll col
) {
	vec<pair<ll,ll>> cycle;
	stack<pair<ll, ll>> next;
	next.push({row, col});
	visited[row][col] = true;
	while (!next.empty()) {
		pair<ll, ll> curr = next.top();
		next.pop();
		cycle.push_back(curr);
		for (pair<ll, ll> child : children[curr.first][curr.second]) {
			if (!visited[child.first][child.second]) {
				next.push(child);
				visited[child.first][child.second] = true;
			}
		}
		for (pair<ll, ll> parent : parents[curr.first][curr.second]) {
			if (!visited[parent.first][parent.second]) {
				next.push(parent);
				visited[parent.first][parent.second] = true;
			}
		}
	}

	return cycle;
}


void solve() {
	ll n, m;
	cin >> n >> m;
	vec<string> colors(n);
	forn (i) cin >> colors[i];

	vec<vec<vec<pair<ll, ll>>>> parents(n, vec<vec<pair<ll,ll>>>(m));
	vec<vec<vec<pair<ll, ll>>>> children(n, vec<vec<pair<ll,ll>>>(m));

	vec<string> dirs(n);
	forn (row) {
		cin >> dirs[row];
		for (ll col = 0; col < m; col++) {
			pair<ll,ll> child;
			if (dirs[row][col] == 'U') {
				child = {row - 1, col};
			} else if (dirs[row][col] == 'D') {
				child = {row + 1, col};
			} else if (dirs[row][col] == 'L') {
				child = {row, col - 1};
			} else {
				child = {row, col + 1};
			}
			parents[child.first][child.second].push_back({row, col});
			children[row][col].push_back(child);
		}
	}

	vec<vec<bool>> visited(n, vec<bool>(m, false));
	vec<vec<pair<ll, ll>>> cycles;

	for (ll row = 0; row < n; row++) {
		for (ll col = 0; col < m; col++) {
			if (!visited[row][col]) {
				cycles.push_back(make_cycle(parents, children, visited, row, col));
			}
		}
	}

	ll total = 0;
	ll blacks = 0;
	for (ll i = 0; i < cycles.size(); i++) {
		count_for_cycle(parents, children, colors, cycles[i], total, blacks);
	}

	cout << total << " " << blacks << endl;


}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();


	return 0;
}
