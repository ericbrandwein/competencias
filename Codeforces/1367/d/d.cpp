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

ll sum_to(ll from, vec<ll>& positions) {
	ll sum = 0;
	for (ll pos : positions) {
		sum += abs(pos - from);
	}
	return sum;
}

void solve() {
	string s;
	cin >> s;

	ll m;
	cin >> m;
	vector<ll> sums(m);
	fore (i,0 ,m) cin >> sums[i];

	vector<vec<ll>> positions;
	vector<bool> used(m, false);
	bool all_used = false;
	while (!all_used) {
		all_used = true;
		vector<ll> new_positions;
		for (ll i = 0; i < sums.size(); i++) {
			if (!used[i] && sums[i] == 0) {
				new_positions.push_back(i);
				used[i] = true;
			}
		}

		for (ll i = 0; i < sums.size(); i++) {
			if (!used[i]) {
				sums[i] -= sum_to(i, new_positions);
				all_used = false;
			}
		}
		positions.push_back(new_positions);
	}

	vec<char> chars_used;

	map<char, ll> ocurrences;
	for (ll i = 0; i < s.size(); i++) {
		ocurrences[s[i]]++;
	}

	auto it = ocurrences.end();
	it--;
	for (; chars_used.size() < positions.size();) {
		ll char_pos = chars_used.size();
		ll curr_char = it->first;
		ll curr_ocurr = it->second;
		if (curr_ocurr >= positions[char_pos].size()) {
			chars_used.push_back(curr_char);
		}
		if (it != ocurrences.begin()) it--;
	}

	string b;
	for (ll i = 0; i < m; i++) {
		b.push_back('0');
	}
	for (ll i = 0; i < positions.size(); i++) {
		char curr_char = chars_used[i];
		for (ll pos : positions[i]) {
			b[pos] = curr_char;
		}
	}

	cout << b << endl;


}


int main() {
	IOS;

	ll q;
	cin >> q;
	while (q--) solve();

	return 0;
}
