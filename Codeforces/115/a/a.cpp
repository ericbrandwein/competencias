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

ll max_depth(vector<vector<ll>>& employees, ll manager) {
	ll maxd = 1;
	for (ll employee : employees[manager]) {
		maxd = max(maxd, max_depth(employees, employee) + 1);
	}
	return maxd;
}

int main() {
	IOS;

	ll n;
	cin >> n;
	vector<vector<ll>> employees(n);
	vector<ll> bosses;
	forn (i) {
		ll manager;
		cin >> manager;
		if (manager == -1) {
			bosses.push_back(i);
		} else {
			manager--;
			employees[manager].push_back(i);
		}
	}

	ll maxd = 0;
	for (ll boss : bosses) {
		maxd = max(maxd, max_depth(employees, boss));
	}

	cout << maxd << endl;



	return 0;
}
