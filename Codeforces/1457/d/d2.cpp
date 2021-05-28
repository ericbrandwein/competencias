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

int highest_bit(unsigned int n) {
	return n ? 32 - __builtin_clz(n) : -1;
}


ll min_moves_for(vec<ll>& nums, ll pos) {
	ll curr = 0;
	ll moves = 0;
	ll min_moves = LONG_LONG_MAX;
	for (ll i = pos; i > 0; i--) {
		curr ^= nums[i];
		if (nums[i-1] > curr) {
			min_moves = min(min_moves, moves);
			break;
		} else if (highest_bit(nums[i-1]) < highest_bit(nums[i])) {
			break;
		} else {
            ll i_curr = 0;
            ll i_moves = 0;
            for (ll j = i - 1; j >= 0; j--) {
                i_curr ^= nums[j];
                if (i_curr > nums[pos]) {
                    min_moves = min(min_moves, moves + i_moves);
                    break;
                }
                i_moves++;
            }
        }
		moves++;
	}


	return min_moves;
}

int main() {
	IOS;

	ll n;
	cin >> n;
	vec<ll> a(n);
	forn (i) cin >> a[i];

	vec<ll> highest_bits(n);
	for (ll i = 0; i < n; i++) {
		highest_bits[i] = highest_bit(a[i]);
	}

	for (ll i = 0; i <= n - 3; i++) {
		if (
			highest_bits[i] == highest_bits[i+1] &&
			highest_bits[i+1] == highest_bits[i+2] &&
			highest_bits[i] != -1
		) {
			cout << 1 << endl;
			return 0;
		}
	}

	ll min_moves = LONG_LONG_MAX;
	for (ll i = 0; i < n -1 ; i++) {
		if (highest_bits[i] != -1 && highest_bits[i] == highest_bits[i+1]) {
			min_moves = min(min_moves, min_moves_for(a, i+1));
            ll i_curr = 0;
            ll i_moves = 0;
            for (ll j = i; j >= 0; j--) {
                i_curr ^= a[j];
                if (i_curr > a[i+1]) {
                    min_moves = min(min_moves, i_moves);
                    break;
                }
                i_moves++;
            }
		}
	}

	if (min_moves == LONG_LONG_MAX) {
		cout << -1 << endl;
	} else {
		cout << min_moves << endl;
	}


}
