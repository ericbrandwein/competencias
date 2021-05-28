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
	ll q;
	cin >> q;
	vec<ll> a(n);
	forn (i) cin >> a[i];
	vec<pair<ll,ll>> first;
	vec<ll> b;
	ll biggest = a[0];
	fore (i, 1, n) {
		first.push_back({biggest, a[i]});
		b.push_back(min(biggest,a[i]));
		biggest = max(biggest, a[i]);
	}

	fore (i, 0, q) {
		ll iteration;
		cin >> iteration;
		iteration--;
		if (iteration < n-1) {
			cout << first[iteration].first << " " << first[iteration].second << endl;
		} else {
			cout << biggest << " " << b[iteration % (n-1)] << endl;
		}
	}

	return 0;
}
