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

#define MOD 1000000007

ll pot2(ll num) {
	ll res = 1;
	for (ll i = 0; i < num; i++) {
		res *= 2;
		res %= MOD;
	}
	return res;
}

int main() {
	IOS;

	ll n;
	cin >> n;
	vector<ll> cants(100001, 0);

	vector<ll> colors(n);
	forn (i) {
		cin >> colors[i];
		cants[colors[i]]++;
	}

	ll total = 0;
	for (ll i = 0; i < cants.size(); i++) {
		total += pot2(cants[i]) - 1;
	}

	cout << total << endl;

	return 0;
}
