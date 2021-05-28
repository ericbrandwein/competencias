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

	ll n, m;
	cin >> n>> m;


	if (m % n != 0) {
		cout << - 1 << endl;
		return 0;
	}
	ll div = m / n;
	ll moves = 0;
	while (div > 1 && div % 3 == 0) {
		div /= 3;
		moves++;
	}
	while (div > 1 && div % 2 == 0) {
		div /= 2;
		moves++;
	}


	if (div > 1) {
		cout << -1 << endl;
	} else {
		cout << moves << endl;
	}

	return 0;
}
