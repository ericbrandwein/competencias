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

struct Changing {
	ll from, to;
	ll cost;
};

int main() {
	IOS;

	string s;
	string t;
	cin >> s >> t;

	ll n;
	cin >> n;
	vector<Changing> changings(n);
	forn (i) {
		char from, to;
		cin >> from >> to >> changings[i].cost;
		changings[i].from = from - 'a';
		changings[i].to = to -'a';
	}

	ll abcd = 'z' - 'a' + 1;

	ll inf = LONG_LONG_MAX / 2;
	vector<vector<ll>> dist(abcd, vector<ll>(abcd, inf));
	for (ll i = 0; i < dist.size(); i++) {
		dist[i][i] = 0;
	}
	for (ll i = 0; i < changings.size(); i++) {
		ll from = changings[i].from;
		ll to = changings[i].to;
		ll cost = changings[i].cost;
		dist[from][to] = min(dist[from][to], cost);
	}

	for (ll k = 0; k < abcd; k++) {
		for (ll i = 0; i < abcd; i++) {
			for (ll j = 0; j < abcd; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	if (s.size() != t.size()) {
		cout << -1 << endl;
		return 0;
	}

	ll total = 0;
	string res = "";
	for (ll i = 0; i < s.size(); i++) {
		ll si = s[i] - 'a';
		ll ti = t[i] - 'a';
		ll min_dist = inf;
		ll curr_max = 0;
		for (ll letra = 0; letra < abcd; letra++) {
			ll sum = dist[si][letra] + dist[ti][letra];
			if (sum < min_dist) {
				curr_max = letra;
				min_dist = sum;
			}
		}

		if (min_dist == inf) {
			cout << -1 << endl;
			return 0;
		} else {
			total += min_dist;
			res.push_back(curr_max + 'a');
		}
	}


	cout << total << endl;
	cout << res <<endl;



	return 0;
}
