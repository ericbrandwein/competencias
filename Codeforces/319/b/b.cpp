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

	ll max_wait = 0;
	stack<ll> decrecientes;
	stack<ll> waits;
	forn (i) {
		ll new_wait = 0;
		while (!decrecientes.empty() && nums[i] > decrecientes.top()) {
			new_wait = max(new_wait, waits.top() + 1);
			waits.pop();
			decrecientes.pop();
		}

		if (decrecientes.empty()) {
			new_wait = 0;
		} else if (new_wait == 0) {
			new_wait = 1;
		}
		max_wait = max(max_wait, new_wait);
		waits.push(new_wait);
		decrecientes.push(nums[i]);
	}

	cout << max_wait << endl;

	return 0;
}
