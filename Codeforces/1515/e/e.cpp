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

	ll n, mod;
	cin >> n >> mod;
	// [pos, amount_of_manual, pos_in_order] = combinations
	vec<vec<vec<int>>> prev_later(n, vec<vec<int>>(n + 1, vec<int>(3, 0)));
	vec<vec<vec<int>>> prev_before(n, vec<vec<int>>(n + 1, vec<int>(3, 0)));
	prev_later[0][1][0] = 1;
	prev_later[1][2][0] = 1;
	prev_before[1][2][1] = 1;
	for (ll i = 2; i < n; i++) {
		for (ll manual = 0; manual <= i; manual++) {
			prev_later[i][manual+1].resize(manual + 1);
			prev_before[i][manual+1].resize(manual + 1);
			// prev automatic
			ll combi = 0;
			for (ll pos = 0; pos < manual && pos < prev_later[i-2][manual].size(); pos++) {
				combi += prev_later[i-2][manual][pos];
				combi %= mod;
				combi += prev_before[i-2][manual][pos];
				combi %= mod;
			}

			for (ll pos = 0; pos <= manual; pos++) {
				ll num = (ll)prev_later[i][manual + 1][pos] + combi;
				num %= mod;
				prev_later[i][manual + 1][pos] = num;
			}

			// prev manual
			// either prev comes before prevprev, or we come later prev and prev comes later prevprev
			// prev < prevprev, so we can go anywhere
			vec<ll> combi_by_pos(manual + 1, 0);
			for (ll pos = manual-1; pos >= 0; pos--) {
				combi_by_pos[pos] = combi_by_pos[pos+1] + prev_later[i-1][manual][pos];
				combi_by_pos[pos] %= mod;
			}

			for (ll pos = 0; pos <= manual; pos++) {
				ll num = (ll)prev_later[i][manual + 1][pos] + combi_by_pos[pos];
				num %= mod;
				prev_later[i][manual + 1][pos] = num;
			}

			combi_by_pos = vec<ll>(manual+1, 0);
			for (ll pos = 0; pos < manual; pos++) {
				combi_by_pos[pos+1] = combi_by_pos[pos] + prev_later[i-1][manual][pos];
				combi_by_pos[pos] %= mod;
			}

			for (ll pos = 0; pos <= manual; pos++) {
				ll num = (ll)prev_before[i][manual + 1][pos] + combi_by_pos[pos];
				num %= mod;
				prev_before[i][manual + 1][pos] = num;
			}

			// prev > prevprev, so we have to go after prev
			combi_by_pos = vec<ll>(manual+1, 0);
			for (ll pos = 0; pos < manual; pos++) {
				combi_by_pos[pos+1] = combi_by_pos[pos] + prev_before[i-1][manual][pos];
				combi_by_pos[pos+1] %= mod;
			}

			for (ll pos = 0; pos <= manual; pos++) {
				ll num = (ll)prev_before[i][manual + 1][pos] + combi_by_pos[pos];
				num %= mod;
				prev_before[i][manual + 1][pos] = num;
			}
		}
	}

	ll total = 0;
	for (ll manual = 0; manual <= n; manual++) {
		for (ll pos = 0; pos < manual; pos++) {
			total += prev_before[n - 1][manual][pos];
			total %= mod;
			total += prev_later[n - 1][manual][pos];
			total %= mod;
		}
	}

	cout << total << endl;


}
