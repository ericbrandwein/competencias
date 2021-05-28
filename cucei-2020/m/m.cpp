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

map<ll,ll> factorizar(ll n) {
	map<ll,ll> factores;
	ll primo = 2;
	for (; primo * primo <= n; primo++) {
		while (n % primo == 0) {
			factores[primo]++;
			n /= primo;
		}
	}
	if (n > 1) factores[n]++;
	return factores;
}


int main() {
	IOS;

	ll n, m;
	cin >> n >> m;
	map<ll,ll> factores = factorizar(m);

	ll res = 1;
	for (auto factor : factores) {
		ll primo = factor.first;
		ll cant = factor.second;
		ll cada_uno = cant / n;
		for (ll i = 0; i < cada_uno; i++) {
			res *= primo;
		}
	}

	cout << res << endl;



}
