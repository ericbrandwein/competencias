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
	ll n;
	cin >> n;
	vec<ll> a(n);
	forn (i) {
		cin >> a[i];
		a[i]--;
	}

	vec<ll> firsts(n, n);
	vec<ll> lasts(n, -1);
	vec<ll> amounts(n, 1);
	for (ll i = 0; i < n; i++) {
		if (lasts[a[i]] != -1) {
			amounts[i] += amounts[lasts[a[i]]];
		}
		firsts[a[i]] = min(firsts[a[i]], i);
		lasts[a[i]] = max(lasts[a[i]], i);
	}

	vec<ll> max_subsec(n);
	max_subsec[n- 1] = 1;
	for (ll i = n - 2; i >= 0; i--) {

		max_subsec[i] = max_subsec[i + 1];
		if (i == firsts[a[i]]) {
			ll last = lasts[a[i]];
			ll maxed = amounts[last];
			if (last < n - 1) {
				maxed += max_subsec[last + 1];
			}
			max_subsec[i] = max(
				max_subsec[i],
				maxed
			);
		} else {
			ll last = lasts[a[i]];
			ll maxed = amounts[last] - amounts[i] + 1;
			max_subsec[i] = max(
				max_subsec[i],
				maxed
			);
		}
	}

	cout << n - max_subsec[0] << endl;

}
