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

pair<ll, ll> ask_for_path_enhancement(
	pair<ll, ll>& curr_ends, vector<vector<ll>>& children, ll distance,
	vector<bool>& belongs_to_path
) {
	// Preguntamos por los que estén a distancia distance de alguno de los dos
	vector<ll> first_children;
	children_with_distance(curr_ends.first, children, first_children, distance);
	vector<ll> second_children;
	if (curr_ends.first != curr_ends.second) {
		children_with_distance(curr_ends.second, children, second_children, distance);
	}

	vector<ll> to_ask;
	for (ll child : first_children) {
		if (!belongs_to_path[child]) {
			to_ask.push_back(child);
		}
	}
	for (ll child : second_children) {
		if (!belongs_to_path[child]) {
			to_ask.push_back(child);
		}
	}

	return ask(to_ask);
}

void add_to_path(
	vector<ll>& parents, pair<ll, ll>& curr_ends, ll added, vector<bool>& belongs_to_path
) {
	ll parent = added;
	while (true) {
		belongs_to_path[parent] = true;
		parent = parents[parent];
		if (parent == curr_ends.first) {
			curr_ends.first = added;
			break;
		} else if (parent == curr_ends.second) {
			curr_ends.second = added;
			break;
		}
	}
}


pair<ll, ll> find_nodes(
	vector<vector<ll>>& children, vector<ll>& parents, ll root, ll distance
) {
	// Agrandamos el camino hasta encontrar las dos puntas
	pair<ll, ll> curr_ends = {root, root};
	vector<bool> belongs_to_path(parents.size(), false);
	belongs_to_path[root] = true;
	ll curr_path_length = 0;

	while (curr_path_length < distance) {
		ll distance_diff = distance - curr_path_length;
		if (distance_diff % 2 == 1) distance_diff++;
		ll curr_asking_distance = distance_diff / 2;
		pair<ll, ll> res = ask_for_path_enhancement(
			curr_ends, children, curr_asking_distance, belongs_to_path
		);
		add_to_path(parents, curr_ends, res.first, belongs_to_path);
		curr_path_length += curr_asking_distance;

	}

	return curr_ends;
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


	pair<ll, ll> found = find_nodes(children, parents, root, orig_dist);

	cout << "! " << found.first + 1 << " " << found.second + 1 << endl << flush;
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
