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

    ll q;
    cin >> q;

    fore (i, 0, q) {
        ll n, length;
        cin >> n >> length;

        string s ;
        cin >> s;

        string rgb = "RGB";

        vector<vector<ll>> changes(n, vector<ll>(3, 0));
        vector<vector<ll>> lengths(n, vector<ll>(3 ,0));

        ll min_changes = LONG_LONG_MAX;

        forn (j) {
            fore (letter, 0, 3) {
                if (j > 0) {
                    changes[j][letter] = changes[j - 1][(letter - 1 + 3) % 3];
                    lengths[j][letter] = lengths[j - 1][(letter - 1 + 3) % 3];
                }
                if (s[j] != rgb[letter]) {
                    changes[j][letter]++;
                }
                lengths[j][letter]++;

                if (lengths[j][letter] > length) {
                    if (s[j - length] != rgb[((letter - length) % 3 + 3) % 3]) {
                        changes[j][letter]--;
                    }
                    lengths[j][letter]--;
                }
                if (lengths[j][letter] == length) {
                    min_changes = min(changes[j][letter], min_changes);
                }
            }
        }

        cout << min_changes << endl;
    }


	return 0;
}
