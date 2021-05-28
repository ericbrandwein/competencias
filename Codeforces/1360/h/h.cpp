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

void decrease(string& num) {
	ll i = num.size() - 1;
	for (; num[i] == '0'; i--) {
		num[i] = '1';
	}
	num[i] = '0';
}

void previous_num(string& num, set<string>& deleted) {
	do {
		decrease(num);
	} while (deleted.count(num) == 1);
}


void increase(string& num) {
	ll i = num.size() - 1;
	for (; num[i] == '1'; i--) {
		num[i] = '0';
	}
	num[i] = '1';
}



void next_num(string& num, set<string>& deleted) {
	do {
		increase(num);
	} while (deleted.count(num) == 1);
}


string solve(ll n, ll length, vector<string>& nums) {
	string middle = "0";
	for (ll i = 0; i < length - 1; i++) {
		middle.push_back('1');
	}

	set<string> deleted;
	bool even = true;
	for (string& num : nums) {
		deleted.insert(num);
		even = !even;
		if (middle > num && !even) {
			next_num(middle, deleted);
		} else if (middle < num && even) {
			previous_num(middle, deleted);
		} else if (middle == num) {
			if (even) {
				previous_num(middle, deleted);
			} else {
				next_num(middle, deleted);
			}
		}
	}
	return middle;
}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) {
		ll n, length;
		cin >> n >> length;
		vector<string> nums(n);

		forn (i) {
			cin >> nums[i];
		}

		cout << solve(n, length, nums) << endl;
	}

	return 0;
}
