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
	vector<ll> nums(n);
	vector<vector<ll>> parents(n);
	forn (i) {
		cin >> nums[i];
		if (i - nums[i] >= 0) {
			parents[i - nums[i]].push_back(i);
		}
		if (i + nums[i] < n) {
			parents[i + nums[i]].push_back(i);
		}
	}

	vector<ll> dist_even(n, -1);
	vector<ll> dist_odd(n, -1);
	queue<ll> next_even, next_odd;
	for (ll i = 0; i < n; i++) {
		if (nums[i] % 2 == 0) {
			next_even.push(i);
			dist_even[i] = 0;
		} else {
			next_odd.push(i);
			dist_odd[i] = 0;
		}
	}

	while (!next_even.empty()) {
		ll current = next_even.front(); next_even.pop();
		for (ll parent : parents[current]) {
			if (dist_even[parent] == -1) {
				dist_even[parent] = dist_even[current] + 1;
				next_even.push(parent);
			}
		}
	}

	while (!next_odd.empty()) {
		ll current = next_odd.front(); next_odd.pop();
		for (ll parent : parents[current]) {
			if (dist_odd[parent] == -1) {
				dist_odd[parent] = dist_odd[current] + 1;
				next_odd.push(parent);
			}
		}
	}

	forn (i) {
		if (nums[i] % 2 == 0) {
			cout << dist_odd[i] << " ";
		} else {
			cout << dist_even[i] << " ";
		}
	}
	cout << endl;


	return 0;
}
