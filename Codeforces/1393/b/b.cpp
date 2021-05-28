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

bool can_form(multiset<ll>& cants) {
	auto max_it = cants.end();
	bool square = false;
	ll rectangles = 0;
	bool can = false;
	while (!can && max_it != cants.begin()) {
		max_it--;
		ll num = *max_it;
		if (num < 2) {
			break;
		}
		if (!square && num >= 4) {
			num -= 4;
			square = true;
		} else if (!square && num < 4) {
			return false;
		}

		while (num >= 2 && rectangles < 2) {
			rectangles++;
			num -= 2;
		}
		if (square && rectangles >= 2) {
			can = true;
		}
	}

	return can;
}


int main() {
	IOS;

	ll n;
	cin >> n;

	vector<ll> a(n);
	map<ll, ll> amounts;
	multiset<ll> cants;
	forn (i) {
		cin >> a[i];
		amounts[a[i]]++;
	}
	for (pair<ll, ll> amount : amounts) {
		cants.insert(amount.second);
	}

	ll q;
	cin >> q;
	while (q--) {
		char event;
		cin >> event;
		ll num;
		cin >> num;
		ll old = amounts[num];
		ll value;
		if (event == '-') {
			value = old - 1;
		} else {
			value = old + 1;
		}
		amounts[num] = value;
		auto it_found = cants.find(old);
		if (it_found != cants.end()) {
			cants.erase(it_found);
		}
		cants.insert(value);

		if (can_form(cants)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}
