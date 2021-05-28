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

#define MOD 1000000007

using namespace std;

#define MAX 100010
ll dp[MAX][2];



int main() {
	IOS;
	string orig;
	cin >> orig;

	vector<ll> ns;
	vector<ll> us;
	ll curr = 0;
	char prev = 0;
	for (ll i = 0; i < orig.size(); i++) {
		if (orig[i] == 'm' || orig[i] == 'w') {
			cout << 0 << endl;
			return 0;
		}

		if (prev == orig[i]) curr++;
		else {
			if (prev == 'n') {
				ns.push_back(curr);
			} else if (prev == 'u') {
				us.push_back(curr);
			}
			curr = 1;
			prev = orig[i];
		}
	}

	if (prev == 'u') us.push_back(curr);
	if (prev == 'n') ns.push_back(curr);

	// 0 libre
	// 1 ocupado
	dp[1][0] = 1;
	for (ll i = 2; i < MAX; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
		dp[i][1] = dp[i - 1][0];
	}

	ll total = 1;
	for (auto& num : ns) {
		total *= dp[num + 1][0];
		total %= MOD;
	}
	for (auto& num : us) {
		total *= dp[num + 1][0];
		total %= MOD;
	}

	cout << total << endl;



	return 0;
}
