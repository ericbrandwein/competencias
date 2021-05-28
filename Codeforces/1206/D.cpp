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
    
    ll n; cin>>n;
    vec<ll> v(n);
    forn(i) cin>>v[i];
    
    vec< vec<ll> > info(65);
    
    forn(i){
        ll index = 0LL;
        ll nr = v[i];
        while(nr!=0){
            if( (nr%2)==1 ) info[index].push_back( i );
            nr /= 2LL;
            index++;
        }
    }

    fore (i, 0, 65) {
        if (info[i].size() >= 3) {
            cout << 3 << endl;
            return 0;
        }
    }

    map<ll, set<ll> > g;
    for(int i=0; i<65; i++){
        if (info[i].size() == 2) {
            g[info[i][0]].insert(info[i][1]);
            g[info[i][1]].insert(info[i][0]);
        }
    }
    
    ll ans = -1LL;
    for(auto &it: g){
            ll nans = -1LL;
            ll node = it.first;
            map<ll, bool> visitados;
            visitados[node] = true;
            map<ll, ll> niveles;
            niveles[ node ] = 0LL;
            queue<ll> q; q.push(node);
            map<ll, ll> padre;
            padre[node]=-1LL;
            while(not q.empty()){
                    node = q.front(); q.pop();
                    for(auto vecino:  g[node]){
                        if( visitados[vecino] ){
                            if(padre[node]==vecino) continue;
                            if(nans==-1LL) nans=niveles[vecino]+niveles[node]+1LL;
                            else nans = min(niveles[vecino]+niveles[node]+1LL, nans);
                        }else{
                            visitados[vecino] = true;
                            niveles[ vecino ] = niveles[ node ]+1LL;
                            q.push( vecino );
                            padre[vecino]=node;
                        }
                    }
            }
            if(nans==-1LL)continue;
            if(ans==-1LL) ans=nans;
            else ans = min(nans, ans);
    }
    
    cout<<ans<<endl;
    
    return 0;
}
