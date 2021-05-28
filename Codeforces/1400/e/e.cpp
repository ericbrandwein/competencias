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

ll operations(vec<ll>& a, ll from, ll to, ll restado) {
	if (from == to) return 0;
	ll mini = from;
	for (ll i = from; i < to; i++) {
		if (a[i] < a[mini]) mini = i;
	}
	return min(
		to - from,
		a[mini] - restado +
		operations(a, from, mini, a[mini]) +
		operations(a, mini + 1, to, a[mini])
	);
}


int main() {
	IOS;

	ll n;
	cin >> n;
	vec<ll> a(n);
	forn (i) cin >> a[i];

	cout << operations(a, 0, n, 0) << endl;


	return 0;
}
