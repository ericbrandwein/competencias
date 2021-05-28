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

const ll MAX_NUM = 10000000;

vector<ll> primes;


void criba() {
	vector<bool> possible(MAX_NUM + 1, true);

	for (ll i = 2; i * i <= MAX_NUM ; i++) {
		if (possible[i]) {
			primes.push_back(i);
			for (ll j = i * 2; j * j <= MAX_NUM; j+=i) {
				possible[j] = false;
			}
		}
	}
}

ll first_divisor(ll num) {
	for (ll i = 0; i < primes.size() && primes[i] * primes[i] <= num; i++) {
		if (num % primes[i] == 0) {
			return primes[i];
		}
	}

	return num;
}


int main() {
	IOS;

	ll n;
	cin >> n;
	vector<ll> nums(n);
	forn (i) {
		cin >> nums[i];
	}

	criba();

	vector<vector<ll>> divs(n, vector<ll>(2,-1));
	for (ll i = 0; i < n; i++) {
		ll num = nums[i];
		vector<ll>& curr_divs = divs[i];

		ll first = first_divisor(num);
		ll second = num;

		while (second % first == 0) {
			second /= first;
		}

		if (second != 1) {
			curr_divs[0] = first;
			curr_divs[1] = second;
		}
	}

	for (ll i =0; i < 2; i++) {
		for (vector<ll>& div : divs) {
			cout << div[i] << " ";
		}
		cout << endl;
	}


	return 0;
}
