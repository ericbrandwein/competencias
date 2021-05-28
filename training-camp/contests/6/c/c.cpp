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

ll cost_starting_from(
	vector<vec<ll>>& depende, vector<bool>& depende_alguien_de, vector<ll>& labs,
	ll from
) {
	// Por todos los que no dependa nadie quiero encontrar el nivel

	ll n = depende.size();
	vector<ll> costs(n, -1);
	stack<ll> next;
	for (ll i = 0; i < depende_alguien_de.size(); i++) {
		if (!depende_alguien_de[i]) {
			next.push(i);
		}
	}

	ll total_cost = 0;

	vector<bool> visited(n, false);
	while(!next.empty()) {
		ll curr = next.top();
		if (visited[curr]) {
			// ya visite todo los hijos
			next.pop();
			if (costs[curr] == -1) {
				// ir por cada hijo
				for (ll child : depende[curr]) {
					if (labs[child] == labs[curr]) {
						costs[curr] = max(costs[curr], costs[child]);
					} else {
						costs[curr] = max(costs[curr], costs[child] + 1);
					}
				}
				if (depende[curr].empty()) {
					if (labs[curr] == from) {
						costs[curr] = 0;
					} else {
						costs[curr] = 1;
					}
				}
			}
			total_cost = max(total_cost, costs[curr]);
		} else {
			for (ll child : depende[curr]) {
				next.push(child);
			}
		}
		visited[curr] = true;
	}

	return total_cost;
}


void solve() {
	ll n, m;
	cin >> n >> m;

	vector<ll> labs(n, 0);
	forn (i) {
		cin >> labs[i];
	}

	vector<vector<ll>> depende(n);
	vector<bool> depende_alguien_de(n, false);
	fore (i, 0, m) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		depende[b].push_back(a);
		depende_alguien_de[a] = true;
	}


	ll cost = cost_starting_from(depende, depende_alguien_de, labs, 1);
	cost = min(cost, cost_starting_from(depende, depende_alguien_de, labs, 2));

	cout << cost << endl;

}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}

/*
1
5 6
1 2 1 2 1
1 2
1 3
2 4
3 4
2 5
3 5
*/