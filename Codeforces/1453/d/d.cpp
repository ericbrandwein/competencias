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

vec<ll> get_esperanzas() {
	vec<ll> esperanzas;
	ll esperanza = 2;
	while (esperanza < 500'000'000'000'000'000) {
		esperanzas.push_back(esperanza);
		esperanza++;
		esperanza *= 2;
	}
	return esperanzas;
}


void solve() {
	ll k;
	cin >> k;
	vec<ll> stages;
	if (k % 2 == 1) {
		cout << -1 << endl;
		return;
	}
	vec<ll> esperanzas = get_esperanzas();
	for (ll i = esperanzas.size() - 1; i >= 0 && k > 0; i--) {
		while (k >= esperanzas[i]) {
			stages.push_back(1);
			for (ll j = 0; j < i; j++) {
				stages.push_back(0);
			}
			k-= esperanzas[i];
		}
	}

	cout << stages.size() << endl;
	for (ll stage : stages) {
		cout << stage << " ";
	}

	cout << endl;

}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();


}
