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
	vector<ll> changes(n);
	forn (i) {
		cin >> changes[i];
	}

	ll impares = 0;
	for (ll i = 0; i < changes.size(); i++) {
		if (changes[i] % 2 != 0) {
			impares++;
		}
	}

	ll up = impares / 2;
	assert(impares % 2 == 0);
	for (ll i = 0; i < n; i++) {
		if (changes[i] % 2 != 0) {
			if (up > 0) {
				changes[i]++;
				up--;
			} else {
				changes[i]--;
			}
		}
		cout << changes[i] / 2 << endl;
	}


}
