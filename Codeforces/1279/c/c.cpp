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

ll solve() {
	ll n, sent_q;
	cin >> n >> sent_q;

	vector<ll> presents(n);
	vector<ll> positions(n);
	forn (i) {
		cin >> presents[i];
		presents[i]--;
		positions[presents[i]] = i;
	}

	vector<ll> sent(sent_q);
	fore (i, 0, sent_q) {
		cin >> sent[i];
		sent[i]--;
	}

	ll max_position = -1;
	ll seconds = 0;
	fore (i, 0, sent_q) {
		ll curr_position = positions[sent[i]];
		if (max_position < curr_position) {
			max_position = curr_position;
			// All the previous ones had a position lower than mine,
			// and they were all removed, so the seconds I add
			// are decreased by the number of gifts sent before this one.
			seconds += 2 * (curr_position - i);
		} else {
			// We removed a gift from a position further away,
			// so we could've rearranged this one to waste just one second.
		}
		seconds++;
	}

	return seconds;
}


int main() {
	IOS;

	ll t;
	cin >> t;
	while (t--) {
		cout << solve() << endl;
	}
	return 0;
}
