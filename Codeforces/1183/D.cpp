#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

struct candy{
    ll tipo, apariciones;
};

bool comp(candy& a1, candy& a2){
    return a1.apariciones < a2.apariciones;
}

int main() {
	IOS;

    ll q; cin>>q;

    while(q--){

        ll n; cin>>n;
        map<ll, ll> nr_apariciones;
        forn(i){
            ll x; cin>>x;
            nr_apariciones[x]++;
        }

        vec<candy> candys;
        for(auto it: nr_apariciones){
            candys.push_back( {it.first, it.second} );
        }
        sort(all(candys), comp);

        ll ans = candys.back().apariciones;
        ll menor_usado = ans;

        for(ll i=candys.size()-2LL; i>=0LL; i--){

            if( menor_usado <= 1LL ) break;

            if( candys[i].apariciones >= menor_usado ){
                ans += max(0LL, menor_usado-1LL);
                menor_usado--;
            }else{
                ans += candys[i].apariciones;
                menor_usado = candys[i].apariciones;
            }

        }

        cout<<ans<<endl;

    }

	return 0;
}
