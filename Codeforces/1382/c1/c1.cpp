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

char flip(char num, ll times) {
	return (num - '0' + times) % 2 + '0';
}





void solve() {
	ll n;
	cin >> n;
	string a, b;
	cin >> a >> b;

	ll flipeos = 0;
	ll from = 0;
	ll to = n - 1;

	vector<ll> ops;
	for (ll i = n - 1; i >=0; i--) {
		bool al_reves = flipeos % 2 == 1;
		ll same_pos;
		ll other_pos;
		if (al_reves) {
			same_pos = from;
			other_pos = to;
		} else {
			same_pos = to;
			other_pos = from;
		}

		ll same = flip(a[same_pos], flipeos);
		ll other = flip(a[other_pos], flipeos);
		if (same == b[i]) {
			if (al_reves) {
				from++;
			} else {
				to--;
			}
		} else {
			if (other == b[i]) {
				ops.push_back(1);
			}
			ops.push_back(i + 1);
			if (al_reves) {
				to--;
			} else {
				from++;
			}
			flipeos++;
		}
	}


	cout << ops.size() << " ";
	for (ll i = 0; i < ops.size(); i++){
		cout << ops[i] << " ";
	}
	cout << endl;
}



int main() {
	IOS;


	ll t;
	cin >> t;
	while (t--) solve();


	return 0;
}
