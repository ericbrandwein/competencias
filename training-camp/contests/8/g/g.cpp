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

struct Segment {
	ll from, to;

	bool operator<(const Segment& other) const {
		return to < other.to;
	}
};

bool lower_start(const Segment& first, const Segment& second) {
	return first.from < second.from;
}


int main() {
	IOS;

	ll n;
	cin >> n;
	vector<Segment> segments(n);
	forn (i) {
		cin >> segments[i].from >> segments[i].to;
		if (segments[i].from > segments[i].to) swap(segments[i].from, segments[i].to);
	}

	vector<ll> nails;

	sort(all(segments), lower_start);

	set<Segment> open_segments;
	for (ll i = 0; i < segments.size(); i++) {
		if (open_segments.empty() || open_segments.begin()->to >= segments[i].from) {
			open_segments.insert(segments[i]);
		} else {
			ll new_nail = open_segments.begin()->to;
			nails.push_back(new_nail);
			open_segments.clear();
			open_segments.insert(segments[i]);
		}
	}

	if (!open_segments.empty()) {
		auto it = open_segments.begin();
		nails.push_back(it->to);
	}

	cout << nails.size() << endl;
	for (ll nail:nails) {
		cout << nail << " ";
	}
	cout << endl;


	return 0;
}
