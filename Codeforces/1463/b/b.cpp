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
	vec<ll> a(n);
	ll suma_par = 0;
	ll suma_impar = 0;
	forn (i) {
		cin >> a[i];
		if (i % 2 == 0) suma_par +=a[i];
		else suma_impar += a[i];
	}

	ll resto = 0;
	if (suma_impar > suma_par) {
		resto = 1;
	}

	forn (i) {
		if (i % 2 == resto) {
			cout << a[i] << " ";
		} else {
			cout << 1 << " ";
		}
	}

	cout << endl;



}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();
}
