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
	string dirs;
	cin >> dirs;

	ll primer_dif = 1;
	char ulti = dirs[0];
	for (; primer_dif < n && dirs[primer_dif] == ulti; primer_dif++);

	if (primer_dif == n) {
		// todos iguales

		ll a_cambiar = (dirs.size() + 2) / 3;
		cout << a_cambiar << endl;
	} else {
		vec<ll> largos;
		ulti = dirs[primer_dif];
		ll largo = 1;
		for (ll i = (primer_dif + 1) % n; i != primer_dif;) {
			if (dirs[i] == ulti) {
				largo++;
			} else {
				largos.push_back(largo);
				largo = 1;
				ulti = dirs[i];
			}
			i++;
			i %= n;
		}
		largos.push_back(largo);

		ll total = 0;
		for (ll i = 0; i < largos.size(); i++) {
			total += largos[i] / 3;
		}

		cout << total << endl;

	}

}


int main() {
	IOS;


	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
