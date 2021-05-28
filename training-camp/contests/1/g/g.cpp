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

int main() {
	IOS;

	ll n, k;
	cin >> n>> k;

	vector<vector<ll>> graph(n);
	fore (i, 0, n-1) {
		ll from, to;
		cin >> from >> to;
		from--;
		to--;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	if (n == 1) {
		cout << "No" << endl;
		return 0;
	}
	ll some_hoja = -1;
	forn (i) {
		if (graph[i].size() == 1) {
			some_hoja = i;
			break;
		}
	}

	ll middle = -1;
	ll longest = 0;
	vector<ll> curr_path;
	vector<bool> visited(n, false);
	stack<ll> next_aristas;
	next_aristas.push(some_hoja);
	while (!next_aristas.empty()) {
		ll curr = next_aristas.top();
		if (visited[curr]) {
			next_aristas.pop();
			curr_path.pop_back();
		} else {
			curr_path.push_back(curr);
			for (ll connected : graph[curr]) {
				if (!visited[connected]) {
					next_aristas.push(connected);
				}
			}
			visited[curr] = true;
			if (curr_path.size() > longest) {
				longest = curr_path.size();
				middle = curr_path[curr_path.size() / 2];
			}
		}
	}
	if (longest / 2 != k) {
		cout << "No" << endl;
		return 0;
	}

	ll root = middle;

	vector<ll> parents(n, -1);

	visited = vector<bool>(n, false);
	stack<ll> next;
	next.push(root);
	while (!next.empty()) {
		ll curr = next.top();
		next.pop();
		visited[curr] = true;

		for (ll child : graph[curr]) {
			if (!visited[child]) {
				parents[child] = curr;
				next.push(child);
			}
		}
	}

	queue<ll> next_lower;
	fore (i, 0, n) {
		if (graph[i].size() == 1) {
			next_lower.push(i);
		}
	}

	vector<ll> hijos(n, 0);
	vector<ll> alturas(n, 0);
	while (!next_lower.empty()) {
		ll curr = next_lower.front();
		next_lower.pop();
		ll parent = parents[curr];
		if (parent != -1) {
			hijos[parent]++;
			if (alturas[parent] == 0) {
				alturas[parent] = alturas[curr] + 1;
				next_lower.push(parent);
			} else if (alturas[parent] != alturas[curr] + 1) {
				cout << "No" << endl;
				return 0;
			}
		}

		if (hijos[curr] > 0 && hijos[curr] < 3) {
			cout << "No" << endl;
			return 0;
		}
	}


	cout << "Yes" << endl;



	return 0;
}
