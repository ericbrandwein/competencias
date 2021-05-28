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

	vector<string> lines;
	string line;
	while (getline(cin, line)) {
		lines.push_back(line);
	}


	vector<bool> special(lines.size(), false);
	for (ll i = 0; i < lines.size(); i++) {
		ll j = 0;
		for (;j < lines[i].size() && lines[i][j] == ' '; j++);
		special[i] = j < lines[i].size() && lines[i][j] == '#';
	}

	string res;
	for (ll i = 0; i < lines.size(); i++) {
		if (special[i]) {
			res.append(lines[i]);
			res.push_back('\n');
		} else {
			for (ll j = 0; j < lines[i].size(); j++) {
				if (lines[i][j] != ' ') {
					res.push_back(lines[i][j]);
				}
			}
			if (i < lines.size() - 1 && special[i + 1] || i == lines.size() - 1) {
				res.push_back('\n');
			}
		}
	}

	cout << res;



	return 0;
}
