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

void solve(ll n) {
	vec<ll> pilas(2, 0);
	forn (i) {
		string action;
		ll plates;
		cin >> action >> plates;
		if ( action == "DROP") {
			cout << "DROP 1 "<< plates << endl;
			pilas[0] += plates;
		} else {
			if (pilas[1] > 0){
				ll sacados = min(plates, pilas[1]);
				cout << "TAKE 2 " << sacados << endl;
				pilas[1] -= sacados;
				plates -= sacados;
			}
			if (plates > 0) {
				cout << "MOVE 1->2 " << pilas[0] << endl;
				pilas[1] = pilas[0];
				pilas[0] = 0;
				cout << "TAKE 2 " << plates << endl;
				pilas[1] -= plates;
			}
		}
	}
	cout << endl;
}


int main() {
	IOS;

	ll n;
	cin >> n;
	while(n != 0) {
		solve(n);

		cin >> n;
	}


	return 0;
}
