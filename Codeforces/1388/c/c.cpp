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


bool possible(vec<vec<ll>>& graph, vec<ll>& visitors, vec<ll>& measured) {
	ll n = graph.size();

	stack<ll> next;
	next.push(0);
	vector<bool> visited(n, false);
	vector<bool> added_to_stack(n, false);
	added_to_stack[0] = true;
	vector<ll> good_mood(n, 0);
	while (!next.empty()) {
		ll curr = next.top();
		if (visited[curr]) {
			// visitamos los hijos
			ll needed = 0;
			for (ll child : graph[curr]) {
				needed += good_mood[child];
			}

			ll bad_mood = visitors[curr] - measured[curr];
			if (bad_mood % 2 != 0 || bad_mood < 0) {
				return false;
			}
			bad_mood /= 2;
			good_mood[curr] = visitors[curr] - bad_mood;

			if (good_mood[curr] < needed) {
				return false;
			}

			next.pop();
		} else {
			for (ll child : graph[curr]) {
				if (!added_to_stack[child]) {
					next.push(child);
					added_to_stack[child] = true;
				}
			}
			visited[curr] = true;
		}
	}

	return true;

}


void solve() {
	ll n, peopleq;
	cin >> n >> peopleq;

	vector<ll> living(n);
	forn (i) {
		cin >> living[i];
	}

	vector<ll> measured(n);
	forn (i) {
		cin >> measured[i];
	}

	vector<vec<ll>> graph(n);
	fore (i, 0, n - 1) {
		ll from, to;
		cin >> from >> to;
		from--;
		to--;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	vec<ll> visitors(n, 0);
	stack<ll> next;
	next.push(0);
	vector<bool> visited(n, false);
	vector<bool> added_to_stack(n, false);
	added_to_stack[0] = true;
	while (!next.empty()) {
		ll curr = next.top();
		if (visited[curr]) {
			// ya visitamos todos sus hijos
			for (ll child : graph[curr]) {
				visitors[curr] += visitors[child];
			}
			visitors[curr] += living[curr];
			next.pop();
		} else {
			for (ll child : graph[curr]) {
				if (!added_to_stack[child]) {
					next.push(child);
					added_to_stack[child] = true;
				}
			}
			visited[curr] = true;
		}
	}

	if (possible(graph, visitors, measured)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}









}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
