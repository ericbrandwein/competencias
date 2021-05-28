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

int solve() {
	ll cj, jc;
	cin >> cj >> jc;

	string s;
	cin >> s;

	char prev = '0';
	ll res = 0;
	for (char curr : s) {
		if (prev == 'J' && curr == 'C') {
			res += jc;
		} else if (prev == 'C' && curr == 'J') {
			res += cj;
		}

		if (curr != '?') {
			prev = curr;
		}
	}

	return res;

}


int main() {
	IOS;

	ll t;
	cin >> t;
	fore (i, 0, t) {
		cout << "Case #" << i + 1 << ": " << solve() << endl;
	}

}
