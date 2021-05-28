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
	cin >>n ;
	vec<ll> a(n);
	forn (i) {
		cin >> a[i];
		a[i]--;
	}

	vec<ll> cant(n, 0);
	for (ll num : a) {
		cant[num]++;
	}

	vec<ll> validos(n, 0);
	ll izq = 0;
	ll der = n - 1;
	for (ll i = 0; i < n; i++) {
		if (cant[i] > 0) {
			validos[i] = 1;
		}
		if (cant[i] > 1 || cant[i] == 0) {
			break;
		}
		if (a[izq] == i) {
			izq++;
		} else if (a[der] == i) {
			der--;
		} else {
			break;
		}
	}

	reverse(all(validos));
	validos[0] = 1;
	for (ll cant_actual : cant) {
		if (cant_actual == 0) validos[0] = 0;
	}
	for (ll num : validos) {
		cout << num;
	}
	cout << endl;


}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}
