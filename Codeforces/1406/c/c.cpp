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

ll get_max_comp(ll from, ll parent, vec<vec<ll>>& graph, vec<ll>& comp, vec<ll>& through) {
	ll children = 0;
	for (ll child : graph[from]) {
		if (child != parent) {
			ll component = get_max_comp(child, from, graph, comp, through);
			children += component;
			if (component > comp[from]) {
				through[from] = child;
			}
			comp[from] = max(comp[from], component);
		}
	}

	children++;
	if (comp[from] < (ll)graph.size() - children) {
		through[from] = parent;
	}
	comp[from] = max(comp[from], (ll)graph.size() - children);
	return children;
}


void solve() {
	ll n;
	cin >> n;

	vec<vec<ll>> graph(n);
	fore (i,0, n-1) {
		ll from, to;
		cin >> from >> to;
		from--; to--;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	vec<ll> max_comp(n, 0);
	vec<ll> through(n, -1);
	get_max_comp(0, -1, graph, max_comp, through);

	ll min_max = 0;
	ll amount = 1;
	ll other = -1;
	for (ll i = 0; i < n; i++) {
		if (max_comp[min_max] > max_comp[i]) {
			min_max = i;
			amount = 1;
		} else if (max_comp[min_max] == max_comp[i]) {
			amount++;
			other = i;
		}
	}

	pair<ll,ll> removed = {0, graph[0][0]};
	pair<ll,ll> added = {0, graph[0][0]};
	if (amount > 1) {
		ll removed_to = graph[other][0];
		for (ll i = 0; i < graph[min_max].size(); i++) {
			if (removed_to == graph[min_max][i] || removed_to == min_max) {
				removed_to = graph[other][1];
				break;
			}
		}

		removed = {other, removed_to};
		added = {min_max, removed_to};
	}

	cout << removed.first + 1 << " " << removed.second + 1 << endl;
	cout << added.first + 1 << " " << added.second + 1 << endl;

}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
