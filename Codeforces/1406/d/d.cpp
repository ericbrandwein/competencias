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

int main() {
	IOS;

	ll n;
	cin >> n;
	vec<ll> a(n);
	forn (i) cin >> a[i];

	vec<ll> difs(n, 0); // dif con el anterior
	ll sumab = 0;
	difs[0] = a[0];
	fore (i, 1, n) {
		difs[i] = a[i] - a[i-1];
		if (difs[i] >= 0) {
			sumab+= difs[i];
		}
	}

	ll b0 = (a[0] - sumab) / 2;
	if ((a[0] - sumab) % 2 == 1) {
		b0++;
	}
	cout << b0 + sumab << endl;
	ll q;
	cin >> q;
	for (ll i = 0; i < q; i++) {
		ll from, to, sumado;
		cin >> from >> to >> sumado;
		from--; to;
		ll nuevo = 0;
		ll ant = max(difs[from], 0ll);
		difs[from] += sumado;
		ll sig = max(difs[from], 0ll);
		if (from == 0) {
			a[0] += sumado;
		} else {
			nuevo = sig - ant;
		}
		if (to < n) {
			ant = max(difs[to], 0ll);
			difs[to] -= sumado;
			sig = max(difs[to], 0ll);
			nuevo += sig - ant;
		}
		sumab += nuevo;

		b0 = (a[0] - sumab) / 2;
		if ((a[0] - sumab) % 2 == 1) {
			b0++;
		}
		cout << b0 + sumab << endl;
	}


	return 0;
}
