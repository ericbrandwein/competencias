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
	string s;
	cin >> s;
	vec<set<ll>> graph(26);
	for (ll i = 0; i < s.size() - 1; i++) {
		graph[s[i]-'a'].insert(s[i+1] - 'a');
		graph[s[i+1]-'a'].insert(s[i] - 'a');
	}

	vec<ll> res;
	vec<ll> visited(26, false);
	ll lower = -1;
	for (ll i = 0; i < graph.size(); i++) {
		if (graph[i].empty()) {
			res.push_back(i);
			visited[i] = true;
		}
		if (graph[i].size() == 1) {
			lower = i;
		}
		if (graph[i].size() >= 3) {
			cout << "NO" << endl;
			return;
		}
	}

	if (res.size() < 26 && lower == -1) {
		cout << "NO" << endl;
		return;
	}


	for (ll i = 0; i < 26; i++) {
		if (graph[i].size() == 1) {
			res.push_back(i);
			visited[i] = true;
			ll prev = i;
			ll next = *(graph[prev].begin());
			graph[prev].erase(next);
			while (true) {
				visited[next] = true;
				graph[next].erase(prev);
				res.push_back(next);
				if (!graph[next].empty()) {
					ll nexti = *(graph[next].begin());
					if (visited[nexti]) {
						cout << "NO" << endl;
						return;
					}
					graph[next].clear();
					prev = next;
					next= nexti;
				} else {
					break;
				}
			}
		}
	}

	cout << "YES" << endl;
	for (ll i = 0; i < res.size(); i++) {
		cout << char('a' + res[i]);
	}
	cout << endl;





}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
