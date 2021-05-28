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

	ll n, q;
	cin >> n >> q;
	vec<ll> p(n);
	set<ll> piles;
	forn (i) {
		cin >> p[i];
		piles.insert(p[i]);
	}

	sort(all(p));
	multiset<ll> segments;
	for (ll i = 1; i < n; i++) {
		segments.insert(p[i] - p[i-1]);
	}

	ll dist = p[n-1] - p[0];
	if (!segments.empty()) {
		auto it = --segments.end();
		dist -= *it;
	}
	cout << dist << endl;

	while (q--) {
		ll type, pos;
		cin >> type >> pos;

		if (type == 0) {
			auto it = piles.find(pos);
			ll added = 0;
			if (it != piles.begin()) {
				it--;
				ll segment = pos - *it;
				segments.erase(segments.find(segment));
				it++;
				added += segment;
			}
			it++;
			if (it != piles.end()) {
				ll segment = *it - pos;
				segments.erase(segments.find(segment));
				added += segment;
			}
			it--;
			if (it != piles.begin() && (++it) != piles.end()) {
				segments.insert(added);
			}
			piles.erase(piles.find(pos));
		} else {
			if (!piles.empty()) {
				auto it = piles.lower_bound(pos);

				if (it != piles.end()) {
					ll next = *it;
					ll segment = next - pos;
					segments.insert(segment);
				}
				if (it != piles.begin()) {
					it--;
					ll prev = *it;
					ll segment = pos - prev;
					segments.insert(segment);
					it++;
				}
				if (it != piles.begin() && it != piles.end()) {
					ll next = *it;
					ll prev = *(--it);
					ll segment = next - prev;
					segments.erase(segments.find(segment));
				}
			}
			piles.insert(pos);
		}

		ll dist = 0;
		if (!piles.empty()) {
			dist = (*(--piles.end())) - (*piles.begin());
			if (!segments.empty()) {
				dist -= *(--segments.end());
			}
		}
		cout << dist << endl;

	}


	return 0;
}
