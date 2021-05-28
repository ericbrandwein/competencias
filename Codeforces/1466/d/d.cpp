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

void solve() {
	ll n;
	cin >> n;
	vec<ll> weights(n);
	map<ll,vec<ll>> biggest;
	ll sum = 0;
	forn (i) {
		cin >> weights[i];
		biggest[weights[i]].push_back(i);
		sum += weights[i];
	}

	vec<vec<ll>> graph(n);
	fore (i, 0, n-1) {
		ll from, to;
		cin >> from >> to;
		from--;
		to--;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	cout << sum << " ";
	for (ll k = 2; k <= n - 1; k++) {
		if (!biggest.empty()) {
			auto it = --biggest.end();
			ll weight = it->first;
			ll node = it->second.back();
			while (graph[node].size() == 1) {
				it->second.pop_back();
				if (it->second.empty()) {
					biggest.erase(it);
					if (biggest.empty()) {
						break;
					} else {
						it = --biggest.end();
						weight = it->first;
					}
				}
				node = it->second.back();
			}
			if (!biggest.empty()) {
				sum += weight;
				graph[node].pop_back();
			}
		}
		cout << sum << " ";
	}

	cout << endl;
}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}
