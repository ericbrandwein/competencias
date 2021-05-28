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

ll changes_for(string& s, char first, char second) {
	vector<char> letters = {first, second};

	ll total = 0;
	ll curr = 0;
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] != letters[curr]) total++;
		else {
			curr += 1;
			curr %= 2;
		}
	}

	if ((s.size() - total) % 2 == 1) {
		total++;
	}
	return total;
}


void solve() {
	string s;
	cin >> s;

	vector<ll> apparitions(10, 0);
	for (ll i = 0; i < s.size(); i++) {
		apparitions[s[i] - '0']++;
	}

	ll max_elem = *max_element(all(apparitions));
	ll best = s.size() - max_elem;

	for (char first = '0'; first <= '9'; first++) {
		for (char second = '0'; second <= '9'; second++) {
			if (first != second) {
				best = min(best, changes_for(s, first, second));
			}
		}
	}

	cout << best << endl;

}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();


	return 0;
}
