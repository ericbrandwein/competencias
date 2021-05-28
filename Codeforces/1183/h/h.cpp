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

void operator+=(vec<ll>& prim, vec<ll>& seg) {
	for (ll i = 0; i < prim.size(); i++) {
		prim[i] += seg[i];
	}
}

vec<ll> adelantar(vec<ll>& lista, ll posiciones) {
	vec<ll> res(lista.size());
	for (ll i = 0; i + posiciones < lista.size(); i++) {
		res[i+posiciones] = lista[i];
	}
	return res;
}


int main() {
	IOS;

	ll n, k;
	cin >> n >> k;
	string a;
	cin >> a;

	vec<vec<ll>> cant_eliminados(n+1, vec<ll>(n+1, 0));
	cant_eliminados[n][0] = 1;
	for (ll i = n-1; i >= 0; i--) {
		for (ll j = i + 1; j <= n; j++) {
			vec<ll> adelantado = adelantar(cant_eliminados[j], j - 1 - i);
			cant_eliminados[i] += adelantado;
			if (j < n && a[j] == a[i]) {
				break;
			}
		}
	}

	vec<ll> total(n+1, 0);
	for (ll i = 0; i <= n; i++) {
		vec<ll> adelantado = adelantar(cant_eliminados[i], i);
		total += adelantado;
	}

	ll res = 0;
	for (ll i = 0; i < n + 1 && k > 0; i++) {
		ll sacados = min(total[i], k);
		res += sacados*i;
		k -= sacados;
	}
	if (k > 0) cout << -1 << endl;
	else cout << res << endl;



}
