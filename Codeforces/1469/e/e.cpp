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
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	ll beginning = max(0LL,k - 20);
	vec<ll> res(beginning,0);
	set<ll> used;
	ll ones = 0;
	for (ll i = 0; i <= n - (k - beginning); i++) {
		if (ones >= beginning) {
			ll num = 0;
			for (ll j = i; j < i + k - beginning; j++) {
				num <<= 1;
				num += 1-(s[j] - '0');
			}
			used.insert(num);
		}
		if (s[i] == '1') {
			ones++;
		} else {
			ones = 0;
		}
 	}

	ll pot = 1;
	for (ll i = 0; i < k-beginning; i++) {
		pot *= 2;
	}


	if (used.size() >= pot) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		ll ant = 0;
		for (ll num : used) {
			if (num > ant) {
				break;
			}
			ant = num + 1;
		}
		vec<ll> binary;
		while (binary.size() < k - beginning) {
			binary.push_back(ant%2);
			ant /= 2;
		}
		reverse(all(binary));
		for (ll i = 0; i < k - beginning; i++) {
			res.push_back(binary[i]);
		}
		for (ll num : res) {
			cout << num;
		}
		cout << endl;

	}
}

int main() {
	IOS;

	ll q;
	cin >> q;
	while (q--) solve();


}
