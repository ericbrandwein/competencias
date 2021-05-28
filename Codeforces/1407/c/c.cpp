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


ll query(ll x, ll y) {
	cout << "? " << x +1 << " " << y+1 << endl << flush;
	ll res;
	cin >> res;
	return res;
}

int main() {
	IOS;

	ll n;
	cin >> n;

	ll maxi = 0;
	vec<ll> res(n, 0);
	fore (i, 1, n) {
		ll first = query(maxi, i);
		ll second = query(i, maxi);
		if (first > second) {
			res[maxi] = first;
			maxi = i;
		} else {
			res[i] = second;
		}
	}
	res[maxi] = n;
	cout << "! ";
	forn (i) cout << res[i] << " ";
	cout << endl;


	return 0;
}
