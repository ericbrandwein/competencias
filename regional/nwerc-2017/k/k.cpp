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

int max_pot_2_menor(ll n, ll& exponente) {
	exponente = 0;
	ll res;
	for (res = 1; res <= n; res *= 2, exponente++);
	if (res > n) {
		res /= 2;
		exponente--;
	}
	return res;
}

int main() {
	IOS;

	ll n;
	cin >> n;
	ll poder_dale ;
	cin >> poder_dale;
	vec<ll> poderes(n-1);
	fore (i,0,n-1) cin >> poderes[i];
	sort(all(poderes));

	ll exponente;
	ll pot = max_pot_2_menor(n, exponente);
	ll sobran = n - pot;
	vec<vec<ld>> probas_por_nivel(exponente + 1, vec<ld>(n + 1, 0));
	for (ll i = 0; i < sobran; i++) {
		ll poder = poderes[poderes.size() - 1 - i];
		probas_por_nivel.back()[poder] = 1;
	}

}
