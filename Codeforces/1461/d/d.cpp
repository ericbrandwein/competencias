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



ll get_sums(vec<ll>& a, set<ll>& res, ll from, ll to) {
	if (from > to) {
		return 0;
	}
	if (a[from] == a[to]) {
		ll num = (to - from + 1) * a[from];
		res.insert(num);
		return num;
	}
	ll searched = (a[from] + a[to]) / 2;
	auto it = upper_bound(a.begin() + from, a.begin() + to, searched);
	ll left = get_sums(a, res, from, it - a.begin() - 1);
	ll right = get_sums(a, res, it - a.begin(), to);
	res.insert(left + right);
	return left + right;
}

void solve() {
	ll n, q;
	cin >> n >> q;
	vec<ll> a(n);
	forn (i) cin >> a[i];


	set<ll> sums;
	sort(all(a));
	get_sums(a, sums, 0, n-1);
	fore (i, 0, q) {
		ll s;
		cin >> s;
		if (sums.count(s) > 0) {
			cout << "Yes"<< endl;
		} else {
			cout << "No" << endl;
		}
	}
}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();


}
