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

ll to_num(vec<ll>& digits, map<char,ll>& letters, const string& word) {
	ll res = 0;
	for (char c : word) {
		res *= 10;
		res += digits[letters[c]];
	}
	return res;
}

bool valid(vec<ll>& digits, map<char,ll>& letters, vec<string>& summed, string& res) {
	ll sum = 0;
	for (const string& word: summed) {
		sum += to_num(digits, letters, word);
		if (digits[letters[word[0]]] == 0) {
			return false;
		}
	}
	if (digits[letters[res[0]]] == 0) {
		return false;
	}

	return sum == to_num(digits, letters, res);
}

int main() {
	IOS;

	ll n;
	cin >> n;
	vec<string> summed(n - 1);
	map<char,ll> letters;
	string res;
	fore (i, 0, n - 1) {
		cin >> summed[i];
		for (char c : summed[i]) {
			if (letters.count(c) == 0) {
				ll pos = letters.size();
				letters[c] = pos;
			}
		}
	}
	cin >> res;
	for (char c : res) {
		if (letters.count(c) == 0) {
			ll pos = letters.size();
			letters[c] = pos;
		}
	}

	vec<ll> digits;
	for (ll i = 0; i < 10; i++) {
		digits.push_back(i);
	}

	ll tot = 0;
	do {
		if (valid(digits, letters, summed, res)) tot++;
	} while (next_permutation(all(digits)));

	ll additional = 1;
	for (ll i = 1; i <= 10 - letters.size(); i++) {
		additional *= i;
	}

	cout << tot / additional << endl;
}
