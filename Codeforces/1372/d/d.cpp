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
	vector<ll> a(n);
	vector<ll> sumas_impares(n, 0);
	ll ultima_suma_impar = 0;
	vector<ll> sumas_pares(n, 0);
	ll ultima_suma_par = 0;
	forn (i) {
		cin >> a[i];
		if (i % 2 == 0) {
			ultima_suma_par += a[i];
		} else {
			ultima_suma_impar += a[i];
		}
		sumas_pares[i] = ultima_suma_par;
		sumas_impares[i] = ultima_suma_impar;
	}

	// Primero par y después impar
	ll max_suma = 0;
	for (ll primer_impar = 1; primer_impar < n; primer_impar+=2) {
		ll pares = sumas_pares[primer_impar];
		ll impares = sumas_impares[n - 1] - sumas_impares[primer_impar - 1];
		max_suma = max(max_suma, pares + impares);
	}
	for (ll primer_par = 2; primer_par < n; primer_par+=2) {
		ll impares = sumas_impares[primer_par];
		ll pares = sumas_pares[n - 1] - sumas_pares[primer_par - 1];
		max_suma = max(max_suma, pares + impares);
	}

	max_suma = max(max_suma, sumas_pares[n - 1]);

	cout << max_suma << endl;

	return 0;
}
