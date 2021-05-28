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

	ll t;
	cin >> t;
	fore (i, 0, t) {
		ll n;
		cin >> n;
		vector<ll> p(n);
		ll ppares = 0;
		ll pimpares = 0;
		forn (j) {
			cin >> p[j];
			if (p[j] % 2 == 0) ppares++;
			else pimpares++; 
		}
		ll m;
		cin >> m;
		vector<ll> q(m);
		ll qpares = 0;
		ll qimpares = 0;
		fore (j, 0, m) {
			cin >> q[j];
			if (q[j] % 2 == 0) qpares++;
			else qimpares++;
		}

		cout << ppares * qpares + pimpares * qimpares << endl;

	}	

	return 0;
}
