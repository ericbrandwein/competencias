//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define elif else if
#define ll int
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

vec<ll> operator-(const vec<ll>& first, const vec<ll>& second) {
	vec<ll> res;
	for (ll i = 0; i < first.size(); i++) {
		res.push_back(first[i] - second[i]);
	}
	return res;
}


void solve() {
	ll n;
	cin >> n;
	vec<ll> a(n);

	forn (i) cin >> a[i];


	ll max_elem = *max_element(all(a));
	vec<vec<ll>> appearances(max_elem + 1);
	vec<vec<ll>> acum(n + 1, vec<ll>(max_elem + 1, 0));
	for (ll i = 0; i < a.size(); i++) {
		acum[i + 1] = acum[i];
		acum[i + 1][a[i]]++;
		appearances[a[i]].push_back(i);
	}

	ll max_len = 1;
	for (ll i = 1; i <= max_elem; i++) {
		for (ll x = 1; x + x <= appearances[i].size(); x++) {
			ll first = appearances[i][x - 1];
			ll second = appearances[i][appearances[i].size() - x];
			vec<ll> amount = acum[second] - acum[first + 1];
			ll max_mid = *max_element(all(amount));
			max_len = max(max_len, max_mid + 2*x);
		}
	}

	cout << max_len << endl;


}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
