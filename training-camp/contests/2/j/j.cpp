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

// inclusive, inclusive
ll suma_desde_hasta(ll j, ll k) {
	return (k + 1)*k / 2 - j*(j-1) / 2 - (k - j);
}


int main() {
	IOS;

	ll n, k;
	cin >> n >> k;

	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}

	if (n <= k) {
		cout << 1 << endl;
		return 0;
	}


	// busqueda binaria para ver cuántos agarramos
	ll from = 1;
	ll to = k + 1;
	while (from < to) {
		ll middle = (from + to) / 2;
		ll suma = suma_desde_hasta(k - middle + 1, k);
		if (suma >= n) {
			// Tenemos que agarrar menos
			to = middle;
		} else {
			// tenemos que agarrar mas
			from = middle + 1;
		}
	}

	// from es cuantos agarramos
	if (suma_desde_hasta(k - from + 1, k) < n) {
		cout << -1 << endl;
	} else {
		cout << from << endl;
	}


	return 0;
}
