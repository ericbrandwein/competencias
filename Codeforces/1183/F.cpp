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

int main() {
	IOS;

    ll q; cin>>q;

    while(q--){

        ll n; cin>>n;
        vec<ll> v(n);
        forn(i) cin>>v[i];
        sort(all(v));

        vec<ll> padre(n);
        padre[0LL]=-1LL;
        for(ll i=1LL; i<n; i++){
            if( (v[i]%v[i-1LL])==0LL ) padre[i]=padre[i-1LL];
            else padre[i] = i-1LL;
        }

        ll ans = v.back();
        for(ll i=n-1LL; i>=0LL; i--){
            ll quien =  i;
            ll nans = v[quien];
            
            ll veces = 0;
            while(true){
                if(veces==2) break;

                if(padre[quien]==-1) break;

                ll anterior = padre[quien];
                while( (v[quien]%v[anterior])==0 ){
                    anterior = padre[anterior];
                    if(anterior==-1) break;
                }
                
                nans += v[anterior];
                quien = anterior;
            }

            ans = max(nans, ans);
        }

        cout<<ans<<endl;

    }

	return 0;
}
