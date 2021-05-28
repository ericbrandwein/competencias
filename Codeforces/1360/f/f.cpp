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

bool check_diff(string& checked, vector<string>& words) {
	for (string& current : words) {
		ll diff = 0;
		for (ll i = 0; i < checked.size(); i++) {
			if (current[i] != checked[i]) {
				diff++;
			}
		}
		if (diff > 1) {
			return false;
		}
	}
	return true;
}


string solve(vector<string>& words) {
	string possible_word = words[0];
	if (check_diff(possible_word, words)) {
		return possible_word;
	}

	for (ll curr_changed = 0; curr_changed < words[0].size(); curr_changed++) {
		possible_word = words[0];
		for (char curr_char = 'a'; curr_char <= 'z'; curr_char++) {
			possible_word[curr_changed] = curr_char;
			if (check_diff(possible_word, words)) {
				return possible_word;
			}
		}
	}

	return "-1";
}


int main() {
	IOS;

	ll t;
	cin >> t;
	for (ll i = 0; i < t; i++) {
		ll n, m;
		cin >> n >> m;
		vector<string> words(n);
		forn (j) {
			cin >> words[j];
		}
		cout << solve(words) << endl;


	}

	return 0;
}
