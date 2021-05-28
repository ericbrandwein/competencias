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

pair<ll, ll> ask(vector<ll>& nodes) {
	cout << "? " << nodes.size() << " ";
	for (ll node : nodes) {
		cout << node + 1<< " ";
	}
	cout << endl;
	cout << flush;
	ll node, dist;
	cin >> node >> dist;
	node--;
	return {node, dist};
}

void children_with_distance(ll from, vector<vector<ll>>& children, vector<ll>& res, ll distance) {
	if (distance == 0) {
		res.push_back(from);
	} else {
		for (ll child : children[from]) {
			children_with_distance(child, children, res, distance - 1);
		}
	}
}

ll find_node(vector<vector<ll>>& children, vector<ll>& parents, ll root, ll orig_dist) {
	// Búsqueda binaria en la distancia para encontrar la distancia del nodo desde el root.

	ll found_node = root;
	ll from = 0;
	ll to = orig_dist + 1;
	while (from < to) {
		ll middle = (from + to) / 2;
		vector<ll> nodes_to_ask_for;
		children_with_distance(root, children, nodes_to_ask_for, middle);
		if (nodes_to_ask_for.empty()) {
			to = middle;
		} else {
			pair<ll, ll> res = ask(nodes_to_ask_for);
			ll dist = res.second;
			if (dist == orig_dist) {
				found_node = res.first;
				from = middle + 1;
			} else {
				to = middle;
			}
		}

	}
	return found_node;
}


void solve() {
	ll n;
	cin >> n;
	vector<vector<ll>> edges(n);

	fore (i, 0, n-1) {
		ll from, to;
		cin >> from >> to;
		from--;
		to--;
		edges[from].push_back(to);
		edges[to].push_back(from);
	}

	vector<ll> all_nodes;
	fore (i, 0, n) {
		all_nodes.push_back(i);
	}
	pair<ll, ll> res = ask(all_nodes);
	ll root = res.first;
	ll orig_dist = res.second;

	vector<vector<ll>> children(n);
	vector<ll> parents(n, -1);
	stack<ll> next;
	next.push(root);
	while (!next.empty()) {
		ll curr = next.top();
		next.pop();
		for (ll child : edges[curr]) {
			if (children[child].empty()) {
				children[curr].push_back(child);
				next.push(child);
				parents[child] = curr;
			}
		}
	}

	ll found_node = find_node(children, parents, root, orig_dist);

	// Encontramos uno de los nodos.
	// Vemos su distancia al padre.
	ll curr_parent = found_node;
	ll level = 0;
	vector<bool> parents_of_found_node(n, false);
	parents_of_found_node[found_node] = true;
	while (curr_parent != root) {
		curr_parent = parents[curr_parent];
		parents_of_found_node[curr_parent] = true;
		level++;
	}
	parents_of_found_node[root] = false;

	ll dist_to_other_node = orig_dist - level;

	vector<ll> possible_others;
	children_with_distance(root, children, possible_others, dist_to_other_node);
	vector<ll> nodes_to_ask_for;

	for (ll i = 0; i < possible_others.size(); i++) {
		if (!parents_of_found_node[possible_others[i]]) {
			nodes_to_ask_for.push_back(possible_others[i]);
		}
	}
	res = ask(nodes_to_ask_for);
	ll other_node = res.first;

	cout << "! " << found_node + 1 << " " << other_node + 1 << endl << flush;
	string correct;
	cin >> correct;
}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
