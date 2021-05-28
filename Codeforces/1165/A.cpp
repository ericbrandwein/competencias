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

	ll n, x, y;
	cin >> n >> x >> y;
	
	string num;
	cin >> num;

	ll total = 0;
	for (ll i = 0; i < y; i++) {
		if (num[num.size() - 1 - i] != '0') {total++;}
	}
	if (num[num.size() - 1 - y] != '1') total++;
	for (ll i = y + 1; i < x; i++) {
		if (num[num.size() - 1 - i] != '0') total++;
	}
	for (ll i = x + 1; i < n; i++)
		if (num[num.size() - 1 - i] == '1')
			break;
		else if(i == n - 1) total++;

	cout << total << endl;

	return 0;
}
