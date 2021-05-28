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



class ShoppingSpree {
public:
	int maxValue(int k, vector <int> shirtValue,
        vector <int> jeansValue, vector <int> shirtType, vector <int> jeansType) {


        vector<bool> usedShirts(shirtValue.size(), false);
        vector<bool> usedJeans(jeansValue.size(), false);

        ll total = 0;
        for (ll i = 0; i < k; i++) {
            ll best_deal = 0;
            ll sums = -1;

            for (ll j = 0; j < shirtType.size(); j++) {
                ll curr = 0;
                if (!usedShirts[shirtType[j]]) curr += shirtValue[shirtType[j]];
                if (!usedJeans[jeansType[j]]) curr += jeansValue[jeansType[j]];
                if (sums < curr) {
                    sums = curr;
                    best_deal = j;
                }
            }

            usedShirts[shirtType[best_deal]] = true;
            usedJeans[jeansType[best_deal]] = true;
            total += sums;
        }

        return total;
	}
}
