#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define fore(i, s, n) for(ll i = s; i < n; i++)
#define forn(i) for(ll i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
#define vec vector

void print_item(vec<ll>& pos, ll last) {
    for (ll i = 0; i < last; i++) {
        cout << pos[i] << '.';
    }
    cout << pos[last] << endl;
}

void solve() {
    ll n;
    cin >> n;
    vec<ll> list(n);
    forn (i) cin >> list[i];

    vec<ll> pos;
    vec<string> result(n);
    for (ll i = 0; i < n; i++) {
        ll curr = list[i];
        if (curr == 1) {
            pos.push_back(curr);
            print_item(pos, pos.size() - 1);
        } else {
            ll j = pos.size() - 1;
            for (; pos[j] != curr-1; j--) {
                pos.pop_back();
            }
            pos[j]++;
            print_item(pos, j);
        }
    }

}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll t;
    cin >> t;
    fore (i,0,t) solve();    




}
