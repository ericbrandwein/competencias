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

struct Card {
	ll top, bottom;

	bool operator<(const Card& other) const {
		return bottom < other.bottom || (bottom == other.bottom && top < other.top);
	}
};

int main() {
	IOS;

	ll n;
	cin >> n;
	vector<Card> cards(n);
	forn (i) {
		Card& new_card = cards[i];
		cin >> new_card.top >> new_card.bottom;
	}

	sort(cards.rbegin(), cards.rend());
	ll total = 0;
	ll counter = 1;
	auto it_card = cards.begin();
	while (counter > 0 && it_card != cards.end()) {
		counter--;
		counter+= it_card->bottom;
		total += it_card->top;
		it_card++;
	}

	cout << total << endl;

	return 0;
}
