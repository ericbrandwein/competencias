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

    forn (i) {
        ll elem, cortes_q;
        cin >> elem >> cortes_q;
        vector<ll> elems(elem);
        for (ll j = 0; j < elem; j++) {
            cin >> elems[j];
        }


        ll odd_q = 0;
        vector<ll> cortes;
        fore (j, 0, elem) {
            if (elems[j] % 2 == 1) {
                if (cortes_q == 1) {
                    odd_q++;
                } else {
                    cortes.push_back(j + 1);
                    cortes_q--;
                }
            }
        }

        if (odd_q % 2 == 0 || cortes_q > 1) {
            cout << "NO" << endl;
        } else {
            cortes.push_back(elem);
            cout << "YES" << endl;
            fore (j, 0, cortes.size()) {
                if (j > 0) {
                    cout << " ";
                }
                cout << cortes[j];
            }
            cout << endl;
        }


    }
	return 0;
}
