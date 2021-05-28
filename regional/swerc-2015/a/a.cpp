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

void mark_parent(ll node, vec<vec<bool>>& parents, ll parent, vec<vec<ll>>& graph) {
	parents[node][parent] = true;
	for (ll child : graph[node]) {
		if (!parents[child][parent]) {
			mark_parent(child, parents, parent, graph);
		}
	}
}

ll obligated(ll promotions, vec<ll>& children, ll n) {
	ll res = 0;
	forn (i) {
		ll not_children = n - children[i];
		if (not_children < promotions) res++;
	}
	return res;
}

int main() {
	IOS;


	ll a, b, n, m;
	cin >> a >> b >> n >> m;
	vec<vec<ll>> graph(n);
	fore (i, 0, m) {
		ll from, to;
		cin >> from >> to;
		graph[from].push_back(to);
	}
	vec<vec<bool>> parents(n, vec<bool>(n, false));
	forn (i) {
		mark_parent(i, parents, i, graph);
	}
	vec<ll> children(n, 0);
	forn (i) {
		forn (j) {
			if (parents[i][j]) {
				children[j]++;
			}
		}
	}

	cout << obligated(a, children, n) << endl;
	cout << obligated(b, children, n) << endl;
	ll no_posib = 0;
	forn (i) {
		ll padres = 0;
		forn (j) {
			if (parents[i][j]) padres++;
		}
		if (padres > b) {
			no_posib++;
		}
	}

	cout << no_posib << endl;



}
