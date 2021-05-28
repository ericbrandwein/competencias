#pragma GCC optimize("Ofast")
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

#define N 100
int dp[N][N];

int solve_dp(int i, int j){
  int &ans = dp[i][j];
  if(ans!=-1)return ans;
  if((i==0)||(j==0)) return ans=1;
  return ans=(solve_dp(i-1,j)+solve_dp(i,j-1))%2;
}

int solve_cabeza(int n){
	for(ll i = 0; i < N; i++) for(ll j = 0; j < N; j++) dp[i][j] = -1;
  int ans = 0;
  for(int i=0;i<=n;i++){
    ans += solve_dp(n-i,i);
  }
  return ans;
}

vec<ll> hardcode = {1, 2, 2, 4, 2, 4, 4, 8};

ll multiplicador(ll n){
  vec<ll> pot2 = {2};
  while(pot2.size()!=60) pot2.push_back(pot2.back()*2);
  for(auto&it:pot2)it--;
  for(ll i=pot2.size()-1;i>=0;i--){
    if( n >= pot2[i] ) return pot2[i]+1;
  }
  return 1;
}

ll solve_posta(ll n){
  ll index = n%8;
  ll m = multiplicador(n/8);
  return hardcode[index] * m;
}

ll solve(ll n) {
	vec<ll> pot2 = {1, 2};
  	while(pot2.size()!=61) pot2.push_back(pot2.back()*2);
	for (ll i = pot2.size() - 1; i >= 0; i--) {
		if (n >= pot2[i]) {
			return 2*solve(n - pot2[i]);
		}
	}
	return 1;
}


int main(){IOS;
  ll n;cin>>n;
  cout << solve(n) << endl;
}