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

pair<ll,ll> get_min_max(ll a) {
	pair<ll,ll> min_max = {10, 0};
	while (a > 0) {
		ll dig = a%10;
		min_max.first = min(min_max.first, dig);
		min_max.second = max(min_max.second, dig);
		a/=10;
	}
	return min_max;
}


void solve() {
	ll a, k;
	cin >> a >> k;

	pair<ll,ll> min_max = get_min_max(a);
	for (ll pasos = 1; pasos < k && min_max.first != 0; pasos++) {
		a += min_max.first * min_max.second;
		min_max = get_min_max(a);
	}

	cout << a << endl;

}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}
