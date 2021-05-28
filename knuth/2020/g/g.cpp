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

const ll MAX_DIG = 18;
const char INF = '9' + 1;

string num_to_string(ll num) {
	string res = "";
	while (num > 0) {
		int dig = num % 10;
		res.push_back('0' + dig);
		num /= 10;
	}
	sort(res.rbegin(), res.rend());

	for (ll i = res.size(); i < MAX_DIG; i++) {
		res.push_back(INF);
	}
	return res;
}


int main() {
	IOS;

	ll n;
	cin >> n;
	vector<ll> a(n);
	forn (i) cin >> a[i];

	vector<string> nums(n);
	forn (i) {
		nums[i] = num_to_string(a[i]);
	}

	sort(nums.rbegin(), nums.rend());


	for (string num : nums) {
		for (ll i = 0; i < num.size() && num[i] != INF; i++) {
			cout << num[i];
		}
	}
	cout << endl;

	return 0;
}
