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

ll resolver(ll n, ll m, ll p1, ll p2) {
	if (n == 0 && p1 == 0 && p2 == 0) return 1;
	if (n == 0) return 0;
	if (p1 <= 0 || p2 <= 0) return 0;

	ll res = resolver(n - 1, m, p1, p2);

	for (int i = 1; i <= m; i++)
		res = ((res + resolver(n - 1, m, p1 - i, p2)) % 1000000007
		     + resolver(n - 1, m, p1, p2 - i)) % 1000000007;
	
	return res;
}

int main() {
	IOS;
	ll n, m, p1, p2;
	cin >> n >> m >> p1 >> p2;
	cout << resolver(n, m, p1, p2) << endl;
	return 0;
}
