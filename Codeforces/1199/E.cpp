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
        ll vertices, edges;
        cin >> vertices >> edges;

        vector<bool> available(vertices * 3 + 1, true);

        ll edges_taken = 0;
        vector<ll> indices;
        fore (j, 0, edges) {
            ll from, to;
            cin >> from >> to;
            if (available[from] && available[to]) {
                edges_taken++;
                available[from] = false;
                available[to] = false;
                indices.push_back(j + 1);
            }
        }

        if (edges_taken >= vertices) {
            cout << "Matching" << endl;
            fore (k, 0, vertices) {
                if (k > 0) {
                    cout << " ";
                }
                cout << indices[k];
            }
            cout << endl;
        } else {
            cout << "IndSet" << endl;
            ll used = 0;
            for (ll k = 1; k < available.size() && used < vertices; k++) {
                if (available[k]) {
                    if (used > 0) {
                        cout << " ";
                    }
                    cout << k;
                    used++;
                }
            }
            cout << endl;
        }
    }
}
