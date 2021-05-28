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

	string rap;
	cin >> rap;

	vec<ll> costs(2, 0); // 10, 01
	fore (i, 0, 2) cin >> costs[1-i];
	ll first = 0;
	ll second = 1;
	if (costs[0] < costs[1]) swap(first, second);
	vec<vec<ll>> before(rap.size(), vec<ll>(2, 0));
	vec<ll> amount(2, 0);
	ll total = 0;
	before[0][0] = 0;
	before[0][1] = 0;
	if (rap[0] == '?') {
		amount[second]++;
	} else {
		amount[rap[0]-'0']++;
	}
	for (ll i = 1; i < rap.size(); i++) {
		for (ll num = 0; num < 2; num++) {
			before[i][num] = before[i-1][num];
		}
		if (rap[i-1] == '?') {
			before[i][second]++;
		} else {
			before[i][rap[i-1]-'0']++;
		}
		ll curr = rap[i] - '0';
		if (rap[i] == '?') {
			curr = second;
		}
		amount[curr]++;
		total += costs[curr] * before[i][1-curr];
	}

	ll res = total;
	for (ll i = 0; i < rap.size(); i++) {
		if (i > 0) {
			for (ll num = 0; num < 2; num++) {
				before[i][num] = before[i-1][num];
			}
			if (rap[i-1] == '?') {
				before[i][first]++;
			} else {
				before[i][rap[i-1]-'0']++;
			}
		}
		if (rap[i] == '?') {
			// cambiamos por el first
			ll after_first = amount[first] - before[i][first];
			total -= costs[first] * after_first;
			total -= costs[second] * before[i][first];
			ll after_second = amount[second] - before[i][second] - 1;
			total += costs[second] * after_second;
			total += costs[first] * before[i][second];
			res = min(res, total);
			amount[second]--;
			amount[first]++;
		}
	}

	cout << res << endl;

}
