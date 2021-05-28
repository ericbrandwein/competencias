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

	string s;
	cin >> s;

	ll letters = 'z' - 'a' + 1;

	vec<vec<ll>> letter_pos(letters);
	vec<ll> winning_per_letter(letters, 0);
	for (ll i = 0; i < s.size(); i++) {
		ll letter = s[i]-'a';
		letter_pos[letter].push_back(i);
	}

	for (ll letter = 0; letter < letters; letter++) {
		for (ll i = 0; i < s.size(); i++) {
			map<ll,ll> amount_per_letter;
			for (ll pos : letter_pos[letter]) {
				ll curr_pos = (pos + i) % s.size();
				ll curr_letter = s[curr_pos] - 'a';
				amount_per_letter[curr_letter]++;
			}
			ll curr_winning = 0;
			for (auto& entry : amount_per_letter) {
				if (entry.second == 1) {
					curr_winning++;
				}
			}
			winning_per_letter[letter] = max(winning_per_letter[letter], curr_winning);
		}
	}

	ll total_sum = accumulate(all(winning_per_letter), 0);
	cout << (ld)total_sum / (ld)s.size() << endl;

}



