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

void solve() {
	string s;
	cin >> s;

	ll last_one = 0;
	for (last_one = 1;
		last_one < s.size() && (s[last_one] != s[last_one-1] || s[last_one] != '1');
		last_one++);
	last_one--;

	ll first_zero = s.size() - 1;
	for (first_zero = s.size() - 2;
		first_zero >= 0 && (s[first_zero] != s[first_zero + 1] || s[first_zero] != '0');
		first_zero--);
	first_zero++;

	if (last_one >= first_zero) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}
