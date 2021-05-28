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
	ll d, k;
	cin >> d >> k;
	ll max_num = d / k;
	vec<ll> max_saltos(max_num + 1, 0);
	for (ll i = 0; i * k <= d; i++) {
		ll hor = i*k;
		ll vert = max_num*k;
		while (hor*hor + vert*vert > d*d) {
			max_num--;
			vert = max_num*k;
		}
		max_saltos[i] = max_num;
	}
	ll prim_secuencia = LONG_LONG_MAX;
	for (ll i = 0; i < max_saltos.size(); i++) {
		ll resta = max_saltos[i] - i;
		if (resta >= 0) {
			prim_secuencia = min(prim_secuencia, resta);
		}
	}

	if (prim_secuencia % 2 == 0) {
		cout << "Utkarsh" << endl;
	} else {
		cout << "Ashish" << endl;
	}
}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}
