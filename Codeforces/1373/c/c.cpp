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
	string s;
	cin >> s;
	vector<ll> sums(s.size() + 1);
	sums[0] = 0;
	vector<ll> first_mins;
	ll res = s.size();
	fore (i, 1, s.size() + 1) {
		sums[i] = sums[i - 1];
		if (s[i - 1] == '+') {
			sums[i]++;
		} else {
			sums[i]--;
		}
		if (sums[i] < 0) {
			if (-sums[i] > first_mins.size()) {
				first_mins.push_back(i);
				res += i;
			}
		}
	}

	cout << res << endl;

}


int main() {
	IOS;


	ll t;
	cin >> t;
	while (t--) {
		solve();
	}



	return 0;
}
