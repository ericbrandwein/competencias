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

	ll n;
	cin >> n;
	vector<vector<ll>> weights(n, vector<ll>(n));
	forn (i) {
		forn (j) {
			cin >> weights[i][j];
		}
	}


	vector<ll> deleted(n);
	forn (i) {
		cin >> deleted[i];
		deleted[i]--;
	}

	vector<ll> sums;
	for (ll addedi = (ll)deleted.size() - 1; addedi >= 0; addedi--) {
		ll added = deleted[addedi];
        forn (from) {
            forn (to) {
                weights[from][to] = min(
                    weights[from][to],
                    weights[from][added] + weights[added][to]
                );
            }
        }

		ll sum = 0;
        for (ll fromi = (ll)deleted.size() - 1; fromi >= addedi; fromi--) {
            ll from = deleted[fromi];
            for (ll toi = (ll)deleted.size() - 1; toi >= addedi; toi--) {
                ll to = deleted[toi];
				sum += weights[from][to];
            }
        }

		sums.push_back(sum);
	}

	for (ll i = (ll)sums.size() - 1; i >= 0; i--) {
		cout << sums[i] << " ";
	}
	cout << endl;


	return 0;
}
