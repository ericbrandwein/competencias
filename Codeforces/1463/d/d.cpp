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
	vec<ll> b(n);
	vec<bool> adentro(2*n, false);
	forn (i) {
		cin >> b[i];
		b[i]--;
		adentro[b[i]] = true;
	}

	vec<ll> sacados;

	ll indice_b = 0;
	for (ll i = 0; i < 2*n; i++) {
		if (indice_b < n) {
			if (b[indice_b] == i) {
				indice_b++;
			} else {
				sacados.push_back(i);
			}
		} else {
			sacados.push_back(i);
		}
	}

	ll min_minimos = 0; // pongo todos los que puedo para atras
	ll menor_sacados = 0;
	ll mayor_sacados = n - 1;
	for (ll i = 0; i < n; i++) {
		if (b[i] < sacados[menor_sacados]) {
			mayor_sacados--;
			min_minimos++;
		} else {
			menor_sacados++;
		}
	}

	ll max_minimos = 0; // pongo todos los que puedo para adelante
	menor_sacados = 0;
	mayor_sacados = n - 1;
	for (ll i = n-1; i >= 0; i--) {
		if (b[i] > sacados[mayor_sacados]) {
			menor_sacados++;
		} else {
			mayor_sacados--;
			max_minimos++;
		}
	}

	cout << max_minimos - min_minimos + 1 << endl;


}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}
