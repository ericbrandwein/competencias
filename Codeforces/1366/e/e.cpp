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


const ll MOD = 998244353;

int main() {
	IOS;

	ll n, m;
	cin >> n >> m;

	vector<ll> a(n);
	vector<ll> b(m);

	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (ll i = 0; i < m; i++) {
		cin >> b[i];
	}

	ll ways = 1;
	ll curr_b = m - 1;
	ll curr_ways = 0;
	for (ll i = n - 1; i >= 0; i--) {
		if (a[i] == b[curr_b] || a[i] > b[curr_b] && curr_ways > 0) {
			curr_ways++;
		} else if (a[i] < b[curr_b]) {
			if (curr_b == 0) {
				ways = 0;
				break;
			}
			ways *= curr_ways;
			ways %= MOD;
			curr_b--;
			curr_ways = 0;
			i++;
		}
	}

	if (curr_ways == 0 || curr_b > 0) {
		ways = 0;
	}

	cout << ways << endl;

	return 0;
}
