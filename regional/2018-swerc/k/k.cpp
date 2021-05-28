#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK: 20000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
//#define ll __int128
#define ld long double
#define vec vector
#define all(x) x.begin(), x.end()
#define deb(x) cerr<<#x<<" = "<<x<<endl
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
struct Hash {
  int P=1777771,MOD[2],PI[2];
  vector<int> h[2],pi[2];
  Hash(string& s){
    MOD[0]=999727999;MOD[1]=1070777777;
    PI[0]=325255434;PI[1]=10018302;
    fore(k,0,2)h[k].resize(s.size()+1),pi[k].resize(s.size()+1);
    fore(k,0,2){
      h[k][0]=0;pi[k][0]=1;
      ll p=1;
      fore(i,1,s.size()+1){
        h[k][i]=(h[k][i-1]+p*s[i-1])%MOD[k];
        pi[k][i]=(1LL*pi[k][i-1]*PI[k])%MOD[k];
        p=(p*P)%MOD[k];
      }
    }
  }
  ll get(int s, int e){
    ll h0=(h[0][e]-h[0][s]+MOD[0])%MOD[0];
    h0=(1LL*h0*pi[0][s])%MOD[0];
    ll h1=(h[1][e]-h[1][s]+MOD[1])%MOD[1];
    h1=(1LL*h1*pi[1][s])%MOD[1];
    return (h0<<32)|h1;
  }
};

pair<ll,ll> get_best_next(ll l, ll r, vec<vec<pair<ll,ll>>>& dp_salto, Hash &H, ll n){
  pair<ll,ll> &ans = dp_salto[l][r];
  if( ans.first!=-1 && ans.second!=-1 ) return ans;
  ll size = r-l+1;
  if( (r+size)>=n ) return ans = {l,r};
  ll hash1 = H.get(l,r+1), hash2 = H.get(r+1,r+size+1);
  if( hash1 != hash2 ) return ans = {l,r};
  return ans = get_best_next(r+1,r+size,dp_salto,H,n);
}

ll solve(ll from, ll to, string &s, Hash &H, vec<vec<ll>>& dp, vec<vec<pair<ll,ll>>>& dp_salto){
  if(from>to)return 0;
  ll &ans = dp[from][to];
  if(ans!=-1)return ans;
  if(from==to)return ans=1;
  ans = to-from+1;
  for(ll i=from;i<to;i++){
    // [from,i] - [i+1,to]
    ll nans = solve(from,i,s,H,dp,dp_salto) + solve(i+1,to,s,H,dp,dp_salto);
    ans = min(nans,ans);
    ll len_pre = i - from + 1;
    ll len = to-from + 1;
    if (len % len_pre == 0) {
      pair<ll,ll> lr = get_best_next(from,i,dp_salto,H,s.size());
      ll l = lr.first, r = lr.second;
      if (r >= to) {
        ans = min( solve(l,r,s,H,dp,dp_salto), ans );
      }
    }
  }
  return ans;
}

int main(){IOS;
  ll n;cin>>n;
  string s;cin>>s;
  Hash H(s);
  vec<vec<ll>> dp(n,vec<ll>(n,-1));
  vec<vec<pair<ll,ll>>> dp_salto(n,vec<pair<ll,ll>>(n,{-1,-1}));
  cout<<solve(0,n-1,s,H,dp,dp_salto)<<endl;
}