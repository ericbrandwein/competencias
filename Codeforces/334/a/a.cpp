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
	vector<vector<int>> bags(n);

	ll bag = 0;
	for (ll i = 1; i <= n * n; i++) {
		bags[bag].push_back(i);
		if (i % n != 0) {
			if ((i / n) % 2 == 0) {
				bag++;
			} else {
				bag--;
			}
		}
	}

	for (ll i = 0;i < n; i++) {
		for (ll j = 0; j < bags[i].size(); j++) {
			cout << bags[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
