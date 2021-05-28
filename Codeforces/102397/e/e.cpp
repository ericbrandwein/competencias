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

	ll needed, n;
	cin  >> n >>needed;
	vector<ll> houses(n);
	forn (i) {
		cin >> houses[i];
	}

	ll coins = 0;
	ll start_house = 0;
	ll min_cant = LONG_LONG_MAX;
	for (ll i = 0; i < houses.size(); i++) {
		coins += houses[i];
		while (coins >= needed) {
			min_cant = min(i - start_house + 1, min_cant);
			coins -= houses[start_house];
			start_house++;
		}
	}

	if (min_cant == LONG_LONG_MAX) {
		min_cant = -1;
	}
	cout << min_cant << endl;
	return 0;
}
