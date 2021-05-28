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

const ll MOD = 1'000'000'007;

int main() {
	IOS;

	string num;
	cin >> num;

	vec<ll> pot10(num.size() + 1);
	pot10[0] = 1;
	for (ll i = 1; i < num.size()+1; i++) {
		pot10[i] = (pot10[i-1] *10) % MOD;
	}

	vec<ll> sum10(num.size() + 1);
	sum10[0] = 0;
	for (ll i = 1; i < num.size()+1; i++) {
		sum10[i] = sum10[i-1] + pot10[i-1];
		sum10[i] %= MOD;
	}

	ll suma = 0;
	ll multiplicado = 0;
	for (ll i = num.size()- 1; i >= 0; i--) {
		ll derecha = num.size() - i- 1;
		if (derecha > 0) {
			multiplicado *= 10;
			multiplicado %= MOD;
			multiplicado += sum10[derecha];
			multiplicado %= MOD;
		}
		suma += (num[i] - '0') * multiplicado;
		suma %= MOD;
		ll temp = (num[i] - '0')*pot10[derecha];
		temp %= MOD;
		temp *= (i*(i+1)/2) % MOD;
		temp %= MOD;
		suma += temp;
		suma %= MOD;
	}

	cout << suma << endl;

	return 0;
}
