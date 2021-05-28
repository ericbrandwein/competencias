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
#define deb(x) cerr<<#x<<" = "<<x<<endl
#define PI 3.14159265358979323
#define sen(ang) sin((ang)*PI/180)
//cout<<flush;

using namespace std;

int main() {
	IOS;

	string l;
	cin >> l;


	fore (i, 1, l.size()) {
		vector<bool> p(3, false);
		for (ll j = i - 1; j <= i+1 && j < l.size(); j++ ) {
			if (l[j] != '.') {
				p[l[j] - 'A'] = true;
			}
		}
		bool all_true = true;
		fore (i, 0, 3) {
			all_true &= p[i];	
		}
		if (all_true) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;
	return 0;
}
