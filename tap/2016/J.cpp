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

	int N, n; cin>>N>>n;
	vec<int> v(n); forn(i)cin>>v[i]; 

	if(n==2){
		if( (v[0]==1 && v[1]==2) || (v[0]==2 && v[1]==1) ){
			cout<<"N"<<endl;
			return 0;
		}
	}

	int max_element = v[0];
	int max_element_index = 0;
	forn(i){
		if( v[i] > max_element ){
			max_element = v[i];
			max_element_index = i;
		}
	}  

	if( max_element_index<n-1 && max_element_index>0 ){
		if( v[max_element_index-1] == v[max_element_index+1] ){
			cout<<"N"<<endl;
			return 0;
		}
	}

	for(int i=1; i<n-1; i++){
		if( v[i]==2 ){
			cout<<"N"<<endl;
			return 0;
		}
	}

	for(int i=max_element_index; i<n-1; i++){
		if( v[i] == (v[i+1]+1) ) continue;
		if( v[i] ==  (v[i+1]+2) ) continue;
		cout<<"N"<<endl; return 0;
	}

	for(int i=max_element_index; i>=1; i--){
		if( v[i] == (v[i-1]+1) ) continue;
		if( v[i] == (v[i-1]+2) ) continue;
		cout<<"N"<<endl; return 0;
	}

	cout<<"S"<<endl;


	return 0;
}
