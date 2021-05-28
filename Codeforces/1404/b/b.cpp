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

void calc_dist(vec<vec<ll>>& graph, ll from, vec<ll>& dist) {
	for (ll child : graph[from]) {
		if (dist[child] == -1) {
			dist[child] = dist[from] + 1;
			calc_dist(graph, child, dist);
		}
	}
}

vec<ll> dist(vec<vec<ll>>& graph, ll from) {
	ll n = graph.size();
	vec<ll> dists(n, -1);
	dists[from] = 0;
	calc_dist(graph, from, dists);

	return dists;
}


void solve() {
	ll n, a, b, da, db;
	cin >> n >> a >> b >> da >> db;
	a--;
	b--;
	vec<vec<ll>> graph(n);
	fore (i, 0, n-1) {
		ll from, to;
		cin >> from >> to;
		from--;
		to--;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	vec<ll> dists = dist(graph, a);
	if (db < 2*da + 1 || dists[b] <= da) {
		cout << "Alice" << endl;
		return;
	}

	ll mas_lejos = a;
	for (ll i = 0; i < n; i++) {
		if (dists[mas_lejos] < dists[i]) {
			mas_lejos = i;
		}
	}

	vec<ll> double_dists = dist(graph, mas_lejos);
	ll mas_largo = 0;
	for (ll i = 0; i < n; i++) {
		mas_largo = max(mas_largo, double_dists[i]);
	}

	if (mas_largo + 1 >= 2*da + 2) {
		cout << "Bob" << endl;
	} else {
		cout << "Alice" << endl;
	}



}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
