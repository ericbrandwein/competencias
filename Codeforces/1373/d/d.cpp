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
	vector<ll> a(n);
	forn (i) {
		cin >> a[i];
	}

	// para las sumas que empiezan en un indice par: 0, 2, etc.
	vector<ll> diffs_pares(n / 2 + 1);
	diffs_pares[0] = 0;
	fore (i, 0 , n / 2) {
		// resto pares, sumo impares
		diffs_pares[i + 1] = -a[i * 2] + a[i*2 + 1];
	}

	// para las sumas que empiezan en un indice impar: 1, 3, etc.
	vector<ll> diffs_impares(1);
	diffs_pares[0] = 0;
	for (ll i = 0; i * 2 + 2 < n; i++) {
		// resto pares, sumo impares
		diffs_impares.push_back(-a[i * 2 + 2] + a[i*2 + 1]);
	}

	// max_subarray enrte las dos/.
	ll best = 0;
	ll last = 0;
	fore (i, 0, diffs_pares.size()) {
		last = max(last, 0ll);
		last += diffs_pares[i];
		best = max(best, last);
	}

	last = 0;
	fore (i, 0, diffs_impares.size()) {
		last = max(last, 0ll);
		last += diffs_impares[i];
		best = max(best, last);
	}

	ll total = best;
	for (ll i = 0; i < n; i+= 2) {
		total += a[i];
	}
	cout << total << endl;

}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
