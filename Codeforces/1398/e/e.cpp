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

ll insert_next_biggest(set<ll>& all, set<ll>& biggest) {
	set<ll>::iterator it;
	if (biggest.empty()) {
		it = all.end();
	} else {
		it = all.find(*biggest.begin());
	}
	if (it != all.begin()) {
		it--;
		biggest.insert(*it);
		return *it;
	}
	return 0;
}

int main() {
	IOS;

	ll n;
	cin >> n;
	set<ll> biggest;
	ll sum_biggest = 0;
	set<ll> all;
	set<ll> lights, fires;
	ll sum_all = 0;
	forn (i) {
		ll type;
		cin >> type;
		ll power;
		cin >> power;
		sum_all += power;
		if (power > 0) {
			if (type == 1) {
				lights.insert(power);
				sum_biggest += insert_next_biggest(all, biggest);
			} else {
				fires.insert(power);
			}
			all.insert(power);
			biggest.insert(power);
			sum_biggest += power;
		} else {
			power = -power;
			if (type == 1) {
				lights.erase(power);
			} else {
				fires.erase(power);
			}
			if (biggest.count(power) > 0) {
				sum_biggest -= power;
				biggest.erase(power);
			}
			all.erase(power);
		}

		if (biggest.size() < lights.size()) {
			sum_biggest += insert_next_biggest(all, biggest);
		}

		if (biggest.size() > lights.size()) {
			ll erased = *biggest.begin();
			biggest.erase(erased);
			sum_biggest -= erased;
		}


		if (lights.size() > 0) {
			ll total = sum_all;
			total += sum_biggest;
			ll min_light = *lights.begin();
			if (biggest.count(min_light) > 0) {
				total -= min_light;
				auto it = all.find(min_light);
				if (it != all.begin()) {
					it--;
					total += *it;
				}
			}
			cout << total << endl;
		} else {
			cout << sum_all << endl;
		}


	}

	return 0;
}
