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

	ll q;
	cin >> q;
	while (q--) {
		ll n;
		cin >> n;

		vector<ll> elems(n);
		vec<bool> present(n);
		for (ll i = 0; i < n; i++) {
			cin >> elems[i];
			elems[i]--;
			present[elems[i]] = true;
		}

		vec<bool> move_left(n, false);
		ll largest = elems[0];
		for (ll i = 0; i < n; i++) {
			if (elems[i] > largest) {
				largest = elems[i];
			} else if (elems[i] < largest) {
				move_left[elems[i]] = true;
			}
		}

		ll j = 0;
		for (;j < n && !move_left[j]; j++) {
			if (present[j]) {
				move_left[j] = true;
			}
		}

		ll move_left_q = 0;
		if (j != n) {
			for (ll k = 0;k < n;k++) {
				if (move_left[k]) move_left_q++;
			}
		}




		vec<bool> move_right(n, false);
		ll smallest = elems[n - 1];
		for (ll i = n - 1; i >= 0; i--) {
			if (elems[i] < smallest) {
				smallest = elems[i];
			} else if (elems[i] > smallest) {
				move_right[elems[i]] = true;
			}
		}
		j = n - 1;
		for (;j >= 0 && !move_right[j]; j--) {
			if (present[j]) {
				move_right[j] = true;
			}
		}


		ll move_right_q = 0;
		if (j >= 0) {
			for (ll k = 0;k < n;k++) {
				if (move_right[k]) move_right_q++;
			}
		}
		cout << min(move_left_q, move_right_q) << endl;

	}

	return 0;
}
