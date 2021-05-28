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

struct Edge {
	ll from, to, color = 1;
};

void dfs(
	ll from, 
	vector<bool>& visited, vector<bool>& parenting, 
	vector<Edge>& edges, vector<vector<ll>>& edges_for_vertex) {

	visited[from] = true;
	parenting[from] = true;
	for (auto& index: edges_for_vertex[from]) {
		ll dest = edges[index].to;
		if (visited[dest] && parenting[dest]) {
			edges[index].color = 2;
		} else if (!visited[dest]) {
			dfs(dest, visited, parenting, edges, edges_for_vertex);
		}
	}
	parenting[from] = false;
}

int main() {
	IOS;

	ll vertices_q, edges_q;
	cin >> vertices_q >> edges_q;

	vector<Edge> edges;
	vector<vector<ll>> edges_for_vertex(vertices_q + 1);
	fore (i, 0, edges_q) {
		Edge edge;
		cin >> edge.from >> edge.to;
		edges.push_back(edge);
		edges_for_vertex[edge.from].push_back(i);
	}

	vector<bool> parenting(vertices_q + 1, false);
	vector<bool> visited(vertices_q + 1, false);
	for (ll i = 1; i <= vertices_q; i++) {
		if (!visited[i]) {
			dfs(i, visited, parenting, edges, edges_for_vertex);
		}
	}

	ll max_color = 1;
	for (auto& edge: edges) {
		max_color = max(max_color, edge.color);
	}
	cout << max_color << endl;
	fore (i, 0, edges.size()) {
		cout << edges[i].color;
		if (i < edges.size() - 1) {
			cout << " ";
		}
	}
	cout << endl;

	return 0;
}
