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
	vec<ll> c(n);
	forn (i) cin >> c[i];
	vec<pair<ll,ll>> conectados_antes(n);
	forn (i) {
		cin >> conectados_antes[i].first;
	}
	forn (i) {
		cin >> conectados_antes[i].second;

		if (conectados_antes[i].first > conectados_antes[i].second) {
			swap(conectados_antes[i].first, conectados_antes[i].second);
		}
	}
	vec<ll> max_ciclo(n);
	max_ciclo[0] = 0;
	ll max_total = max_ciclo[0];
	fore(i, 1, n) {
		ll ciclo_puntas = 0;
		if (conectados_antes[i].first != conectados_antes[i].second && i > 1) {
			ciclo_puntas = conectados_antes[i].first +
				c[i-1] - conectados_antes[i].second + 1 + max_ciclo[i-1];
		}
		ll ciclo_interno = conectados_antes[i].second - conectados_antes[i].first + 1;
		max_ciclo[i] = max(ciclo_puntas, ciclo_interno);
		max_total = max(max_total, max_ciclo[i] + c[i]);
	}
	cout << max_total << endl;

}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();
}
