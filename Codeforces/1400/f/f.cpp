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

bool check_x_prime(string& s, ll from, ll to, ll x) {
	bool x_prime = true;
	for (ll i = from; i <= to; i++) {
		ll sum = 0;
		for (ll j = i; j <= to; j++) {
			sum += s[j] - '0';
			if (sum != x && x % sum == 0) {
				x_prime = false;
			}
		}
	}
	return x_prime;
}

int main() {
	IOS;

	string s;
	cin >> s;
	ll x;
	cin >> x;

	ll total = 0;
	ll last_indep = -1;
	ll from = 0;
	ll sum = 0;
	for (ll i = 0; i < s.size(); i++) {
		sum += s[i] - '0';
		while (sum > x) {
			sum -= s[from] - '0';
			from++;
		}
		if (sum == x && from > last_indep && check_x_prime(s, from, i, x)) {
			last_indep = i;
			total++;
		}
	}

	cout << total << endl;


	return 0;
}
