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
	string s;
	cin >> s;

	vector<ll> levels(s.size());
	ll curr_level = 0;
	ll max_level = 0;
	fore (i, 0, s.size()) {
		if (s[i] == '[') {
			curr_level++;
		}
		levels[i] = curr_level;
		max_level = max(max_level, curr_level);
		if (s[i] == ']') {
			curr_level--;
		}
	}

	for (ll i = 0; i < s.size(); i++) {
		levels[i] = max_level - levels[i] + 1;
	}
	// todas las de level igual tienen el mismo alto.
	vector<ll> positions(s.size(), 0);

	string middle = "";
	// hacer el del medio
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] == '[' || s[i - 1] == ']') {
			middle.push_back('|');
		} else {
			middle.push_back(' ');
			middle.push_back(' ');
			middle.push_back(' ');
			middle.push_back('|');
		}
		positions[i] = middle.size() - 1;
	}
	string empty = "";
	for (ll i = 0 ; i < middle.size(); i++) {
		empty.push_back(' ');
	}
	vector<string> res(1 + max_level, empty);
	res[0] = middle;


	for (ll i = 0 ; i < s.size(); i++) {
		for (ll level = 0; level < levels[i]; level++) {
			res[level][positions[i]] = '|';
		}
		res[levels[i]][positions[i]] = '+';
		if (s[i] == ']') {
			res[levels[i]][positions[i] - 1] = '-';
		} else {
			res[levels[i]][positions[i] + 1] = '-';
		}
	}

	for (ll i = res.size() - 1;i > 0; i--) {
		cout << res[i] << endl;
	}
	for (string& r : res) {
		cout << r << endl;
	}






	return 0;
}
