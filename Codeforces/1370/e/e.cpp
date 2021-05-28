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
	string s, t;
	cin >> s >> t;
	ll minc = 0;
	ll maxc = 0;
	ll curr = 0;
	fore (i, 0, s.size()) {
		if (s[i] == '1' && t[i] == '0') curr++;
		if (t[i] == '1' && s[i] == '0') curr--;
		minc = min(minc, curr);
		maxc = max(maxc, curr);
	}

	if (curr != 0) cout << -1 << endl;
	else
		cout << maxc - minc << endl;

	return 0;
}
