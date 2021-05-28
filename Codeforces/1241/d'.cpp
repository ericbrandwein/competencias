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

		vector<ll> nexts(n, -1);
		ll prev = 0;
		for (ll i = 1;i<n;i++) {
			if (present[i]) {
				nexts[prev] = i;
				prev = i;
			}
		}

		vec<bool> next_is_after(n, true);
		vec<bool> found(n, false);
		for (ll i = 0; i < n; i++) {
			ll next = nexts[elems[i]];
			if (next != -1 && found[next]) {
				next_is_after[elems[i]] = false;
			}
			found[elems[i]] = true;
		}

		ll first = 0;
		for (;!present[first]; first++);

		ll longest_consec = 0;
		ll curr_consec = 0;
		ll curr = first;
		while (curr != -1) {
			curr_consec++;
			if (!next_is_after[curr]) {
				longest_consec = max(longest_consec, curr_consec);
				curr_consec = 0;
			}
			curr = nexts[curr];
		}
		longest_consec = max(longest_consec, curr_consec);

		ll numbers = 0;
		for (ll i = 0; i < n; i++) {
			if (present[i]) numbers++;
		}

		cout << numbers - longest_consec << endl;
	}

	return 0;
}
