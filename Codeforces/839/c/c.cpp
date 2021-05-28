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

ld calculate_expectancy(vec<vec<ll>>& graph, ll node, ll parent) {
	ld expectancy = 0;

	for (ll child : graph[node]) {
		if (child != parent) {
			expectancy += 1 + calculate_expectancy(graph, child, node);
		}
	}
	if (expectancy != 0) {
		if (parent != -1) {
			expectancy /= graph[node].size() - 1;
		} else {
			expectancy /= graph[node].size();
		}
	}
	return expectancy;
}

int main() {
	IOS;

	ll n;
	cin >> n;
	vec<vec<ll>> graph(n);
	fore (i, 0, n-1) {
		ll from, to;
		cin >> from >> to;
		from--;
		to--;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	presicion(15);
	cout << calculate_expectancy(graph, 0, -1) << endl;
}
