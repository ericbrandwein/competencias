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

vec<int> z_function(string& s){
	int l=0,r=0,n=s.size();
	vector<int> z(s.size(),0); // z[i] = max k: s[0,k) == s[i,i+k)
	for(int i=1;i<n;i++){
		if(i<=r)z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
		if(i+z[i]-1>r)l=i,r=i+z[i]-1;
	}
	return z;
}

int main() {
	IOS;

	string text;
	getline(cin, text);
	string pattern;
	getline(cin, pattern);
	ll times;
	cin >> times;

	string concat = pattern + '\n' + text;

	vec<int> z = z_function(concat);
	vec<int> lengths;
	for (ll i = pattern.size(); i < concat.size(); i++) {
		lengths.push_back(z[i]);
	}
	sort(lengths.rbegin(), lengths.rend());
	string res;
	if (lengths[times - 1] > 0) {
		for (ll i = 0; i < lengths[times - 1]; i++) {
			res.push_back(pattern[i]);
		}
	} else {
		res = "IMPOSSIBLE";
	}

	cout << res << endl;



	return 0;
}
