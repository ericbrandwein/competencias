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

class  EllysTwinLetters {
public:

	int getMin(string s) {
        const ll INF = 1000000;
        ll letters = 'Z' - 'A' + 1;
        // [0] = needs
        // [1] = not needs
		vec<vec<vec<ll>>> dp(s.size(), vec<vec<ll>>(letters, vec<ll>(2, INF)));
        for (ll i = 0; i < letters; i++) {
            dp[0][i][0] = abs(s[0] - 'A' - i);
        }
        for (ll i = 1; i < s.size(); i++) {
            for (ll letter = 0; letter < letters; letter++) {
                ll dist = abs(s[i] - 'A' - letter);
                dp[i][letter][1] = dist + min(dp[i-1][letter][0], dp[i-1][letter][1]);
                for (ll prev = 0; prev < letters; prev++) {
                    if (prev != letter) {
                        dp[i][letter][0] = min(
                            dp[i][letter][0],
                            dist + dp[i-1][prev][1]
                        );
                    }
                }
            }
        }

        ll res = INF;
        for (ll i = 0; i < letters; i++) {
            res = min(res, dp[s.size() - 1][i][1]);
        }
        return res;

	}
};

