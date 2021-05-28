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
	ll pasos = 0;
	forn (i) {
		cin >> a[i];
		if (i > 0) {
			pasos += abs(a[i] - a[i-1]);
		}
	}

	ll best_pasos = pasos;
	for (ll i = 0; i < n; i++) {
		ll curr_pasos = pasos;
		if (i > 0) {
			curr_pasos -= abs(a[i-1] - a[i]);
		}
		if (i < n-1) {
			curr_pasos -= abs(a[i] - a[i+1]);
		}
		if (i > 0 && i < n-1) {
			curr_pasos += abs(a[i-1] - a[i+1]);
		}
		best_pasos = min(best_pasos, curr_pasos);
	}

	cout << best_pasos << endl;




}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}
