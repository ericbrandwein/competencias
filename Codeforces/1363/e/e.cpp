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

void set_child_costs(vector<vector<ll>>& graph, vector<ll>& costs) {
	stack<ll> next;
	vector<bool> visited(graph.size(), false);
	next.push(0);
	while (!next.empty()) {
		ll curr = next.top();
		next.pop();

		for (ll child : graph[curr]) {
			if (!visited[child]) {
				if (costs[child] > costs[curr]) {
					costs[child] = costs[curr];
				}
				next.push(child);
			}
		}

		visited[curr] = true;
	}
}


stack<ll> get_ordered_nodes(vector<vector<ll>>& graph) {
	stack<ll> ordered_nodes;
	ordered_nodes.push(0);
	vector<ll> level;
	vector<bool> visited(graph.size(), false);
	level.push_back(0);
	while (!level.empty()) {
		vector<ll> new_level;
		for (ll node : level) {
			for (ll child : graph[node]) {
				if (!visited[child]) {
					new_level.push_back(child);
					ordered_nodes.push(child);
				}
			}

			visited[node] = true;
		}
		level = new_level;
	}

	return ordered_nodes;
}


int main() {
	IOS;

	ll n;
	cin >> n;

	vector<ll> costs(n);
	vector<int> initial_dig(n);
	vector<int> objective_dig(n);

	ll initial_ones = 0;
	ll obj_ones = 0;
	forn (i) {
		cin >> costs[i] >> initial_dig[i] >> objective_dig[i];
		if (initial_dig[i]) {
			initial_ones++;
		}
		if (objective_dig[i]) {
			obj_ones++;
		}
	}

	vector<vector<ll>> graph(n);
	fore (i, 0, n - 1) {
		ll from, to;
		cin >> from >> to;
		from--;
		to--;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}


	if (obj_ones != initial_ones) {
		cout << -1 << endl;
		return 0;
	}


	set_child_costs(graph, costs);
	vector<vector<ll>> wrong_in_subtree(n, vector<ll>(2, 0));

	stack<ll> ordered_nodes = get_ordered_nodes(graph);

	ll cost = 0;

	vector<ll> visited(n, false);
	// We have to calculate the amount of wrong nodes in each subtree
	while (!ordered_nodes.empty()) {
		ll curr = ordered_nodes.top();
		ordered_nodes.pop();

		if (initial_dig[curr] == 1 && objective_dig[curr] == 0) {
			wrong_in_subtree[curr][1] = 1;
		} else if (initial_dig[curr] == 0 && objective_dig[curr] == 1) {
			wrong_in_subtree[curr][0] = 1;
		}

		for (ll child : graph[curr]) {
			if (visited[child]) {
				fore (i, 0, 2) {
					wrong_in_subtree[curr][i] += wrong_in_subtree[child][i];
				}
			}
		}

		ll fixed = min(wrong_in_subtree[curr][0], wrong_in_subtree[curr][1]);
		fore (i, 0, 2) {
			wrong_in_subtree[curr][i] -= fixed;
		}

		cost += fixed * 2* costs[curr];

		visited[curr] = true;
	}


	cout << cost << endl;





	return 0;
}
