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

bool puedo_mover(ll from, vec<vec<ll>>& digits, ll k, ll convertido, ll n) {
	ll otro = 1-convertido;
	ll ult_otro = digits[otro].back();
	ll prim_otro = digits[otro].front();
	if (prim_otro >= from && prim_otro < from + k) {
		auto it = lower_bound(digits[otro].begin(), digits[otro].end(), from + k);
		if (it == digits[otro].end()) {
			// no hay más del otro (nunca debería pasar)
			return false;
		} else {
			prim_otro = *it;
		}
	}
	if (ult_otro >= from && ult_otro < from + k) {
		auto it = lower_bound(digits[otro].begin(), digits[otro].end(), from);
		if (it == digits[otro].begin()) {
			return false;
		} else {
			it--;
			ult_otro = *it;
		}
	}
	return ult_otro - prim_otro >= k;
}

int main() {
	IOS;

	ll n  ,k;
	cin >> n >> k;
	string nums;
	cin >> nums;

	vec<vec<ll>> digits(2);
	ll prim_1 = n;
	ll prim_0 = n;
	ll ult_0 = -1;
	ll ult_1 = -1;
	for (ll i = 0; i < n; i++) {
		digits[nums[i] - '0'].push_back(i);
		if (nums[i] == '1') {
			prim_1 = min(prim_1, i);
			ult_1 = max(ult_1, i);
		} else {
			prim_0 = min(prim_0, i);
			ult_0 = max(ult_0, i);
		}
	}

	vec<string> jugadores = {"tokitsukaze", "quailty", "once again"};
	if (ult_1 - prim_1 < k || ult_0 - prim_0 < k) {
		cout << jugadores[0] << endl;
		return 0;
	}

	ll ganador = 1;
	for (ll i = 0; i +k <= n; i++) {
		// pinto todo de 0
		if (puedo_mover(i, digits, k, 0, n) || puedo_mover(i, digits, k, 1, n)) {
			ganador = 2;
		}
	}

	cout << jugadores[ganador] << endl;



	return 0;
}
