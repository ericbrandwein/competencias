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

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int max_dist, period, from,to;
		cin >> max_dist >> period >> from >> to;

		int linternas_totales = max_dist / period;

		int linternas_no_vistas = 0;
		int cuando_empezamos = from % period;
		int primera_linterna = ((period - cuando_empezamos) % period) + from;
		if (primera_linterna <= to) {
			linternas_no_vistas++;
		}
		if (primera_linterna < to) {
			int primer_pos_sin_linterna = primera_linterna + 1;
			linternas_no_vistas += (to - primer_pos_sin_linterna + 1) / period;
		}

		cout << linternas_totales - linternas_no_vistas << endl;
	}

	return 0;
}
