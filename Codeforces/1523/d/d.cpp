#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define fore(i, s, n) for(ll i = s; i < n; i++)
#define forn(i) for(ll i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
#define vec vector

void find_max(vec<vec<bool>>& new_currencies, vec<bool>& friends, vec<bool>& current, ll& current_amount, vec<bool>& maxi, ll& max_amount, ll index, ll half) {
    if (index >= new_currencies.size()) {
        if (current_amount > max_amount) {
            maxi = current;
            max_amount = current_amount;
        }
        return;
    }
    vec<bool> new_friends = new_currencies[index];
    for (ll i = 0; i < friends.size(); i++) {
        new_friends[i] = new_friends[i] and friends[i];
    }
    ll sum = 0;
    
    for (ll i = 0; i < friends.size(); i++) {
        if (new_friends[i]) sum++;
    }
    if (sum >= half) {
        current[index] = true;
        current_amount++;
        find_max(new_currencies, new_friends, current, current_amount, maxi, max_amount, index+1, half);
        current[index] = false;
        current_amount--;
    }
    find_max(new_currencies, friends, current, current_amount, maxi, max_amount, index+1, half);
    
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n, m, p;
    cin >> n >> m >> p;
    vec<ll> amounts(m);
    vec<vec<bool>> currencies(m, vec<bool>(n, false));
    vec<string> likes(n);
    forn (j) {
        cin >> likes[j];
        for (ll i = 0; i < likes[j].size(); i++) {
            if (likes[j][i] == '1') {
                amounts[i]++;
                currencies[i][j] = true;
            }
        }
    }

    ll half = n / 2;
    if (n % 2 == 1) half++;

    vec<ll> curr_indices;
    vec<vec<bool>> new_currencies;
    for (ll i = 0;  i < amounts.size(); i++) {
        if (amounts[i] >= half) {
            new_currencies.push_back(currencies[i]);
            curr_indices.push_back(i);
        }
    }

    vec<bool> maxi(new_currencies.size(), false);
    vec<bool> friends(n, true);
    vec<bool> current(new_currencies.size(), false);
    ll max_amount= 0;
    ll current_amount = 0;
    find_max(new_currencies, friends, current, current_amount, maxi, max_amount, 0, half);
    string res(currencies.size(), '0');
    for (ll i = 0; i < maxi.size(); i++) {
        if (maxi[i]) {
            res[curr_indices[i]] = '1';
        }
    }
    cout << res << endl;




}
