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

	ll la, ra, ta;
	cin >> la >> ra >> ta;
	ll lb, rb, tb;
	cin >> lb >> rb >> tb;
	ll gcd_ts = __gcd(ta, tb);

	ll buenos_a = ra - la + 1;
	ll buenos_b = rb - lb + 1;
	if (gcd_ts == 1) {
		cout << min(buenos_a, buenos_b) << endl;
		return 0;
	}
	ll sobra_b = (la-lb) % gcd_ts;
	if (sobra_b < 0) sobra_b += gcd_ts;
	// lo que tienen para atras
	ll sobra_a = abs(sobra_b - gcd_ts);
	ll mejor_sacando_b = min(buenos_b - sobra_b, buenos_a);
	ll mejor_sacando_a = min(buenos_a - sobra_a, buenos_b);
	cout << max(mejor_sacando_a, mejor_sacando_b) << endl;
	return 0;
}
