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

    int n; cin>>n;

    vec<string> dr, dd, rr, rd;

    while(n--){
        string s; cin>>s;
        string ss;
        for(auto it: s){
            if(it=='D' || it=='R')
                ss.push_back(it);
        }
        if(ss.size()){
            if( ss[0]=='D' && ss.back()=='R' ) dr.push_back(ss);
            if( ss[0]=='R' && ss.back()=='D' ) rd.push_back(ss);
            if( ss[0]=='D' && ss.back()=='D' ) dd.push_back(ss);
            if( ss[0]=='R' && ss.back()=='R' ) rr.push_back(ss);
        }
    }

    string res = "";
    
    if( dd.size() ){
        res += dd.back();
        dd.pop_back();
    }

    while( rd.size() ){
        res += rd.back();
        rd.pop_back();
    }

    while( true ){

        if(!rr.size()) break;
        if(!dd.size()) break;

        res += rr.back();
        rr.pop_back();

        res+=dd.back();
        dd.pop_back();
    }

    while(rr.size()){
        res += rr.back();
        rr.pop_back();
    }

    while(dd.size()){
        res += dd.back();
        dd.pop_back();
    }

    while(dr.size()){
        res += dr.back();
        dr.pop_back();
    }

    ll ans = 0;
    for(ll i=0LL; i<(ll)res.size()-1LL; i++){

        if( res[i]=='D' && res[i+1]=='R' ) ans++;
    }

    cout<<ans<<endl;


	return 0;
}
