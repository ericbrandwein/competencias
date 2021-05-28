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

	ll n;
	cin >> n;
	string letters;
	cin >> letters;

	vector<ll> intervals;
	char curr = letters[0];
	ll amount = 1;
	fore (i, 1, n) {
		if (letters[i] != curr) {
			intervals.push_back(amount);
			amount = 1;
			curr = letters[i];
		} else {
			amount++;
		}
	}
	intervals.push_back(amount);

	ll total = 0;
	ll usado = 0;
	fore (i, 0, intervals.size()) {
		ll curr_interval = intervals[i];
		usado += curr_interval;
		total += curr_interval * (curr_interval - 1) / 2;
		if (i < intervals.size() - 1) {
			total += (curr_interval - 1) * (intervals[i + 1] - 1);
			total += curr_interval * (n - usado - intervals[i + 1]);
		}
	}

	cout << total << endl;

	return 0;
}
