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
	for (ll primo = 2; primo * primo <= n; primo++) {
		while (n % primo == 0) {
			n /= primo;
			factores[primo]++;
		}
	}
	if (n != 1) factores[n]++;
	return factores;
}

void solve() {
	ll n;
	cin >> n;
	map<ll,ll> factores = factorizar(n);
	vec<pair<ll,ll>> ordenados;
	for (auto factor: factores) {
		ordenados.push_back({factor.second, factor.first});
	}
	sort(ordenados.rbegin(), ordenados.rend());
	vec<ll> res(ordenados[0].first, 1);
	cout << ordenados[0].first << endl;
	ll valor = 1;
	ll pos = ordenados[0].first;
	for (ll i = 0; i < ordenados.size(); i++) {
		while (ordenados[i].first < pos) {
			pos--;
			cout << valor << " ";
		}
		valor *= ordenados[i].second;
	}

	while (pos > 0) {
		cout << valor << " ";
	}
	cout << endl;

}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
