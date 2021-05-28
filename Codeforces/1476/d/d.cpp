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
	string s;
	cin >> s;
	vec<ll> max_alternado_izq(n+1, 0);
	max_alternado_izq[1] = 1;
	fore (i, 2, n + 1)  {
		if (s[i - 1] != s[i-2]) {
			max_alternado_izq[i] = 1 + max_alternado_izq[i-1];
		} else {
			max_alternado_izq[i] = 1;
		}
	}

	vec<ll> max_alternado_der(n+1, 0);
	max_alternado_der[n-1] = 1;
	for (ll i = n-2; i >= 0; i--)  {
		if (s[i ] != s[i+1]) {
			max_alternado_der[i] = 1 + max_alternado_der[i+1];
		} else {
			max_alternado_der[i] = 1;
		}
	}

	fore (i, 0, n+1) {
		ll suma = 1;
		if (i > 0 && s[i-1] == 'L') suma += max_alternado_izq[i];
		if (i < n && s[i] == 'R') suma += max_alternado_der[i];
		cout << suma << " ";
	}
	cout << endl;
}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}
