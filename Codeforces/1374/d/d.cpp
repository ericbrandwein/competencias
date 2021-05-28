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
	ll n, k;
	cin >> n >> k;

	vector<ll> a(n);
	// resto, cantidad
	map<ll, ll> restos;

	ll max_cant = 0;
	ll max_sumado = 0;

	forn (i) {
		cin >> a[i];
		ll resto = a[i] % k;
		if (resto != 0) {
			ll a_sumar = k - resto;
			restos[a_sumar]++;
			if (max_cant < restos[a_sumar] || max_cant == restos[a_sumar] && a_sumar > max_sumado) {
				max_cant = restos[a_sumar];
				max_sumado = a_sumar;
			}
		}
	}

	ll total = max_sumado;
	if (total > 0) {
		total++;
	}
	if (max_cant > 0) {
		total += (max_cant - 1) * k;
	}
	cout << total << endl;

}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
