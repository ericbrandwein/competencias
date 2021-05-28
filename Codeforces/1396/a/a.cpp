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

	map<ll, ll> restos;
	ll pos = 0;
	for (ll i = 0; pos < n; i += n-1, i %= n) {
		restos[i] = pos;
		pos++;
	}

	if (n == 1) {
		cout << 1 << " " << 1 << endl;
		cout << -a[0] << endl;
		cout << 1 << " " << 1 << endl;
		cout << 0 << endl;
		cout << 1 << " " << 1 << endl;
		cout << 0 << endl;
	} else {
		cout << 1 << " " << n - 1 << endl;
		for (ll i = 0; i < n - 1; i++) {
			ll buscado = a[i] % n;
			if (buscado < 0) buscado += n;
			buscado = n - buscado;
			ll sumado = restos[buscado] * (n-1);
			cout << sumado << " ";
			a[i] += sumado;
		}
		cout << endl;

		cout << n << " " << n << endl;
		cout << -a[n-1] << endl;
		a[n-1] = 0;
		cout << 1 << " " << n << endl;
		for (ll i = 0; i < n; i++) {
			cout << -a[i] << " ";
		}
		cout << endl;
	}

	return 0;
}
