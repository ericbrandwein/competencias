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
	ll n, q;
	cin >> n >> q;
	vec<string> students(n);
	vec<ll> scores(n);
	ll max_i = 0;
	forn (i) {
		cin >> students[i] >> scores[i];
		if (scores[i] * 2 < q) {
			for (ll j = 0; j < q; j++) {
				if (students[i][j] == 'T') {
					students[i][j] = 'F';
				} else {
					students[i][j] = 'T';
				}
			}
			scores[i] = q - scores[i];
		}
		if (scores[i] > scores[max_i]) {
			max_i = i;
		}
	}

	cout << students[max_i] <<" " << scores[max_i] << "/1"<< endl;

}

int main() {
	IOS;

	ll t;
	cin >> t;
	fore (i, 0, t) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}

}
