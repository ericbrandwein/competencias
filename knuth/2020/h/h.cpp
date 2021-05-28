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

ll sum_cycle(vector<bool>& visited, vector<ll>& permutation, ll from) {
	visited[from] = true;
	ll curr = permutation[from];
	ll total = 1;
	while (curr != from) {
		visited[curr] = true;
		curr = permutation[curr];
		total++;
	}
	return total - 1;
}


void solve() {
	ll n, ops;
	cin >> n >> ops;

	vector<ll> permutation(n);
	forn (i) {
		cin >> permutation[i];
		permutation[i]--;
	}

	vector<bool> visited(n, false);
	ll cycle_sum = 0;
	forn (i) {
		if (!visited[i]) {
			cycle_sum += sum_cycle(visited, permutation, i);
		}
	}

	if (ops >= cycle_sum && (ops - cycle_sum) % 2 == 0) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
