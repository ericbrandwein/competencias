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

ll get_pairing(string& pars, ll closing, vector<ll>& sums) {
    ll searching_for = sums[closing] + 1;
    ll i = closing - 1;
    for (;; i--) {
        ll curr_i = (i + pars.size()) % pars.size();
        if (pars[curr_i] == '(' && sums[curr_i] == searching_for) {
            break;
        }
    }

    return (i + pars.size()) % pars.size();
}

ll pairs_between(ll from, ll to, vector<ll>& sums) {
    ll searching_for = sums[from];
    ll total = 0;
    for (ll i = from + 1; i % sums.size() != to; i++) {
        if (sums[i % sums.size()] == searching_for) {
            total++;
        }
    }
    return total;
}

int main() {
	IOS;

    ll n;
    cin >> n;
    string pars;
    cin >> pars;

    vector<ll> sums(n);
    ll curr_sum = 0;
    ll min_sum = 0;
    forn (i) {
        if (pars[i] == '(') {
            curr_sum++;
        } else {
            curr_sum--;
            min_sum = min(min_sum, curr_sum);
        }
        sums[i] = curr_sum;
    }

    if (sums[n - 1] != 0) {
        cout << 0 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }


    vector<vector<ll>> min_until(n);
    vector<vector<ll>> min_until_q(n);
    forn (i) {
        for (ll j = i; j < n; j++) {
            ll curr_min = LONG_LONG_MAX;
            ll q = 0;
            if (sums[i] < curr_min) {
                curr_min = sums[i];
                q = 1;
            } else if (sums[i] == curr_min) {
                q++;
            }
            min_until[i].push_back(curr_min);
            min_until_q[i].push_back(q);
        }
    }


    vector<ll> min_sums;
    forn (i) {
        if (sums[i] == min_sum) min_sums.push_back(i);
    }
    ll without_change = min_sums.size();

    vector<vector<ll>> changing_sum(n);
    forn (i) {
        for (ll j = 0; j < min_until[i].size(); j++) {
            ll num = without_change;
            if (min_until[i][j] <= min_sum + 2) {
                num = min_until_q[i][j];
            }
            if (min_until[i][j] == min_sum + 2) {
                num += without_change;
            }
            changing_sum[i].push_back(num);
        }
    }

    forn (i) {
        for (ll j = 0; j < changing_sum[i].size(); j++) {
            if (pars[i] == '(' && pars[i + j] == )
        }
    }




    // vector<ll> pairing;
    // for (ll i = 0; i < min_sums.size(); i++) {
    //     pairing.push_back(get_pairing(pars, min_sums[i], sums));
    // }

    // ll best = 0;
    // ll best_i = 0;
    // for (ll i = 0; i < min_sums.size(); i++) {
    //     ll pairs = pairs_between(pairing[i], min_sums[i], sums);
    //     if (pairs > best) {
    //         best = pairs;
    //         best_i = i;
    //     }
    // }

    // best += 1;
    // if (bests > min_sums.size() && bests > best) {
    //     cout << bests + 
    // }
    // if (best > min_sums.size()) {
    //     cout << best << endl;
    //     cout << min_sums[best_i] + 1 << " " << pairing[best_i] + 1 << endl;  
    // } else {
    //     cout << min_sums.size() << endl;
    //     cout << 1 << " " << 1 << endl;
    // }
}
