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

const ll MOD = 1000003;

int main() {
	IOS;

	ll a, b;
	cin >> a >> b;
	ll n;
	cin >> n;
	vec<string> blacklist_mala(n);
	forn(i) cin >> blacklist_mala[i];
	vector<string> blacklist;
	forn (i) {
		bool minimal = true;
		forn (j) {
			if (i != j && blacklist_mala[i].find(blacklist_mala[j]) != string::npos) {
				minimal = false;
				break;
			}
		}
		if (minimal) blacklist.push_back(blacklist_mala[i]);
	}

	map<char, char> digits;
	digits['o'] = '0';
	digits['i'] = '1';
	digits['e'] = '3';
	digits['s'] = '5';
	digits['t'] = '7';


	ll letras = 'z' - 'a' + 1;
	ll posib = 2*letras + 10;

	vec<vec<ll>>

	// lowercase, uppercase, digit
	// * = todos
	vec<vec<map<string, ll>>> dp(b + 1);
	dp[0][1<<2][""] = letras;
	dp[0][1<<1][""] = letras;
	dp[0][1][""] = 10;
	for (string palabra: blacklist) {
		char ultimo = palabra.front();
		if (palabra.size() > 1) {
			// lowercase
			dp[0][1<<2]["" + ultimo]++;
			// UPPERCASE
			dp[0][1<<1]["" + toupper(ultimo)]++;
			// digits
			if (digits.count(ultimo) > 0) {
				dp[0][1]["" + digits[ultimo]]++;
			}
		} else {
			dp[0][1<<2][""]--;
			dp[0][1<<1][""]--;
			if (digits.count(ultimo) > 0) {
				dp[0][1][""]--;
			}
		}
	}

	for (ll i = 1; i < b; i++) {
		for (ll combi = 0; combi < 1<<3; combi++) {
			dp[i][combi | (1<<2)][""] += (letras * dp[i][combi][""]) % MOD;
			dp[i][combi | (1<<1)][""] += (letras * dp[i][combi][""]) % MOD;
			dp[i][combi | (1)][""] += (10 * dp[i][combi][""]) % MOD;
			for (string palabra: blacklist) {
				for (ll pos = 0; pos <= i && pos < palabra.size() - 1; pos++) {
					string substring = palabra.substr(0, pos + 1);
					string sig_substring = substring.substr(1);

					char ultimo = substring[pos];
					// lowercase
					dp[i][combi | (1<<2)][substring] += dp[i][combi][sig_substring];
					dp[i][combi | (1<<2)][substring] %= MOD;
					substring[pos] = toupper(ultimo);
					// UPPERCASE
					dp[i][combi | (1<<1)][substring] += dp[i][combi][sig_substring];
					dp[i][combi | (1<<1)][substring] %= MOD;

					// digits
					if (digits.count(ultimo) > 0) {
						substring[pos] = digits[ultimo];
						dp[i][combi | (1)][substring] += dp[i][combi][sig_substring];
						dp[i][combi | (1)][substring] %= MOD;
					}
				}

				if (palabra.size() < i) {
					dp[i][combi]
				}

			}
		}
	}

}
