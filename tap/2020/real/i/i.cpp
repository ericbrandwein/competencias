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

const ll MOD = 1e9+7;



ll powmod(ll base, ll exp) {
	ll res = 1;
	while (exp) {
		if (exp & 1) {
			res = (res*base) % MOD;
		}
		base = (base * base) % MOD;
		exp >>= 1;
	}
	return res;
}

/**
 * El mod tiene que ser primo.
 * Se basa en fermatito.
 */
ll inverso_mod(ll num) {
	return powmod(num, MOD - 2ll);
}

ll calcular_combis(
	ll raiz, vec<vec<ll>>& hijos, vec<ll>& combis_totales, vec<ll>& combis_con_raiz
) {
	if (hijos[raiz].size() == 0) {
		return 1;
	}

	ll productoria_hijos = 1;
	for (ll hijo : hijos[raiz]) {
		calcular_combis(hijo, hijos, combis_totales, combis_con_raiz);
		productoria_hijos *= combis_totales[hijo];
		productoria_hijos %= MOD;
	}

	vec<ll> prod_pre;
	vec<ll> prod_suf(hijos[raiz].size() + 1);
	prod_pre.push_back(1);
	prod_suf[hijos[raiz].size()] = 1;
	for (ll hijo : hijos[raiz]) {
		prod_pre.push_back((prod_pre.back() * combis_totales[hijo]) % MOD);
	}

	for (ll i = hijos[raiz].size() - 1; i >= 0; i--) {
		prod_suf[i] = (prod_suf[i + 1] * combis_totales[hijos[raiz][i]]) % MOD;
	}

	combis_totales[raiz] = productoria_hijos;
	combis_con_raiz[raiz] = 0;
	for (ll i = 0; i < hijos[raiz].size(); i++ ) {
		ll hijo = hijos[raiz][i];
		ll productoria_sin_hijo = prod_pre[i] * prod_suf[i + 1];
		productoria_sin_hijo %= MOD;
		ll nuevo = productoria_sin_hijo * combis_con_raiz[hijo];
		nuevo %= MOD;
		combis_con_raiz[raiz] += nuevo;
		combis_con_raiz[raiz] %= MOD;
	}
	combis_totales[raiz] += combis_con_raiz[raiz];
	combis_totales[raiz] %= MOD;

	return combis_totales[raiz];
}



int main() {
	IOS;

	ll n;
	cin >> n;
	vec<vec<ll>> hijos(n);
	// vec<ll> padres(n, -1);

	fore (i, 1, n) {
		ll padre;
		cin >> padre;
		padre--;
		hijos[padre].push_back(i);
		// padres[i] = padre;
	}

	vec<ll> combis_totales(n, 1);
	vec<ll> combis_con_raiz(n, 1);

	cout << calcular_combis(0, hijos, combis_totales, combis_con_raiz) << endl;

	return 0;
}
