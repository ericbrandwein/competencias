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
	forn (i) {
		cin >> nums[i];
	}

	vector<ll> lower_left(n, -1);
	vector<ll> lower_right(n, n);
	stack<ll> previous;
	fore (i, 0, n) {
		while (!previous.empty() && nums[previous.top()] >= nums[i]) {
			ll previous_index = previous.top();
			previous.pop();
			lower_right[previous_index] = i;
		}
		if (!previous.empty()) {
			lower_left[i] = previous.top();
		}
		previous.push(i);
	}


	vector<ll> higher_left(n, -1);
	vector<ll> higher_right(n, n);
	previous = stack<ll>();
	fore (i, 0, n) {
		while (!previous.empty() && nums[previous.top()] <= nums[i]) {
			ll previous_index = previous.top();
			previous.pop();
			higher_right[previous_index] = i;
		}
		if (!previous.empty()) {
			higher_left[i] = previous.top();
		}
		previous.push(i);
	}

	ll total = 0;
	forn (i) {
		ll diff_higher_left = i - higher_left[i];
		ll diff_higher_right = higher_right[i] - i;
		total += diff_higher_left * diff_higher_right * nums[i];

		ll diff_lower_left = i - lower_left[i];
		ll diff_lower_right = lower_right[i] - i;
		total -= diff_lower_left * diff_lower_right * nums[i];
	}

	cout << total << endl;


	return 0;
}
