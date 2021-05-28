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

int main() {
	IOS;

    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> nums(n);
    forn (i) {
        cin >> nums[i];
    }

    vector<ll> max_cost(n, 0);

    ll maximum = 0;
    for (ll i = n - 1; i >= 0; i--) {
        ll current_cost = -k;
        for (ll j = i; j < n && j < i + m; j++) {
            current_cost += nums[j];
            max_cost[i] = max(current_cost, max_cost[i]);
        }
        if (i + m < n) {
            max_cost[i] = max(current_cost + max_cost[i + m], max_cost[i]);
        }

        maximum = max(max_cost[i], maximum);
    }


    cout << maximum << endl;

	return 0;
}
