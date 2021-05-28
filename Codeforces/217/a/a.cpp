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

void connect(vector<bool>& visited, ll drift, vector<pair<int, int>>& drifts,
		vector<vector<ll>>& xs, vector<vector<ll>>& ys) {
	stack<ll> next;
	next.push(drift);
	while (!next.empty()) {
		ll actual = next.top(); next.pop();
		for (ll iter : xs[drifts[actual].first]) {
			if (!visited[iter]) {
				visited[iter] = true;
				next.push(iter);
			}
		}
		for (ll iter : ys[drifts[actual].second]) {
			if (!visited[iter]) {
				visited[iter] = true;
				next.push(iter);
			}
		}
	}
}


int main() {
	IOS;

	ll n;
	cin >> n;
	vector<pair<int, int>> drifts(n);
	vector<vector<ll>> xs(1001);
	vector<vector<ll>> ys(1001);
	forn (i) {
		cin >> drifts[i].first >> drifts[i].second;
		xs[drifts[i].first].push_back(i);
		ys[drifts[i].second].push_back(i);
	}

	vector<bool> visited(n, false);
	ll components = 0;
	forn (i) {
		if (!visited[i]) {
			components++;
			connect(visited, i, drifts, xs, ys);
		}
	}

	cout << components - 1 << endl;



	return 0;
}
