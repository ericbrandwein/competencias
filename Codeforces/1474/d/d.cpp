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
	vec<ll> a(n);
	vec<ll> necesito_izq(n, -1);
	vec<ll> necesito_der(n, -1);
	ll necesito = 0;
	forn (i) {
		cin >> a[i];
	}
	forn (i) {
		necesito_izq[i] = a[i] - necesito;
		if (necesito_izq[i] < 0) break;
		necesito = necesito_izq[i];
	}
	necesito = 0;
	for (ll i = a.size() -1; i >= 0; i--) {
		necesito_der[i] = a[i] - necesito;
		if (necesito_der[i] < 0) break;
		necesito = necesito_der[i];
	}
	if (necesito_izq.back() == 0) {
		cout << "YES" << endl;
		return;
	}

	for (ll i = 0; i < n - 1; i++) {
		ll izq = 0;
		if (i > 0) izq = necesito_izq[i - 1];
		ll der = 0;
		if (i+1 < n-1) der = necesito_der[i+2];
		ll izq_restado = a[i+1] - izq;
		ll der_restado = a[i] - izq_restado;
		if (izq >= 0 && der >= 0 && izq_restado >= 0 && der_restado >= 0 && der_restado == der) {
			cout << "YES" << endl;
			return;
		}
	}

	cout << "NO" << endl;

}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}
