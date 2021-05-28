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

const ll MOD = 2147483647;

int main() {
	IOS;

	ll n;
	cin >> n;
	vec<ll> flechas(n);
	ll comienzo ;
	cin >> comienzo;
	comienzo--;
	forn (i) {
		cin >> flechas[i];
		flechas[i]--;
	}
	vec<vec<ll>> combi_por_fin(n, vec<ll>(n + 1, 0));
	combi_por_fin[0][comienzo] = 1;
	fore (i, 1, n) {
		ll ant = flechas[i-1];
		ll curr = flechas[i];
		for (ll j = 0; j <= n; j++) {
			ll max_ant = max(ant, j);
			ll min_ant = min(ant, j);
			if (curr < max_ant) {
				combi_por_fin[i][max_ant] += combi_por_fin[i-1][j];
				combi_por_fin[i][max_ant] %= MOD;
			}
			if (curr > min_ant) {
				combi_por_fin[i][min_ant] += combi_por_fin[i-1][j];
				combi_por_fin[i][min_ant] %= MOD;
			}
		}
	}

	ll suma = 0;
	fore (i, 0, n+1) {
		suma += combi_por_fin[n-1][i];
		suma %= MOD;
	}

	cout << suma << endl;




}
