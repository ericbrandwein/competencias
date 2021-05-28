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

void max_for(ll node, ll parent, vec<vec<ll>>& graph, vec<vec<ll>>& prices, vec<ll>& left, vec<ll>& right) {
	for (ll child : graph[node]) {
		if (child != parent) {
			max_for(child, node, graph, prices, left, right);
			ll max_dist_left = max(
				abs(left[node] - left[child]) + prices[child][0],
				abs(left[node] - right[child]) + prices[child][1]
			);
			prices[node][0] += max_dist_left;
			ll max_dist_right = max(
				abs(right[node] - left[child]) + prices[child][0],
				abs(right[node] - right[child]) + prices[child][1]
			);
			prices[node][1] += max_dist_right;
		}
	}
}

void solve() {
	ll n;
	cin >> n;
	vec<ll> left(n), right(n);
	forn (i) {
		cin >> left[i] >> right[i];
	}
	vec<vec<ll>> graph(n);
	fore (i,0 ,n-1) {
		ll from, to;
		cin >> from >> to;
		from--;
		to--;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	vec<vec<ll>> prices(n, vec<ll>(2, 0));
	max_for(0, -1, graph, prices, left, right);
	cout << max(prices[0][0], prices[0][1]) << endl;

}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();


}
