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

bool puedo_repartir(ll n, ll x, ll suma) {
	for (ll i = 0; i < n; i++) {
		if ((suma - x * i) % (n - i) == 0) {
			return true;
		}
	}
	return false;
}

void solve() {
	ll n;
	cin >> n;
	ll x;
	cin >> x;

	vec<ll> a(n);;
	ll sum = 0;
	ll equals = 0;
	forn (i) {
		cin >> a[i];
		sum += a[i];
		if (a[i] == x) equals++;
	}

	if (equals == n) {
		cout << 0 << endl;
	} else if ((sum % n == 0 && sum / n == x) ||
		equals >= 2 ||
		(equals == 1 && puedo_repartir(n, x, sum))
	) {
		cout << 1 << endl;
	} else {
		cout << 2 << endl;
	}


}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--)solve();


	return 0;
}
