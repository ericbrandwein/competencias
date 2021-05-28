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

	// Voy en orden con con los del topic i:
	// -- Si en sus neghbors ya está el topic i, no se puede
	// -- Si en sus neighbors no está alguno de los de topic menor a i, no se puede
	// -- Sino, todo bien

	ll n, m;
	cin >> n >> m;

	vector<vector<ll>> graph(n);
	set<pair<ll, ll>> topics;
	fore (i, 0, m) {
		ll from, to;
		cin >> from >> to;
		from--;
		to--;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	vector<ll> topics_for(n);
	forn (i) {
		cin >> topics_for[i];
		topics.insert({topics_for[i], i});
	}

	for (pair<ll, ll> topic_pair : topics) {
		ll topic = topic_pair.first;
		ll node = topic_pair.second;

		vector<bool> present(topic, false);
		for (ll neighbor : graph[node]) {
			if (topics_for[neighbor] == topic) {
				cout << -1 << endl;
				return 0;
			}
			if (topics_for[neighbor] < topic) {
				present[topics_for[neighbor]] = true;
			}
		}

		fore (i, 1, present.size()) {
			if (!present[i]) {
				cout << -1 << endl;
				return 0;
			}
		}
	}

	for (pair<ll, ll> topic_pair : topics) {
		cout << topic_pair.second + 1 << " ";
	}
	cout << endl;



	return 0;
}
