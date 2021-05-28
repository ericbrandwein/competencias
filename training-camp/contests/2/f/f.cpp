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

	ll n, k;
	cin >> n >> k;

	vector<vector<ll>> posib(k + 2, vector<ll>(n+1, 0));
	fore (i, 1, n + 1) {
		posib[1][i] = 1;
	}
	fore (i, 1, k+2) {
		fore (j, 1, n+1) {
			for (ll multiplo = j; multiplo <= n; multiplo += j) {
				posib[i][j] += posib[i - 1][multiplo];
				posib[i][j] %= MOD;
			}
		}
	}


	cout << posib[k + 1][1] << endl;



	return 0;
}
