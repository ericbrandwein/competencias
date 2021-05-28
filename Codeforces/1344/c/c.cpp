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

bool visit(vec<vec<ll>>& graph, vec<ll>& visited, ll node, ll number) {
	if (!visited[node]) {
		visited[node] = number;
		bool valid = true;
		for (ll child : graph[node]) {
			valid &= visit(graph, visited, child, number);
		}
		visited[node] = -1;
		return valid;
	} else if (visited[node] == number) {
		return false;
	} else {
		return true;
	}
}

bool is_cycle(vec<vec<ll>>& graph) {
	ll n = graph.size();
	vec<ll> visited(n, 0);
	ll curr_dag = 1;
	forn (i) {
		if (!visited[i]) {
			bool valid = visit(graph, visited, i, curr_dag);
			if (!valid) return true;
		}
	}
	return false;
}

ll calc_min_next(vec<vec<ll>>& graph, ll node, vec<ll>& min_next) {
	if (min_next[node] == -1) {
		min_next[node] = node;
		for (ll child : graph[node]) {
			min_next[node] = min(
				min_next[node],
				calc_min_next(graph, child, min_next)
			);
		}
	}
	return min_next[node];
}

vec<ll> calculate_min_next(vec<vec<ll>>& graph) {
	ll n = graph.size();
	vec<ll> min_nexts(n, -1);
	forn (i) {
		calc_min_next(graph, i, min_nexts);
	}
	return min_nexts;
}

int main() {
	IOS;

	ll n, m;
	cin >> n >> m;
	vec<vec<ll>> graph(n);
	vec<vec<ll>> alvesre(n);
	fore (i, 0, m) {
		ll from, to;
		cin >> from >> to;
		from--;
		to--;
		graph[from].push_back(to);
		alvesre[to].push_back(from);
	}


	if (is_cycle(graph)) {
		cout << -1 << endl;
		return 0;
	}

	string res(n, 'E');
	ll total = 0;

	vec<ll> min_path = calculate_min_next(graph);
	vec<ll> min_prevs = calculate_min_next(alvesre);
	forn (i) {
		min_path[i] = min(min_path[i], min_prevs[i]);
		if (min_path[i] == i) {
			res[i] = 'A';
			total++;
		}
	}

	cout << total << endl;
	cout << res << endl;





	return 0;
}
