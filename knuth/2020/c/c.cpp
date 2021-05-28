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

ll max_type(ll from, ll to, vector<vector<ll>>& graph, vector<ll>& types) {
	ll n = graph.size();

	stack<ll> next;
	next.push(from);
	vector<ll> path;
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

	ll dist = path.size();
	ll min_amount = dist/2;
	map<ll, ll> types_amount;
	for (ll node : path) {
		types_amount[types[node]]++;
		if (types_amount[types[node]] > min_amount) {
			return types[node];
		}
	}
	return -1;
}

int main() {
	IOS;

	ll n;
	cin >> n;
	vector<ll> types(n);
	forn (i) cin >> types[i];

	vector<vector<ll>> graph(n);
	fore (i, 0, n - 1) {
		ll from, to;
		cin >> from >> to;
		from--;
		to--;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	ll q;
	cin >> q;
	fore (i, 0, q) {
		ll t;
		cin >> t;
		if (t == 1) {
			ll from, to;
			cin >> from >> to;
			from--;
			to--;
			cout << max_type(from, to, graph, types) << endl;
		} else {
			ll node, type;
			cin >> node >> type;
			node--;
			types[node] = type;
		}
	}




	return 0;
}
