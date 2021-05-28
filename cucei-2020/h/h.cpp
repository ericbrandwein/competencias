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


const int MAX_N = 10'000;
const ll MOD = 1e9 + 7;

vec<vec<int>> calc_acums() {
	vec<vec<int>> combi(MAX_N + 1, vec<int>(MAX_N + 1, 0));
	for (ll i = 0; i <= MAX_N; i++) {
		combi[i][0] = 1;
		combi[i][i] = 1;
	}

	for (ll i = 1; i <= MAX_N; i++) {
		for (ll j = 1; j < i; j++) {
			combi[i][j] = ((ll)combi[i-1][j] + (ll)combi[i-1][j-1]) % MOD;
		}
	}

	vec<vec<int>> acums(MAX_N + 1, vec<int>(MAX_N+1, 0));
	for (ll i = 0; i <= MAX_N; i++) {
		ll acum = 0;
		for (ll j = 0; j <= MAX_N; j++) {
			acum += combi[i][j];
			acum %= MOD;
			acums[i][j] = acum;
		}
	}

	return acums;

}

int main() {
	IOS;

	// acums[i][j] = sumatoria de [0;j]
	vec<vec<int>> acums = calc_acums();
	ll t;
	cin >> t;
	while (t--) {
		ll n, a, b;
		cin >> n >> a >> b;
		ll suma = (acums[n][b] - acums[n][a-1]) % MOD;
		if (suma  < 0) suma += MOD;
		cout << suma << endl;
	}


}
