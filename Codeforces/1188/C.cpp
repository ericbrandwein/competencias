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
#define MOD 998244353

using namespace std;


vector<vector<ll>> counts(1001, vector<ll>(1001, 0));

ll subs_with_diff_at_least(vector<ll>& nums, ll diff, ll sub_length) {
    ll total = 0;
    counts[0][0] = 1;

    ll difference_index = 0;
    fore (i, 1, nums.size()) {
        fore (j, 0, sub_length) {
            counts[i][j] = counts[i - 1][j];
        }

        while (nums[i] - nums[difference_index] >= diff) {
            fore (j, 1, sub_length) {
                counts[i][j] += counts[difference_index][j - 1];
                counts[i][j] %= MOD;
            }

            difference_index++;
        }

        total += counts[i][sub_length - 1];
        total %= MOD;
    }

    return total;
}

int main() {
	IOS;

	ll n, length;

    cin >> n >> length;
    
    vector<ll> nums(n);
    forn (i) {
        cin >> nums[i];
    }

    sort(all(nums));

    ll max_dif = nums[n - 1] / (length - 1);

    ll total = 0;
    for (ll i = 1; i <= max_dif; i++) {
        total += subs_with_diff_at_least(nums, i, length);
        total %= MOD; 
    }

    cout << total << endl;

	return 0;
}
