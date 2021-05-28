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

vector<ll> get_divisors(ll k) {
	vector<ll> divisors;
	for (ll i = 1; i * i <= k; i++) {
		if (k % i == 0) {
			divisors.push_back(i);
			if (k / i != i) {
				divisors.push_back(k / i);
			}
		}
	}
	return divisors;
}

map<char, ll> get_available(string& s) {
	map<char, ll> available;
	for (char c : s) {
		available[c]++;
	}
	return available;
}


bool check_can_make(map<char, ll>& available, ll rep_length, ll rep_amount) {
	ll remaining = rep_length;

	for (const pair<char, ll>& curr : available) {
		if (curr.second >= rep_amount) {
			remaining -= curr.second / rep_amount;
		}
	}
	return remaining <= 0;
}

void solve() {
	ll n, k;
	cin >> n >> k;

	string s;
	cin >> s;


	map<char, ll> available = get_available(s);
	vector<ll> divisors = get_divisors(k);

	ll max_length = 1;
	for (ll divisor : divisors) {
		for (ll repeated = 1; repeated * divisor <= n; repeated++) {
			if (check_can_make(available, divisor, repeated)) {
				max_length = max(max_length, repeated*divisor);
			}
		}
	}

	cout << max_length << endl;

}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}
