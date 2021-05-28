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

const ll MOD = 1e9 + 7;

void get_nodes_under(ll node, ll parent, vec<vec<ll>>& graph, vec<ll>& nodes_under, vec<ll>& weights) {
	ll n = graph.size();
	nodes_under[node] = 1;
	for (ll child : graph[node]) {
		if (child != parent) {
			get_nodes_under(child, node, graph, nodes_under, weights);
			nodes_under[node] += nodes_under[child];
		}
	}
	if (node != 0)
		weights.push_back(nodes_under[node] * (n - nodes_under[node]));
}

vec<ll> get_edges_weights(vec<vec<ll>>& graph) {
	ll n = graph.size();
	vec<ll> nodes_under(n, 0);
	vec<ll> weights;
	get_nodes_under(0, -1, graph, nodes_under, weights);
	return weights;
}

void solve() {
	ll n;
	cin >> n;
	vec<vec<ll>> graph(n);
	fore (i ,0 ,n-1) {
		ll from, to;
		cin >> from >> to;
		from--;
		to--;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	ll m;
	cin >> m;
	vec<ll> primes(m);
	fore (i, 0, m) cin >> primes[i];
	sort(primes.begin(), primes.end());
	while (primes.size() > n -1) {
		ll largest = primes.back();
		primes.pop_back();
		primes[primes.size() -1] *= largest;
		primes[primes.size() -1] %= MOD;
	}

	reverse(all(primes));
	while(primes.size() < n - 1) {
		primes.push_back(1);
	}

	vec<ll> weights = get_edges_weights(graph);
	sort(weights.rbegin(), weights.rend());
	ll total = 0;
	for (ll i = 0; i < weights.size(); i++) {
		total += (weights[i] * primes[i]) %MOD;
		total %= MOD;
	}
	cout << total << endl;

}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
