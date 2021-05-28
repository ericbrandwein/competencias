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

	ll n, m;
	cin >> n >> m;
	vector<ll> colors(n);
	forn (i) {
		cin >> colors[i];
	}

	map<ll, set<ll>> neighbors;
	fore (i, 0, m) {
		ll from, to;
		cin >> from >> to;
		from--;
		to--;

		if (colors[from] != colors[to]) {
			neighbors[colors[from]].insert(colors[to]);
			neighbors[colors[to]].insert(colors[from]);
		}
	}

	ll max_size = 0;
	ll max_color = 0;
	for (auto& entry : neighbors) {
		if (entry.second.size() > max_size) {
			max_size = entry.second.size();
			max_color = entry.first;
		}
	}

	if (max_size == 0) {
		cout << *min_element(colors.begin(), colors.end()) << endl;
	} else {
		cout << max_color << endl;
	}

	return 0;
}
