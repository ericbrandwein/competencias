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
	ll q;
	cin >> q;

	vector<bool> read(q, false);

	vector<vector<ll>> applications(n);
	queue<ll> first;
	ll first_read = 0;
	ll notification = 0;
	ll unread = 0;
	fore (i, 0, q) {
		ll type;
		cin >> type;
		ll x;
		cin >> x;
		if (type == 1) {
			// application x generated
			x--;
			applications[x].push_back(notification);
			first.push(notification);
			notification++;
			unread++;
		} else if (type == 2) {
			x--;
			// read notifications of x
			for (ll noti : applications[x]) {
				if (!read[noti]) {
					read[noti] = true;
					unread--;
				}
			}
			applications[x].clear();
		} else {
			// read first x notif
			ll to_read = max(x - first_read, 0LL);
			first_read = max(first_read, x);
			while (to_read > 0) {
				ll next = first.front();
				first.pop();
				if (!read[next]) {
					read[next] = true;
					unread--;
				}
				to_read--;
			}
		}

		cout << unread << endl;
	}

	return 0;
}
