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

ll find_max_xor(multiset<ll>& nums, ll x) {
	ll res = 0;
	ll found = 0;
	for (ll curr_bit_pos = 32; curr_bit_pos >= 0; curr_bit_pos--) {
		ll curr_bit = (x >> curr_bit_pos) & 1;
		// tenemos que encontrar uno que tenga el bit diferente
		ll searched_bit = (curr_bit + 1) % 2;

		ll searched_min = ((found << 1) + searched_bit) << curr_bit_pos;
		ll searched_max = searched_min + (1 << curr_bit_pos) - 1;
		auto it_min = nums.lower_bound(searched_min); // el primero mayor o igual
		if (it_min == nums.end() || *it_min > searched_max) {
			// no encontramos ninguno que sirva
			res <<= 1;
			res += 0;
			found <<= 1;
			found += curr_bit;
		} else {
			// encontramos uno
			res <<= 1;
			res += 1;
			found <<= 1;
			found += searched_bit;
		}
	}

	return res;
}


int main() {
	IOS;

	ll q;
	cin >> q;

	multiset<ll> nums;
	nums.insert(0);

	fore (i, 0, q) {
		char op;
		ll x;
		cin >> op >> x;
		if (op == '+') {
			nums.insert(x);
		} else if (op == '-') {
			nums.erase(nums.find(x));
		} else {
			cout << find_max_xor(nums, x) << endl;
		}
	}

	return 0;
}
