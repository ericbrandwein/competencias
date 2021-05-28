//#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/STACK: 20000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vec vector
#define all(x) x.begin(), x.end()
#define deb(x) cerr<<#x<<" = "<<x<<endl
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct item{ll c,time;};

#define INF 99999999999LL
ll solve(ll n, bool steal, ll time, vec<vec<vec<ll>>> &dp, vec<item>& v){
    if(n==-1){
        if(time>0) return -INF;
        else return 0;
    }
    ll time_index = max(time+2000, 0LL);
    ll &ans = dp[n][steal][time_index];
    if(ans!=-1) return ans;
    if(steal){
        ans = v[n].c +
                max( solve(n-1,true,time+1,dp,v),
                        solve(n-1,false,time+1,dp,v) );
    }else{
        ans = max( solve(n-1,true,time-v[n].time,dp,v),
                solve(n-1,false,time-v[n].time,dp,v) );
    }
    return ans;
}

int main(){IOS;
    ll n; cin>>n;
    vec<item> v(n);
    for(auto&it:v)cin>>it.time>>it.c;
    // haber decidido los últimos i elementos teniendo t tiempo restante
    vec<vec<ll>> dp(n+10,vec<ll>(5000,-1));
    dp[0][2000] = 0;

    for (ll i = 0; i < n; i++) {
        // Mejor costo de robar o no robar este elemento anterior dado que tenemos x tiempo
        for (ll tiempo = 0; tiempo <= 4000; tiempo++) {
            ll costo_actual = dp[i][tiempo];

            // no robar el elemento i
            ll tiempo_no_robar = min(4000LL, tiempo + v[i].time);
            dp[i + 1][tiempo_no_robar] = max(
                dp[i + 1][tiempo_no_robar],
                costo_actual
            );
            // robar elemento i
            if (costo_actual != -1 && tiempo > 0) {
                ll tiempo_robar = tiempo - 1;
                dp[i + 1][tiempo_robar] = max(
                    dp[i + 1][tiempo_robar],
                    costo_actual + v[i].c
                );
            }
        }
    }

    ll max_steal = 0;
    for (ll i = 2000; i <= 4000; i++) {
        max_steal = max(max_steal, dp[n][i]);
    }
    ll sum = 0; for(auto&it:v) sum+=it.c;
    cout<<sum-max_steal<<endl;
}



