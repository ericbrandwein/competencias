//#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/STACK: 20000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
//#define ll __int128
#define ld long double
#define vec vector
#define all(x) x.begin(), x.end()
#define deb(x) cerr<<#x<<" = "<<x<<endl
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int MIN,MAX;
map<vec<int>,int> Q;

int query(int A, int B, int C){
  assert((A!=B)&&(B!=C)&&(A!=C));
  vec<int> v = {A,B,C};
  sort(all(v));
  if(Q.count(v))return Q[v];
  cout<<"? "<<A<<" "<<B<<" "<<C<<endl; cout.flush();
  int response;cin>>response;
  Q[v] = response;
  return response;
}

pair<int,int> get_MAX_MIN(int N){
  assert(N>=5);
  assert((N%2)==1);
  vec<int> candidates;
  for(int i=1;i<=N;i++) candidates.push_back(i);
  int t=20;while(t--)random_shuffle(all(candidates));
  while(candidates.size()!=2){
    int n = candidates.size();
    int a = candidates[n-3], b = candidates[n-2], c = candidates[n-1];
    int response = query(a,b,c);
    if(response==a) swap(candidates[n-3],candidates.back());
    else if(response==b) swap(candidates[n-2],candidates.back());
    candidates.pop_back();
  }
  return {candidates[0],candidates[1]};
}


struct elem{
  int index;
  bool operator==(const elem &other)const{return index==other.index;}
  bool operator<(const elem &other)const{
    // is 'this' less than 'other' ?
    int response = query(MAX,other.index,index);
    if(other.index==response) return true; // this < other < MAX
    return false; // other < this < MAX
  }
};

int main(){IOS;
  int n;cin>>n;
  pair<int,int> max_min = get_MAX_MIN(n);
  MAX = max_min.first, MIN = max_min.second;
  vec<elem> elements;
  for(int i=1;i<=n;i++) if((i!=MAX)&&(i!=MIN)) elements.push_back({i});
  n-=2;
  nth_element(elements.begin(),elements.begin()+n/2,elements.end());
  cout<<"! "<<elements[n/2].index<<endl;
}