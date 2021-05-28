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

	ll n, q;
	cin >> n >> q;
	vec<ll> strengths(n);
	forn (i) cin >> strengths[i];
	vec<ll> acum(n, 0); // [)
	acum[0] = strengths[0];
	fore (i, 1, n) {
		acum[i] = acum[i-1] + strengths[i];
	}
	ll restado = 0;
	fore (i, 0, q) {
		ll arrows;
		cin >> arrows;
		auto it = upper_bound(acum.begin(), acum.end(), arrows + restado);
		// el primero mayor
		ll indice = it - acum.begin();
		ll vivos = 0;
		if (it == acum.end()) {
			restado = 0;
			vivos = n;
		} else {
			vivos = n - indice;
			restado += arrows;
		}

		cout << vivos << endl;
	}





}
