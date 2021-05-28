//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK: 2000000")
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

vec<ll> get_component(
	ll node, vec<vec<ll>>& graph, vec<bool>& infected, vec<bool>& visited
) {
	vec<ll> component;
	stack<ll> next;
	next.push(node);
	while (!next.empty()) {
		ll curr = next.top();
		next.pop();
		component.push_back(curr);
		visited[curr] = true;
		for (ll child : graph[curr]) {
			if (!visited[child] && !infected[child]) {
				next.push(child);
			}
		}
	}
	return component;
}

vec<vec<ll>> get_components(vec<vec<ll>>& graph, vec<bool>& infected) {
	ll n = graph.size();
	vec<bool> visited(n, false);
	vec<vec<ll>> components;
	for (ll i = 0; i < n; i++) {
		if (!visited[i] && !infected[i]) {
			components.push_back(get_component(i, graph, infected, visited));
		}
	}
	return components;
}

ll get_nodes_below(ll node, vec<vec<ll>>& graph, vec<ll>& nodes_below) {
	nodes_below[node]++;
	for (ll child : graph[node]) {
		if (nodes_below[child] == 0) {
			nodes_below[node] += get_nodes_below(child, graph, nodes_below);
		}
	}
	return nodes_below[node];
}


ll get_good_nodes_below(
	ll node, vec<vec<ll>>& graph, vec<bool>& infected, vec<ll>& nodes_below
) {
	nodes_below[node] = -1;
	for (ll child : graph[node]) {
		if (nodes_below[child] == 0) {
			nodes_below[node] += get_good_nodes_below(child, graph, infected, nodes_below);
		}
	}
	nodes_below[node]++;
	if (!infected[node]) nodes_below[node]++;
	return nodes_below[node];
}

ll path_pairs_for_one_component(
	ll node, ll parent, vec<vec<ll>>& graph, vec<ll>& nodes_below, vec<ll>& good_nodes_below,
	vec<bool>& infected, ll component_size
) {
	ll n = graph.size();
	ll total = 0;
	for (ll child : graph[node]) {
		if (child != parent) {
			total += path_pairs_for_one_component(
				child, node, graph, nodes_below, good_nodes_below, infected, component_size);
			if (infected[child] || infected[node]) {
				total += nodes_below[child] * (n - nodes_below[child]);
			} else {
				total += good_nodes_below[child] * (component_size - good_nodes_below[child]);
			}
		}
	}
	return total;
}

void solve_for_one_component(vec<vec<ll>>& graph, vec<bool>& infected, ll component_size) {
	ll n = graph.size();
	vec<ll> nodes_below(n, 0);
	get_nodes_below(0, graph, nodes_below);

	vec<ll> good_nodes_below(n, 0);
	get_good_nodes_below(0, graph, infected, good_nodes_below);

	ll patient_pairs = component_size * (component_size - 1) / 2;

	ll path_pairs = path_pairs_for_one_component(
		0, -1, graph, nodes_below, good_nodes_below, infected, component_size);

	cout << patient_pairs << " " << path_pairs << endl;
}

void calculate_components_below(
	ll node, ll parent, vec<vec<ll>>& graph, vec<bool>& infected, vec<ll>& component_sizes,
	vec<ll>& components_below, ll max_component_size
) {
	for (ll child : graph[node]) {
		if (child != parent) {
			calculate_components_below(
				child, node, graph, infected,
				component_sizes, components_below, max_component_size);
			if (!infected[node]) component_sizes[node] += component_sizes[child];
		}
	}
	if (!infected[node]) component_sizes[node]++;
	if (component_sizes[node] == max_component_size) components_below[node]++;
	for (ll child : graph[node]) {
		if (child != parent) {
			components_below[node] += components_below[child];
			if (!infected[node] && component_sizes[child] == max_component_size) {
				components_below[node]--;
			}
		}
	}
}


void solve_for_multiple_components(
	vec<vec<ll>>& graph, vec<bool>& infected, vec<vec<ll>>& components
) {
	ll n = graph.size();
	vec<ll> sizes(components.size());
	for (ll i = 0; i < components.size(); i++) {
		sizes[i] = components[i].size();
	}

	sort(sizes.rbegin(), sizes.rend());

	vec<ll> component_sizes(n, 0);
	vec<ll> components_below(n, 0);
	ll max_component_size = sizes[0];
	ll second_component_size = sizes[1];
	ll patient_pairs = (max_component_size + second_component_size) * (max_component_size + second_component_size - 1) / 2;
	for (ll i = 2; i < sizes.size(); i++) {
		patient_pairs += sizes[i] * (sizes[i] - 1) / 2;
	}
	ll path_pairs = 0;
	if (sizes[0] == sizes[1]) {
		ll max_components_amount = count(sizes.begin(), sizes.end(), max_component_size);
		calculate_components_below(
			0, -1, graph, infected, component_sizes, components_below, max_component_size);

		// hay que sumar para cada arista mala los nodos de abajo
		stack<ll> next;
		next.push(0);
		vec<bool> visited(n, false);
		while (!next.empty()) {
			ll curr = next.top();
			next.pop();
			visited[curr] = true;
			for (ll child : graph[curr]) {
				if (!visited[child]) {
					next.push(child);
					if (infected[child] || infected[curr]) {
						path_pairs +=
							components_below[child] * max_component_size *
							(max_components_amount - components_below[child]) * max_component_size;
					}
				}
			}
		}


	} else {
		ll second_components_amount = count(sizes.begin(), sizes.end(), second_component_size);
		vec<ll> components_max_below(n, 0);
		calculate_components_below(
			0, -1, graph, infected, component_sizes, components_max_below, max_component_size);
		component_sizes = vec<ll>(n, 0);
		calculate_components_below(
			0, -1, graph, infected, component_sizes, components_below, second_component_size);


		// hay que sumar para cada arista mala los nodos de abajo
		stack<ll> next;
		next.push(0);
		vec<bool> visited(n, false);
		while (!next.empty()) {
			ll curr = next.top();
			next.pop();
			visited[curr] = true;
			for (ll child : graph[curr]) {
				if (!visited[child]) {
					next.push(child);
					if (infected[child] || infected[curr]) {
						ll multiplied = components_below[child];
						if (components_max_below[child] == 1) {
							multiplied = second_components_amount - components_below[child];
						}
						path_pairs +=
							multiplied * second_component_size * max_component_size;
					}
				}
			}
		}
	}


	cout << patient_pairs << " " << path_pairs << endl;
}


void solve() {
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vec<bool> infected(s.size(), false);
	for (ll i = 0; i < s.size(); i++) {
		infected[i] = s[i] == '#';
	}
	vector<ll> parents(n);
	fore (i, 1, k+1) {
		cin >> parents[i];
	}

	ll a,b,c;
	cin >> a >> b >> c;
	fore (i, k+1, n) {
		parents[i] = ((a*parents[i-2] + b*parents[i-1] + c) % i) + 1;
	}

	vec<vec<ll>> graph(n);
	fore (i, 1, n) {
		ll parent = parents[i];
		parent--;
		graph[parent].push_back(i);
		graph[i].push_back(parent);
	}

	vec<vec<ll>> components = get_components(graph, infected);
	if (components.size() <= 1) {
		ll component_size = 0;
		if (components.size() == 1) component_size = components[0].size();
		solve_for_one_component(graph, infected, component_size);
	} else {
		solve_for_multiple_components(graph, infected, components);
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
