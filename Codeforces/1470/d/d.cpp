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
	ll n, m;
	cin >> n >> m;

	vec<vec<ll>> graph(n);
	fore (i, 0, m) {
		ll from, to;
		cin >> from >> to;
		from--;
		to--;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}


	vec<bool> usable(n, true);
	stack<ll> next;
	vec<ll> used;
	next.push(0);
	while (!next.empty()) {
		ll curr = next.top();
		next.pop();
		if (usable[curr]) {
			used.push_back(curr);
			for (ll child : graph[curr]) {
				if (usable[child]) {
					usable[child] = false;
					next.push(child);
				}
			}
			usable[curr] = false;
		} else {
			for (ll child : graph[curr]) {
				if (usable[child]) {
					next.push(child);
				}
			}
		}
	}
	for (bool not_valid : usable) {
		if (not_valid) {
			cout << "NO" << endl;
			return;
		}
	}

	cout << "YES" << endl;
	cout << used.size() << endl;
	for (ll num : used) cout << num + 1 << " ";
	cout << endl;
}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();
}
