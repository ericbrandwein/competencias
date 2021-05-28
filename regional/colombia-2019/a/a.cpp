//#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/STACK: 20000000")
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

ll gcd(ll a, ll b){return a?gcd(b%a, a):b;}

struct line {
  ll pendiente_num, pendiente_den;
  double ord_origen;
  bool operator==(const line &other) const{
    return pendiente_num==other.pendiente_num
      && pendiente_den==other.pendiente_den && abs(ord_origen-other.ord_origen)<DBL_EPSILON;
  }
  bool operator<(const line &other) const{
    if(pendiente_num!=other.pendiente_num)return pendiente_num<other.pendiente_num;
    if(pendiente_den!=other.pendiente_den)return pendiente_den<other.pendiente_den;
    return ord_origen < other.ord_origen;
  }
};

line make_line(pair<ll,ll> &A, pair<ll,ll> &B){
  assert(!(A.first==B.first&&A.second==B.second));
  ll num = B.second-A.second;
  ll den = B.first-A.first;
  if(den==0) return {-1,-1,-1};
  ll g = gcd(num, den);
  num /= g, den /= g;
  if(num<0) num*=-1, den*=-1;
  double ord = (double)A.second - ( (double)A.first * ( (double)num / (double)den ) );
  return {num,den,ord};
}

pair<ll,ll> other_pendiente(pair<ll,ll> m){
  ll num = m.first, den = m.second;
  if( num == -1 && den == -1 ) return {0,1};
  if( num == 0 ){
    assert( den == 1);
    return {-1,-1};
  }
  ll ans_num = -den;
  ll ans_den = num;
  if( ans_num<0 ) ans_num*=-1, ans_den*=-1;
  return {ans_num,ans_den};
}

void solve(){
  ll n;cin>>n;
  vec<line> lines;
  for(ll i=0;i<n;i++){
    pair<ll,ll> A,B;cin>>A.first>>A.second>>B.first>>B.second;
    lines.push_back(make_line(A,B));
  }
  random_shuffle(all(lines));
  sort(all(lines));

  // discard exact same lines
  assert(lines.size());
  vec<line> lines_posta = {lines[0]};
  for(int i=1;i<lines.size();i++){
    if( lines[i] == lines[i-1] ) continue;
    lines_posta.push_back(lines[i]);
  }

  map<pair<ll,ll>,ll> pendiente_ocur;
  for(auto&it:lines) pendiente_ocur[ {it.pendiente_num,it.pendiente_den} ]++;

  ll ans = 0;

  for(auto&it:pendiente_ocur){
    pair<ll,ll> other = other_pendiente(it.first);
    if(pendiente_ocur.count(other)==0)continue;
    ans += it.second *  pendiente_ocur[other];
  }
  cout<<ans/2<<endl;
}

int main(){IOS;
  ll t;cin>>t;
  while(t--)solve();
}