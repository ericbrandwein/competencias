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


	ll n, m;
	cin >> n >> m;
	vec<ll> entradas(n), salidas(m);
	forn (i) cin >> entradas[i];
	fore (i, 0, m) cin >> salidas[i];

	map<ll, ll> cant_de_difs;
	forn (i) {
		fore (j, 0, m) {
			if (entradas[i] <= salidas[j]) {
				cant_de_difs[salidas[j] - entradas[i]]++;
			}
		}
	}

	ll mejor = 0;
	for (pair<ll,ll> cant_de_dif : cant_de_difs) {
		if (cant_de_dif.second > cant_de_difs[mejor]) {
			mejor = cant_de_dif.first;
		}
	}

	cout << mejor << endl;


}
