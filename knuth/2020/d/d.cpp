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

const ll MOD = 1e9 + 7;

int main() {
	IOS;

	ll n;
	cin >> n;
	__int128 raiz = sqrt(n);

	__int128 suma = 0;
	// if (raiz <= 10000000) {
	// 	for (ll i = 1; i <= raiz; i++) {
	// 		suma += i * i;
	// 		suma %= MOD;
	// 	}
	// } else {
	suma = raiz*(raiz + 1) * (2*raiz + 1) / 3;
	// }

	suma %= MOD;



	__int128 diff = (raiz + 1)*(raiz + 1) - raiz*raiz;
	// la mitad tirada para abajo ya la contamos
	__int128 mitad = raiz*raiz + diff / 2;
	if (n < mitad) {
		suma -= (mitad - n) * raiz;
		suma %= MOD;
		if (suma < 0) suma += MOD;
	} else {
		suma += (n - mitad) * (raiz + 1);
		suma %= MOD;
	}

	cout << (ll) suma << endl;

	return 0;
}
