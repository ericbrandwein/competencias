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

ll remove(ll& a, ll& b) {
	ll pairs = min(a,b);
	a-=pairs;
	b-=pairs;
	return pairs;
}

void solve() {
	vec<ll> a(3);
	vec<ll> b(3);
	ll sum = 0;
	fore (i, 0, 3) {
		cin >> a[i];
		sum += a[i];
	}
	fore (i, 0, 3) cin >> b[i];
	ll total = 2*remove(a[2], b[1]);
	sum -= total / 2;
	ll removed = min(a[1], b[2]);
	ll other = sum - max(a[1], b[2]);
	total -= 2*max(0ll, removed - other);
	cout << total << endl;

}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
