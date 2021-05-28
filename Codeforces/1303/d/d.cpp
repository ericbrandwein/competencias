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

string to_bin(ll n) {
	string res;
	while (n > 0) {
		res.push_back('0' + n % 2);
		n/=2;
	}
	return res;
}


void solve() {
	ll n, m;
	cin >> n >> m;
	map<ll,ll> logaritmos;
	ll potencia = 1;
	ll max_potencia = 0;
	for (; max_potencia <= 61; max_potencia++) {
		logaritmos[potencia] = max_potencia;
		potencia *= 2;
	}
	vec<ll> cantidades(max_potencia + 2, 0);

	for (ll i = 0; i < m; i++) {
		ll a;
		cin >> a;
		cantidades[logaritmos[a]]++;
	}

	string bin = to_bin(n);
	ll menor = LONG_LONG_MAX;
	ll total = 0;
	for (ll i = 0; i < bin.size(); i++) {
		if (cantidades[i] >= 1) {
			if (menor != LONG_LONG_MAX) {
				total += i - menor;
				menor = LONG_LONG_MAX;
				cantidades[i]--;
			}
		}
		if (bin[i] == '1') {
			if (cantidades[i] >= 1) {
				bin[i] = '0';
				cantidades[i]--;
			} else {
				menor = min(menor, i);
			}
		}
		cantidades[i+1] += cantidades[i] / 2;
	}

	if (menor != LONG_LONG_MAX) {
		ll otro = menor;
		for (;menor < cantidades.size() && cantidades[menor] == 0; menor++);
		if (menor < cantidades.size()) {
			total += menor - otro;
		} else {
			cout << -1 << endl;
			return;
		}
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
