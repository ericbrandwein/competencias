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


int main() {
	IOS;

	ll n, q;
	cin >> n >> q;
	string s;
	cin >> s;

	vec<ll> acum(n + 1, 0);
	for (ll i = 1; i <=n; i++) {
		acum[i] = acum[i-1] + (s[i - 1] - '0');
	}

	vec<ll> potencias;
	ll pot = 1;
	for (ll i = 0; i <= n; i++) {
		potencias.push_back(pot);
		pot *= 2;
		pot %= MOD;
	}

	while (q--) {
		ll left, right;
		cin >> left >> right;

		ll unos = acum[right] - acum[left - 1];
		ll ceros = right - left + 1 - unos;

		ll total = (potencias[unos] - 1) * (potencias[ceros] - 1);
		total %= MOD;
		total += potencias[unos] - 1;
		cout << total % MOD << endl;
	}

	return 0;
}
