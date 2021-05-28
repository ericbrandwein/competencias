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

const vec<ll> digits = {
	0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 0b1101011,
	0b1101111, 0b1010010, 0b1111111, 0b1111011
};

ll to_num(string& s) {
	ll res = 0;
	for (ll i = 0; i < 7; i++) {
		res <<= 1;
		res += s[i] - '0';
	}
	return res;
}

bool contains(ll a, ll b) {
	return (a & b) == b;
}

ll diff(ll a, ll b) {
	if (contains(a, b)) {
		return __builtin_popcount(a & ~b);
	} else {
		return -1;
	}
}

int main() {
	IOS;

	ll n, k;
	cin >> n >> k;

	vec<ll> prendidos(n);
	forn (i) {
		string curr;
		cin >> curr;
		prendidos[i] = to_num(curr);
	}

	vec<vec<ll>> best_with_k(n, vec<ll>(k + 1, -1));
	for (ll i = n -1; i >=0; i--) {
		for (ll j = 0; j < 10; j++) {
			ll digit = digits[j];
			if (contains(digit, prendidos[i])) {
				ll k_needed = diff(digit, prendidos[i]);
				if (i == n-1) {
					best_with_k[i][k_needed] = max(best_with_k[i][k_needed], j);
				} else {
					for (ll used = k_needed; used <= k; used++) {
						if (best_with_k[i + 1][used - k_needed] != -1 &&
							best_with_k[i][used] < j) {
							best_with_k[i][used] = j;
						}
					}
				}
			}
		}
	}

	for (ll i = 0; i < n; i++) {
		ll digit = best_with_k[i][k];
		if (digit == -1) {
			cout << -1 << endl;
			return 0;
		}
		cout << digit;
		k -= diff(digits[digit], prendidos[i]);
	}
	cout << endl;




	return 0;
}
