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
	ll n;
	cin >> n;
	string num;
	cin >> num;


	if (n % 2 == 1) {
		bool all_even = true;
		for (ll i = 0; i < num.size(); i+=2){
			all_even &= ((num[i] - '0') % 2 == 0);
		}
		if (all_even) cout << 2 << endl;
		else cout << 1 << endl;
	} else {
		bool any_even = false;
		for (ll i = 1; i < num.size(); i+=2){
			any_even |= ((num[i] - '0') % 2 == 0);
		}

		if (any_even) cout << 2 << endl;
		else cout << 1 << endl;
	}

}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}