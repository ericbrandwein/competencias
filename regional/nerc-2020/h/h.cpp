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
	ll n, k, m;
	cin >> n >> k >> m;
	vec<ll> b(m);
	vec<bool> present(n + 1, false);
	ll de_cada_lado = (k-1) / 2;
	ll eliminados = n - m;
	ll curr_eliminados = 0;
	ll anterior = 0;
	bool puede = false;
	fore (i, 0, m) {
		cin >> b[i];
		present[b[i]] = true;
		curr_eliminados += b[i] - anterior - 1;
		anterior = b[i];
		if (curr_eliminados >= de_cada_lado && eliminados - curr_eliminados >= de_cada_lado) {
			puede = true;
		}
	}

	if (eliminados % (k-1) != 0 || !puede) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
	}



}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}
