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
#define MOD 1000000007

int main() {
	IOS;

    ll n, m;
    cin >> n>> m;

    vector<vector<ll>> combi(max(n, m), vector<ll>(4, 0));
    // 0 = 1 white
    // 1 = 1 black
    // 2 = 2 white
    // 3 = 2 black
    combi[0][0] = 1;
    combi[0][1] = 1;

    for (ll i = 1; i < max(n, m); i++) {
        combi[i][0] = (combi[i - 1][1] + combi[i - 1][3]) % MOD;
        combi[i][1] = (combi[i - 1][0] + combi[i - 1][2]) % MOD;  
        combi[i][2] = combi[i - 1][0];
        combi[i][3] = combi[i - 1][1];
    }

    ll total = 0;
    for (ll i = 0; i < 4; i++) {
        total += combi[m - 1][i];
        total %= MOD;
        total += combi[n - 1][i];
        total %= MOD;
    }
    total -= 2;
    total = (total + MOD) % MOD;

    cout << total << endl;

}
