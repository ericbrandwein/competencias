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

class RandomSelection {
public:
    double expectedMaximum(int n, int T, int seed, int Amod, vector <int> Aprefix) {
        vector<double> A(n);
        fore (i, 0, Aprefix.size())
            A[i] = Aprefix[i];
        ll state = seed;
        fore(i, Aprefix.size(), n) {
            state = (1103515245 * state + 12345) % (1 << 31);
            A[i] = T + (state % Amod);
        }

        std::default_random_engine generator;
        ll mean = 0;
        for (ll i = 0; i < 1000; i++) {
            double maxi = 0;
            for (ll j = 0; j < A.size(); j++) {
                std::uniform_real_distribution<double> distribution(0.0,A[j]);
                maxi = max(distribution(generator), maxi);
            }
            mean += maxi;
        }

        return mean / 1000.0;
    }
};
