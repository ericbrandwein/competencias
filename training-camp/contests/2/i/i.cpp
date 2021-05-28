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

struct Interval {
	ll from, length;
	ll destino;

	bool operator<(const Interval& other) const {
		return this->from < other.from;
	}

	// inclusive
	ll to() const {
		return from + length - 1;
	}
};


int main() {
	IOS;

	ll n, queries_q;
	cin >> n >> queries_q;
	vector<ll> a(2*n);
	fore (i, 0, 2*n) cin >> a[i];

	set<Interval> b_intervals;
	b_intervals.insert({0, n, n});

	fore (i, 0, queries_q) {
		ll type;
		cin >> type;
		if (type == 1) {
			// copying
			ll destino, length, from;
			cin >> destino >> from >> length;
			destino--;
			from--;
			Interval interval = {from, length, destino};
			auto before_this = b_intervals.upper_bound(interval);
			before_this--;
			vector<Interval> new_intervals;
			if (before_this->from < interval.from && before_this->to() >= interval.from) {
				Interval new_interval = *before_this;
				new_interval.length = interval.from - before_this->from;
				new_intervals.push_back(new_interval);
			}
			while (before_this != b_intervals.end() &&
				before_this->from <= interval.to() &&
				before_this->to() <= interval.to()
			) {
				auto new_it = before_this;
				new_it++;
				b_intervals.erase(before_this);
				before_this = new_it;
			}

			if (before_this != b_intervals.end() &&
				before_this->from <= interval.to()
			) {
				Interval new_interval = *before_this;
				ll previous_to = new_interval.to();
				new_interval.from = interval.to() + 1;
				ll new_length = previous_to - new_interval.from + 1;
				ll length_diff = new_interval.length - new_length;
				new_interval.destino += length_diff;
				new_interval.length = new_interval.length - length_diff;
				new_intervals.push_back(new_interval);
				b_intervals.erase(before_this);
			}

			for (Interval new_interval : new_intervals) {
				b_intervals.insert(new_interval);
			}
			b_intervals.insert(interval);
		} else {
			// querying

			ll pos;
			cin >> pos;
			pos--;

			auto it = b_intervals.upper_bound({pos, 0, 0}); // El primero >
			it--;
			ll indice_en_a = it->destino + pos - it->from;
			cout << a[indice_en_a] << endl;
		}
	}





	return 0;
}
