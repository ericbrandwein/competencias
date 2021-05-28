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

const ll MOD = 1e9 + 7;

int main() {
	IOS;


	string s;
	cin >> s;

	vector<ll> potencias(s.size() + 1);
	potencias[0] = 1;
	for (ll i = 1; i < potencias.size(); i ++) {
		potencias[i] = (potencias[i - 1] * 2) % MOD;
	}

	ll aes = 0;
	ll total = 0;
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] == 'a') {
			aes++;
		} else if (s[i] == 'b') {
			total += potencias[aes] - 1;
			total %= MOD;
		}
	}

	cout << total << endl;

	return 0;
}
