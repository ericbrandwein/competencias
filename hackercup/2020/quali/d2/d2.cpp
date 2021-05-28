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

vector<ll> path_between(vector<vec<ll>>& graph, ll from, ll to) {
	ll n = graph.size();
	vector<ll> path;
	stack<ll> next;
	next.push(from);
	vector<bool> visited(n, false);
	vector<bool> added_to_stack(n, false);
	added_to_stack[from] = true;
	while (!next.empty()) {
		ll curr = next.top();
		if (curr == to) {
			path.push_back(curr);
			break;
		}
		if (visited[curr]) {
			// ya visitamos todos sus hijos
			path.pop_back();
			next.pop();
		} else {
			path.push_back(curr);
			for (ll child : graph[curr]) {
				if (!added_to_stack[child]) {
					next.push(child);
					added_to_stack[child] = true;
				}
			}

			visited[curr] = true;
		}
	}

	return path;
}


void fill_subtree_costs(
	vec<vec<ll>>& graph, vector<bool>& visited, vector<ll>& costs,
	vec<ll>& cost_of_reaching, map<ll, vec<ll>>& at_distance, ll root_dist, ll root
) {
	ll n = graph.size();
	ll level = root_dist;
	stack<ll> next;
	next.push(root);
	vector<bool> added_to_stack(n, false);
	while (!next.empty()) {
		ll curr = next.top();
		if (added_to_stack[curr]) {

		} else {
			added_to_stack[curr] = true;
		}
	}

}


void solve() {
	ll n, length;
	cin >> n >> length;
	ll from, to;
	cin >> from >> to;
	vector<vec<ll>> graph(n);
	vector<ll> costs(n);
	forn (i) {
		ll parent;
		cin >> parent >> costs[i];
		parent--;
		if (parent != -1) {
			graph[parent].push_back(i);
			graph[i].push_back(parent);
		}
	}

	vector<ll> path = path_between(graph, from, to);

	vector<bool> visited(n, false);
	for (ll node : path) {
		visited[node] = true;
	}

	vector<ll> cost_of_reaching(n, 0);
	map<ll, vector<ll>> at_distance;
	at_distance[0].push_back(path[0]);
	set<ll> previous;
	previous.insert(0);
	for (ll i = 0; i < path.size(); i++) {
		if (previous.empty()) {
			cout << -1 << endl;
			return;
		}

		fill_subtree_costs(graph, visited, costs, cost_of_reaching, at_distance, i, path[i]);

		at_distance[i].push_back(path[i]);
	}



}

int main() {
	IOS;

	ll t;
	cin >> t;
	fore (i, 0, t) {
		cout << "Case #" << i + 1 << ": ";
		solve();
	}

	return 0;
}
