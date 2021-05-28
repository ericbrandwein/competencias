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

	ll books_per_person, n;
	cin  >> n >> books_per_person;

	vector<ll> alice_books;
	vector<ll> bob_books;
	vector<ll> both_books;

	forn (i) {
		ll cost, alice, bob;
		cin >> cost >> alice >> bob;
		if (alice && bob) {
			both_books.push_back(cost);
		} else if (alice) {
			alice_books.push_back(cost);
		} else if (bob) {
			bob_books.push_back(cost);
		}
	}

	if (both_books.size() + min(bob_books.size(), alice_books.size()) < books_per_person) {
		cout << -1 << endl;
		return 0;
	}

	sort(alice_books.rbegin(), alice_books.rend());
	sort(bob_books.rbegin(), bob_books.rend());
	sort(both_books.rbegin(), both_books.rend());

	ll total = 0;
	while (books_per_person > 0) {
		ll separated_cost = LONG_LONG_MAX;
		if (!bob_books.empty() && !alice_books.empty()) {
			separated_cost = bob_books.back() + alice_books.back();
		}
		ll joint_cost = LONG_LONG_MAX;
		if (!both_books.empty()) {
			joint_cost = both_books.back();
		}

		if (joint_cost < separated_cost) {
			both_books.pop_back();
		} else {
			bob_books.pop_back();
			alice_books.pop_back();
		}

		total += min(joint_cost, separated_cost);
		books_per_person--;
	}


cout << total << endl;
	return 0;
}
