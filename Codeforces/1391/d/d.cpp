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

bool is_valid(ll prev_combi, ll curr_combi, ll n) {
	vec<ll> prev_nums;
	vec<ll> curr_nums;
	for (ll i = 0; i < n; i++) {
		prev_nums.push_back(prev_combi % 2);
		curr_nums.push_back(curr_combi % 2);
		prev_combi >>= 1;
		curr_combi >>= 1;
	}

	bool valid = true;
	for (ll i = 0; i < n - 1; i++) {
		ll ones = 0;
		ones += prev_nums[i] + prev_nums[i + 1] + curr_nums[i] + curr_nums[i + 1];
		valid &= ones % 2 == 1;
	}
	return valid;
}

vec<ll> calculate_valid_prevs(ll combi, ll max_combi, ll n) {
	vec<ll> valids;
	for (ll i = 0; i < max_combi; i++) {
		if (is_valid(combi, i, n)) valids.push_back(i);
	}
	return valids;
}

vec<vec<ll>> all_valid_prevs(ll max_combi, ll n) {
	vec<vec<ll>> valids(max_combi);
	for (ll combi = 0; combi < max_combi; combi++) {
		valids[combi] = calculate_valid_prevs(combi, max_combi, n);
	}
	return valids;
}

ll col_to_ll(vector<string>& rows, ll col) {
	ll res = 0;
	for (ll i = 0; i < rows.size(); i++) {
		res <<= 1;
		res += rows[i][col] - '0';
	}
	return res;
}

ll total_with_less_than_4_rows(vector<string>& rows) {
	ll n = rows.size();
	ll m = rows[0].size();
	ll max_combi = 1 << n;
	vector<vec<ll>> least_changes(m, vec<ll>(max_combi, LONG_LONG_MAX));

	vec<vec<ll>> valid_prevs = all_valid_prevs(max_combi, n);
	for (ll col = 0; col < m; col++) {
		ll actual_combi = col_to_ll(rows, col);

		for (ll combi = 0; combi < max_combi; combi++) {
			if (col > 0) {
				for (ll prev_combi : valid_prevs[combi]) {
					least_changes[col][combi] = min(
						least_changes[col][combi],
						least_changes[col - 1][prev_combi]
					);
				}
			} else {
				least_changes[col][combi] = 0;
			}
			least_changes[col][combi] += __builtin_popcount(combi ^ actual_combi);
		}
	}

	return *min_element(all(least_changes[m - 1]));
}


int main() {
	IOS;

	ll n, m;
	cin >> n >> m;
	vector<string> rows(n);
	forn (i) cin >> rows[i];
	if (n >= 4) {
		cout << -1 << endl;
	} else if (n == 1) {
		cout << 0 << endl;
	} else {
		cout << total_with_less_than_4_rows(rows) << endl;
	}



	return 0;
}
