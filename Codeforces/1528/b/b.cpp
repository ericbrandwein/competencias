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

const ll MOD = 998244353;

const int N = 10000000;
int lp[N+1];
vector<int> pr;
void sieve() {
	for (int i=2; i<=N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back (i);
		}
		for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
			lp[i * pr[j]] = pr[j];
	}
}


ll cant_de_divisores(ll n) {
	ll primo_actual = 1;
	ll cant_actual = 0;
	ll res = 1;
	while (n != 1) {
		if (lp[n] == primo_actual) cant_actual++;
		else {
			res *= cant_actual + 1;
			res %= MOD;
			cant_actual = 1;
			primo_actual = lp[n];
		}
		n = n / lp[n];
	}
	res *= cant_actual + 1;
	res %= MOD;
	return res;
}




int main() {
	IOS;


	ll n;
	cin >> n;
	sieve();
	ll acum = 0;
	vec<ll> f(n + 1);
	f[0] = 0;
	for (ll i = 1; i <= n; i++) {
		f[i] = acum + cant_de_divisores(i);
		f[i] %= MOD;
		acum += f[i];
		acum %= MOD;
		// cout << "f(" << i << ") = " << f[i] << endl;
	}

	cout << f[n] << endl;


}
