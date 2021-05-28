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

void solve() {
	ll n;
	cin >> n;
	ll pos = 0;
	ll last_t = 0;
	ll dest = 0;
	ll last_dest = 0;
	ll successful = 0;
	forn (i) {
		ll t, new_pos;
		cin >> t >> new_pos;
		if (i == 0) {
			last_t = t;
			dest = new_pos;
			last_dest = new_pos;
		} else {
			ll dir = 1;
			if (dest < pos) dir = -1;
			ll time_passed = t - last_t;
			ll time_needed = abs(dest - pos);
			ll time_moved = min(time_passed, time_needed);
			ll curr_pos = pos + dir*time_moved;
			if (min(pos, curr_pos) <= last_dest && last_dest <= max(pos, curr_pos)) {
				successful++;
			}
			if (time_needed <= time_passed) {
				dest = new_pos;
			}
			last_dest = new_pos;
			pos = curr_pos;
			last_t = t;
		}
	}


	if (min(pos, dest) <= last_dest && last_dest <= max(pos, dest)) {
		successful++;
	}


	cout << successful << endl;
}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) solve();

}
