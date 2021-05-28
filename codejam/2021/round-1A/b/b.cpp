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


ll best_sum(vec<ll>& primes, vec<ll>& amounts, vec<ll>& used, vec<ll>& curr_primes, ll prod, ll sum) {
	if (prod > sum) {
		return 0;
	} else if (prod == sum) {
		return sum;
	}
	ll best = 0;
	ll i = 0;
	if (!curr_primes.empty()) {
		i = curr_primes.back();
	}
	for (; i < primes.size(); i++) {
		ll curr_prod = prod * primes[i];
		ll curr_sum = sum - primes[i];
		if (curr_prod > curr_sum) {
			break;
		}
		if (amounts[i] > used[i]) {
			used[i]++;
			curr_primes.push_back(i);
			best = max(best, best_sum(primes, amounts, used, curr_primes, curr_prod, curr_sum));
			curr_primes.pop_back();
			used[i]--;
		}
	}
	return best;
}


void solve() {
	ll m;
	cin >> m;
	vec<ll> primes(m);
	vec<ll> amounts(m);
	ll sum = 0;
	fore (i, 0, m) {
		ll p, n;
		cin>> primes[i] >> amounts[i];
		sum += primes[i] * amounts[i];
	}

	ll prod = 1;
	vec<ll> used(m, 0);
	vec<ll> curr_primes;
	cout << best_sum(primes, amounts, used, curr_primes, prod, sum) << endl;
}

int main() {
	IOS;

	ll t;
	cin >> t;
	fore (i, 0, t) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}

}
