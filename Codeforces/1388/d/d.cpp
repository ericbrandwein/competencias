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

	ll n;
	cin >> n;

	vec<ll> a(n);
	forn (i) {
		cin >> a[i];
	}

	vec<ll> b(n);
	forn (i) {
		cin >> b[i];
		b[i]--;
	}


	vec<vec<ll>> parents(n);
	for (ll i = 0; i < n; i++) {
		if (b[i] != -2) {
			parents[b[i]].push_back(i);
		}
	}


	queue<ll> firsts;
	forn(i) {
		if (parents[i].empty()) firsts.push(i);
	}

	vec<ll> ending;
	vec<ll> beginning;

	vec<ll> parents_visited(n, 0);
	ll sum = 0;
	while (!firsts.empty()) {
		ll curr= firsts.front();
		firsts.pop();
		if (a[curr] >= 0) {
			beginning.push_back(curr);
			if (b[curr] != -2) {
				a[b[curr]] += a[curr];
			}
		} else {
			ending.push_back(curr);
		}
		if (b[curr] != -2) {
			parents_visited[b[curr]]++;
			if (parents_visited[b[curr]] == parents[b[curr]].size()) {
				firsts.push(b[curr]);
			}
		}
		sum += a[curr];
	}

	reverse(all(ending));
	cout << sum << endl;

	for (ll i = 0; i < beginning.size(); i++) {
		cout << beginning[i] + 1 << " ";
	}
	for (ll i = 0; i < ending.size(); i++) {
		cout << ending[i] + 1 << " ";
	}
	cout << endl;


	return 0;
}
