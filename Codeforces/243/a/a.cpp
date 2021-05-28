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
	vector<bitset<20>> nums(n);
	vector<vector<ll>> latest_found(n, vector<ll>(20, -1));

	set<ll> results;
	forn (i) {
		ll num;
		cin >> num;
		results.insert(num);
		nums[i] = bitset<20>(num);
		for (ll bit = 0; bit < 20; bit++) {
			if (nums[i].test(bit)) {
				latest_found[i][bit] = 0;
			} else if (i > 0 and latest_found[i - 1][bit] != -1) {
				latest_found[i][bit] = latest_found[i - 1][bit] + 1;
			}
		}
	}

	forn (i) {
		bitset<20> current_res;
		for (ll bit = 0; bit < 20; bit++) {
			if (latest_found[i][bit] != -1) {
				current_res.set(bit);
			}
		}

		while (current_res.any()) {
			results.insert(current_res.to_ullong());
			ll greatest = 0;
			for (ll bit = 0; bit < 20; bit++) {
				greatest = max(greatest, latest_found[i][bit]);
			}
			for (ll bit = 0; bit < 20; bit++) {
				if (latest_found[i][bit] == greatest) {
					latest_found[i][bit] = -1;
					current_res.reset(bit);
				}
			}
		}
	}

	cout << results.size() << endl;

	return 0;
}
