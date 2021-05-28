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

vector<ll> sacar_primos(ll n) {
	vector<ll> primos;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			primos.push_back(i);
			while (n % i == 0) {
				n /= i;
			}
		}
	}

	if (n > 1) {
		primos.push_back(n);
	}
	return primos;
}

int main() {
	IOS;

	ll n;
	cin >> n;

	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	vector<ll> primos = sacar_primos(n);

	ll cant = 1;
	if (primos.size() == 1) {
		if (primos[0] == n) {
			cant = n;
		} else {
			cant = primos[0];
		}
	}

	cout << cant << endl;

	return 0;
}
