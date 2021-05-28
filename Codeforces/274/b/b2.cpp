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

    vector<ll> parents(n, -1);
    stack<ll> change_order = get_change_order(graph, parents);
    vector<Change> changes(n, {0, 0});
    while (!change_order.empty()) {
        ll current_node = change_order.top(); change_order.pop();
        for (ll child : graph[current_node]) {
            if (child != parents[current_node]) {
                changes[current_node].up = max(
                    changes[current_node].up,
                    changes[child].up
                );
                changes[current_node].down = max(
                    changes[current_node].down,
                    changes[child].down
                );
            }
        }

        ll my_cost = costs[current_node] +
            changes[current_node].up - changes[current_node].down;
        if (my_cost > 0) {
            changes[current_node].down += my_cost;
        } else {
            changes[current_node].up += -my_cost;
        }
    }



	cout << changes[0].up + changes[0].down << endl;


	return 0;
}