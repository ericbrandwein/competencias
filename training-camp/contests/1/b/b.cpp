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
	cin >> n >> m;

	vector<ll> fact(n + 1);
	fact[0] = 1;
	fore (i, 1, n + 1) {
		fact[i] = (fact[i - 1] * i) % m;
	}

	ll total = 0;

	fore (i, 0, n) {
		ll curr_hap = fact[n - i] * (n - i);
		curr_hap %= m;
		curr_hap *= fact[i + 1];
		curr_hap %= m;
		total += curr_hap;
		total %= m;
	}

	cout << total << endl;


	return 0;
}
