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

    ll n, bytes;
    cin >> n >> bytes;
    
    map<ll, ll> values;
    forn (i) {
        ll num;
        cin >> num;
        values[num]++;
    }

    ll log2max_difs = 8*bytes / n;

    if (log2max_difs > log2(1000000)) {
        cout << 0 << endl;
        return 0;
    }

    ll max_difs = 1 << log2max_difs;
    ll curr_difs = values.size();
    auto it_principio = values.begin();
    ll min_sacados = 0;
    for (; curr_difs > max_difs; it_principio++) {
        curr_difs--;
        min_sacados += it_principio->second;
    }

    if (min_sacados > 0) {
        it_principio--;
        ll sacados_actual = min_sacados;
        auto it_final = values.end();
        for (;it_principio != values.begin(); it_principio--) {
            it_final--;
            sacados_actual -= it_principio->second;
            sacados_actual += it_final->second;
            min_sacados = min(sacados_actual, min_sacados);
        }
        if (min_sacados > 0) { 
            it_final--;
            sacados_actual -= it_principio->second;
            sacados_actual += it_final->second;
            min_sacados = min(sacados_actual, min_sacados);
        }
    }
    
    cout << min_sacados << endl;

}
