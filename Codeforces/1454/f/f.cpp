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

void solve() {
	ll n;
	cin >> n;
	vec<ll> a(n);
	multiset<ll> left, middle, right;
	forn (i) {
		cin >> a[i];
		middle.insert(a[i]);
	}


	ll i_right = n;
	for (ll i_left = 0; i_left + 1 < i_right; i_left++) {
		left.insert(a[i_left]);
		middle.erase(middle.find(a[i_left]));
		ll searched = *(--left.end());
	}


}

int main() {
	IOS;


	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
