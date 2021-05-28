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

	ll n, types;
	cin >> n >> types;

	vector<ll> longest_increasing(types + 1, 0);
	forn (i) {
		ll type;
		float ignored;
		cin >> type >> ignored;
		ll longest_curr = 0;
		for (ll j = 0; j <= type; j++) {
			longest_curr = max(
				longest_curr, longest_increasing[j] + 1
			);
		}
		longest_increasing[type] = longest_curr;
	}

	ll longest = *max_element(all(longest_increasing));
	cout << n - longest << endl;

	return 0;
}
