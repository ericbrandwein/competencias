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
	while (t--) {
		ll n;
		cin >> n;
		ll a, b, c;
		cin >> a >> b >> c;

		string bob;
		cin >> bob;
		ll boba = 0, bobb = 0, bobc = 0;
		forn (i) {
			if (bob[i] == 'R') boba++;
			if (bob[i] == 'P') bobb++;
			if (bob[i] == 'S') bobc++;
		}

		ll ua = 0, ub = 0, uc = 0;
		ub = max(0LL, b - boba);
		uc = max(0LL, c - bobb);
		ua = max(0LL, a - bobc);

		if (ub + ua + uc > n / 2) {
			cout << "NO" << endl;
		} else {
			string alice = "";
			forn (i) {
				if (bob[i] == 'R') {
					if (b > 0) {
						alice.push_back('P');
						b--;
					} else if (ua > 0) {
						alice.push_back('R');
						ua--;
						a--;
					} else {
						alice.push_back('S');
						uc--;
						c--;
					}
				} else if (bob[i] == 'P') {
					if (c > 0) {
						alice.push_back('S');
						c--;
					} else if (ub > 0) {
						alice.push_back('P');
						ub--;
						b--;
					} else {
						alice.push_back('R');
						ua--;
						a--;
					}
				} else {
					if (a > 0) {
						alice.push_back('R');
						a--;
					} else if (ub > 0) {
						alice.push_back('P');
						ub--;
						b--;
					} else {
						alice.push_back('S');
						uc--;
						c--;
					}
				}
			}
			cout << "YES" << endl;
			cout << alice << endl;
		}
	}
	return 0;
}
