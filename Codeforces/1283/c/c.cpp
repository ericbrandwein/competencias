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

	ll n;
	cin >> n;

	vector<ll> friends(n);
	vector<bool> recibieron(n, false);
	forn (i) {
		cin >> friends[i];
		friends[i]--;
		if (friends[i] > -1) {
			recibieron[friends[i]] = true;
		}
	}

	vector<ll> no_recibieron;
	forn (i) {
		if (!recibieron[i]) {
			no_recibieron.push_back(i);
		}
	}

	vector<ll> ni_recibieron_ni_dieron;
	for (ll i = 0; i < no_recibieron.size(); i++) {
		if (friends[no_recibieron[i]] == -1) {
			ni_recibieron_ni_dieron.push_back(no_recibieron[i]);
		}
	}

	if (ni_recibieron_ni_dieron.size() == 1) {
		// Tengo que dárselo a cualquier otro que no haya recibido.
		ll actual = ni_recibieron_ni_dieron[0];
		forn (i) {
			if (actual != i && !recibieron[i]) {
				friends[actual] = i;
				recibieron[i] = true;
				break;
			}
		}
		ni_recibieron_ni_dieron.clear();
	}

	for (ll i = 0; i < ni_recibieron_ni_dieron.size(); i++) {
		friends[ni_recibieron_ni_dieron[i]] =
			ni_recibieron_ni_dieron[(i + 1) % ni_recibieron_ni_dieron.size()];
		recibieron[
			ni_recibieron_ni_dieron[(i + 1) % ni_recibieron_ni_dieron.size()]] = true;
	}

	no_recibieron.clear();
	vector<ll> no_dieron;
	forn (i) {
		if (!recibieron[i]) {
			no_recibieron.push_back(i);
		}
		if (friends[i] == -1) {
			no_dieron.push_back(i);
		}
	}

	for (ll i = 0; i < no_dieron.size(); i++) {
		friends[no_dieron[i]] = no_recibieron[i];
	}

	for (ll i = 0; i < n; i++) {
		cout << friends[i] + 1 << " ";
	}
	cout << endl;


	return 0;
}
