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

bool can_do_with_time(vec<ll>& drivers, vec<ll>& logs, ll time) {
	ll log = 0;
	for (ll i = 0; i < drivers.size() && log < logs.size(); i++) {
		ll driver_pos = drivers[i];
		ll time_used = 0;
		ll left = 0;
		ll right = 0;
		while (time_used <= time && log < logs.size()) {
			ll log_pos = logs[log];
			ll diff = abs(log_pos - driver_pos);
			if (log_pos < driver_pos) {
				left = max(left, diff);
			} else {
				right = max(right, diff);
			}

			time_used = left + right + min(left, right);
			if (time_used <= time) {
				log++;
			}
		}
	}

	return log == logs.size();
}


void solve() {
	ll n, m, k, s;
	cin >> n >> m >> k >> s;

	vec<ll> drivers(n);
	fore (i, 0, k) cin >> drivers[i];

	ll a,b ,c, d;
	cin >> a >> b>> c >> d;
	fore (i, k, n) {
		drivers[i] = ((a*drivers[i-2] + b*drivers[i-1] + c) % d) + 1;
	}

	vec<ll> logs(m);
	fore (i, 0, k) cin >> logs[i];

	cin >> a >> b>> c >> d;
	fore (i, k, m) {
		logs[i] = ((a*logs[i-2] + b*logs[i-1] + c) % d) + 1;
	}

	sort(all(drivers));
	sort(all(logs));

	ll from = 0;
	ll to = 2*500'000'000 + 1;
	while (from < to) {
		ll middle = (from + to) / 2;
		if (can_do_with_time(drivers, logs, middle)) {
			to = middle;
		} else {
			from = middle + 1;
		}
	}

	cout << from << endl;
}

int main() {
	IOS;

	ll t;
	cin >> t;
	fore (i, 0, t) {
		cout << "Case #" << i + 1 << ": ";
		solve();
	}

	return 0;
}
