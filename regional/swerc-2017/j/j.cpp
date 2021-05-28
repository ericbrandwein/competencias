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

	vec<ll> a(n), b(n);
	vec<ll> sumas_b(3, 0);
	forn (i) cin >> a[i];
	forn (i) {
		cin >> b[i];
		sumas_b[i%3] += b[i];
	}

	vec<ll> cants(3, 0);
	forn (i) {
		fore (j, 0, 3) {
			cants[(i + j) % 3] += a[i] * sumas_b[j];
		}
	}


	cout << cants[1] << " " << cants[2] << " " << cants[0] << endl;



}
