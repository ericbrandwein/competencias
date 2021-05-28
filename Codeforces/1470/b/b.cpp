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

vec<int> get_odd_factors(int num) {
	vec<int> odd_factors;
	for (int p = 2;p * p<= num ; p++) {
		int amount = 0;
		while (num % p == 0) {
			amount++;
			num /= p;
		}
		if (amount % 2 == 1) {
			odd_factors.push_back(p);
		}
	}
	if (num > 1) {
		odd_factors.push_back(num);
	}
	return odd_factors;
}

void solve() {
	ll n;
	cin >> n;
	vec<int> a(n);
	map<vec<int>, int> factorized;
	forn (i) {
		cin >> a[i];
		factorized[get_odd_factors(a[i])]++;
	}

	int first = 0;
	for (const pair<vec<int>, int>& entry : factorized) {
		first = max(first, entry.second);
	}
	int second = 0;
	map<vec<int>, int> second_pass = factorized;
	for (const pair<vec<int>, int>& entry : factorized) {
		if (!entry.first.empty() && entry.second % 2 == 0) {
			second_pass[vec<int>{}] += entry.second;
			second_pass.erase(entry.first);
		}
	}
	second = first;
	for (const pair<vec<int>, int>& entry : second_pass) {
		second = max(second, entry.second);
	}


	ll q;
	cin >> q;
	vec<ll> queries(q);
	fore (i, 0, q) {
		cin >> queries[i];
		if (queries[i] == 0) {
			cout << first << endl;
		} else {
			cout << second << endl;
		}
	}
}


int main() {
	IOS;
	ll t;
	cin >> t;
	while (t--) solve();
}
