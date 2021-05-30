#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define fore(i, s, n) for(ll i = s; i < n; i++)
#define forn(i) for(ll i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

void solve() {
    ll n ,m;
    cin >> n >> m;

    string nums;
    cin >> nums;

    ll i =0;
    for (; i < n && nums[i] != '1'; i++);

    string res = nums;
    if (i < n) {
        ll steps = m;
        for (ll j = i - 1; j >= 0 && steps > 0; j--) {
            res[j] = '1';
            steps--;
        }
        ll prev = i;
        while (i < n) {
            prev = i;
            i++;
            for (; i < n && nums[i] != '1'; i++);
            if (i < n) {
                ll curr = i;
                steps = m;
                for (; res[prev + 1] != '1' && steps >= 0 ; curr--, prev++) {
                    res[curr] = '1';
                    res[prev] = '1';
                    steps--;
                }
            }
        }
        for (; m >= 0 && prev < n; prev++) {
            res[prev] = '1';
            m--;
        }
    }

    cout << res << endl;

}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll t;
    cin >> t;
    fore (i,0,t) solve();    




}
