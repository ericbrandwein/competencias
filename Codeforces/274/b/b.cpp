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

struct Change {
	ll up, down;
};

Change change_for(ll node, vector<vector<ll>>& graph, vector<ll>& costs, ll parent) {
	Change change = {0, 0};
	for (ll child : graph[node]) {
		if (child != parent) {
			Change child_change = change_for(child, graph, costs, node);
			change.up = max(change.up, child_change.up);
			change.down = max(change.down, child_change.down);
		}
	}

	ll my_cost = costs[node] + change.up - change.down;
	if (my_cost > 0) {
		change.down += my_cost;
	} else {
		change.up += -my_cost;
	}

	return change;
}

int main() {
	IOS;

	ll n;
	cin >> n;
	vector<vector<ll>> graph(n);
	fore (i, 0, n - 1) {
		ll from, to;
		cin >> from >> to;
		from--;
		to--;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	vector<ll> costs(n);
	forn (i) {
		cin >> costs[i];
	}

	Change change = change_for(0, graph, costs, -1);
	cout << change.up + change.down << endl;


	return 0;
}
