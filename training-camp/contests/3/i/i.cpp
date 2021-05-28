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

	ll n;
	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}

	vector<ll> combi(n, 0);
	combi[0] = 1;
	combi[1] = 2;
	for (ll i = 2; i < n; i++) {
		combi[i] = (combi[i - 1] + combi[i - 2] + 1) % MOD;
	}

	cout << (combi[n - 1] + combi[n - 2]) % MOD << endl;


	return 0;
}
