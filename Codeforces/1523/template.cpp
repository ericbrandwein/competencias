#include <bits/stdc++.h>

using namespace std;

#define ll long long;
#define ld long double;
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

    if (i < n) {
        ll steps = m;
        for (ll j = i - 1; j >= 0 && steps > 0; j--) {
            nums[j] = '1';
            steps--;
        }
        ll prev = i;
        while (i < n) {
            for (; i < n && nums[i] != '1'; i++);
            if (i < n) {
                ll curr = i - 1;
                steps = m;
                prev++;
                for (; nums[prev + 1] != '1' && steps > 0 ; curr--, prev++) {
                    nums[curr] = '1';
                    nums[prev] = '1';
                    steps--;
                }
            }
        }
        for (; m >= 0 && prev < n; prev++) {
            nums[prev] = '1';
        }
    }

    cout << nums << endl;

}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll t;
    cin >> t;
    fore (i,0,t) solve();    




}
