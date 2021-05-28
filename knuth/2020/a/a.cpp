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

	string s;
	cin >> s;
	map<char, char> replace;
	replace['O'] = '0';
	replace['I'] = '1';
	replace['Z'] = '2';
	replace['E'] = '3';
	replace['A'] = '4';
	replace['S'] = '5';
	replace['G'] = '6';
	replace['T'] = '7';
	replace['B'] = '8';
	for (ll i = 0; i < s.size(); i++) {
		if (replace.count(toupper(s[i])) > 0) {
			s[i] = replace[toupper(s[i])];
		}
	}

cout << s << endl;
	return 0;
}
