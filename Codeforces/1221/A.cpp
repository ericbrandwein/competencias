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

void completar(map<ll, ll>& elems, ll elem) {
	while (elems[elem] > 0 && elem < 2048) {
		elems[elem]--;
		elem = 2 * elem;
	}
	elems[elem]++;
}

int main() {
	IOS;

	ll q;
	cin >> q;
	fore (i, 0, q) {
		ll n;
		cin >> n;

		vec<ll> elems(n);
		fore (j, 0, n) {
			cin>> elems[j];
		}
		map<ll, ll> elems_map;
		bool termine = false;
		for ( ll j = 0; j<  n; j++) {
			if (elems[j] == 2048) {
				cout << "YES" << endl;
				j = n;
				termine = true;
			} else if (elems[j] < 2048) {
				completar(elems_map, elems[j]);
			}
		}

		if (!termine) {
			if (elems_map[2048] > 0) {
			cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
		

	}

	return 0;
}
