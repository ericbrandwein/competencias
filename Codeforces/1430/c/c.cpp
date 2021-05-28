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
	ll n;
	cin >> n;

	// cout << (n+1) / 2 << endl;
	// if (n % 2 == 1) {
	// 	vec<ll> nums;
	// 	nums.push_back((n+1) / 2);
	// 	for (ll i = 1; n - i + 1 > i ; i++) {
	// 		nums.push_back((i+(n-i+1)) / 2);
	// 		cout << i << " " << n-i+1 << endl;
	// 	}
	// 	for (ll i = 0 ; i < nums.size() - 1; i++) {
	// 		cout << nums[i] << " " << nums[i+1] << endl;
	// 	}
	// } else {
		multiset<ll> pares;
		multiset<ll> impares;
		for (ll i = 1; i <= n; i+=2) {
			impares.insert(i);
		}
		for (ll i = 2; i <= n; i+=2) {
			pares.insert(i);
		}
		vec<pair<ll,ll>> res;
		while (pares.size() > 1 || impares.size() > 1) {
			while (pares.size() > 1) {
				auto big = --pares.end();
				auto second = big;
				second--;
				ll num1 = *big, num2 = *second;
				pares.erase(big);
				pares.erase(second);
				res.push_back({num1, num2});
				ll new_num = (num1 + num2) / 2;
				if (new_num % 2 == 0) {
					pares.insert(new_num);
				} else {
					impares.insert(new_num);
				}
			}
			while (impares.size() > 1) {
				auto big = --impares.end();
				auto second = big;
				second--;
				ll num1 = *big, num2 = *second;
				impares.erase(big);
				impares.erase(second);
				res.push_back({num1, num2});
				ll new_num = (num1 + num2) / 2;
				if (new_num % 2 == 0) {
					pares.insert(new_num);
				} else {
					impares.insert(new_num);
				}
			}
		}

		if (!pares.empty() && !impares.empty()) {
			res.push_back({*impares.begin(), *pares.begin()});
		}
	// }

	cout << (res.back().first + res.back().second + 1) / 2 << endl;
	for (pair<ll,ll> elem : res) {
		cout << elem.first << " " << elem.second << endl;
	}
}

int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--)solve();

	return 0;
}
