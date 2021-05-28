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

const ll MAX_N = 100002;

int main() {
	IOS;

	vec<ll> cant(MAX_N);
	cant[0] = 0;
	cant[1] = 0;
	cant[2] = 0;
	cant[3] = 2;
	ll impares = 0;
	for (ll i = 4; i < MAX_N; i++) {
		cant[i] = cant[i-1];
		if (impares != 1) {
			cant[i]++;
		}
		impares++;
		impares %= 3;
	}
	ll t;
	cin >> t;
	while (t--) {
		ll num;
		cin >> num;
		cout << cant[num] << endl;
	}

	return 0;
}
