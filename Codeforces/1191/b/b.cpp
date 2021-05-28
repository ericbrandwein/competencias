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

	vec<string> cards(3);
	map<char, vec<ll>> nums;
	for (ll i = 0; i < 3; i++) {
		cin >> cards[i];
		nums[cards[i][1]].push_back(cards[i][0] - '0');
	}

	ll mini = 2;
	for (const pair<char, vec<ll>>& entry : nums) {
		vec<ll> digits = entry.second;
		sort(all(digits));
		ll amount_equal = 1;
		ll seguidos = 1;
		bool separados = false;
		for (ll i = 1; i < digits.size(); i++) {
			if (digits[i] == digits[i-1]) amount_equal++;
			if (digits[i-1] + 1 == digits[i]) seguidos++;
			if (digits[i-1] + 2 == digits[i]) separados = true;
		}
		if (amount_equal == 3) {
			mini = 0;
		} else if (amount_equal == 2) {
			mini = min(mini, 1ll);
		}
		if (seguidos == 3) {
			mini = 0;
		} else if (seguidos == 2) {
			mini = min(mini, 1ll);
		}
		if (separados) {
			mini = min(mini, 1ll);
		}
	}

	cout << mini << endl;


	return 0;
}
