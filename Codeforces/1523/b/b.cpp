#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define fore(i, s, n) for(ll i = s; i < n; i++)
#define forn(i) for(ll i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
#define vec vector

void solve() {
    ll n;
    cin >> n;
    vec<ll> nums(n);
    forn (i) cin >> nums[i];
    
    cout << 6*n / 2 << endl;
    for (ll i = 0; i < n; i+=2) {
        cout << 1 << " " << i+1 << " " << i + 2 << endl;
        cout << 2 << " " << i+1 << " " << i + 2 << endl;
        
        cout << 1 << " " << i+1 << " " << i + 2 << endl;
        cout << 2 << " " << i+1 << " " << i + 2 << endl;
        
        cout << 1 << " " << i+1 << " " << i + 2 << endl;
        cout << 2 << " " << i+1 << " " << i + 2 << endl;
        
    }
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll t;
    cin >> t;
    fore (i,0,t) solve();    




}
