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

struct DfsState {
    ll node, parent;
};

stack<ll> get_change_order(vector<vector<ll>>& graph, vector<ll>& parents) {
    stack<ll> change_order;
    stack<ll> current_path;
    current_path.push(0);
    while (!current_path.empty()) {
        ll current_node = current_path.top(); current_path.pop();
        change_order.push(current_node);
        for (ll child : graph[current_node]) {
            if (child != parents[current_node]) {
                parents[child] = current_node;
                current_path.push(child);
            }
        }
    }

    return change_order;
}

Change get_change(vector<vector<ll>>& graph, vector<ll>& costs) {
    Change result;

    vector<bool> visited(graph.size(), false);
    stack<Change> current_path_changes;
    stack<DfsState> next;
    next.push({0, -1});
    while (!next.empty()) {
        DfsState& current_state = next.top();
        if (visited[current_state.node]) {
            next.pop();
            Change current_change = current_path_changes.top();
            current_path_changes.pop();
            ll my_cost = costs[current_state.node] + current_change.up - current_change.down;
            if (my_cost > 0) {
                current_change.down += my_cost;
            } else {
                current_change.up += -my_cost;
            }

            if (current_path_changes.empty()) {
                result = current_change;
            } else {
                Change& parent_change = current_path_changes.top();
                parent_change.up = max(parent_change.up, current_change.up);
                parent_change.down = max(parent_change.down, current_change.down);
            }
        } else {
            visited[current_state.node] = true;
            current_path_changes.push({0, 0});
            for (ll child : graph[current_state.node]) {
                if (child != current_state.parent) {
                    next.push({child, current_state.node});
                }
            }
        }
    }

    return result;
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

    Change change = get_change(graph, costs);
	cout << change.up + change.down << endl;


	return 0;
}
