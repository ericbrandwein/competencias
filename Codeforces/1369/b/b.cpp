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
void solve() {
    long long n;
    string s;
    cin >> n;
 	cin >> s;

	ll first_one = 0;
	for (; first_one < n && s[first_one] != '1'; first_one++);
	ll last_zero = n - 1;
	for (; last_zero >= 0 && s[last_zero] != '0'; last_zero--);
	
    if (last_zero < first_one) {
        cout << s << endl;
    } else {
        fore (i, 0, first_one) {
            cout << '0';
        }
        cout << '0';
        fore (i, last_zero+1, n) cout << '1';
        cout << endl;
    }
}

int main() {
	IOS;
    ll t;
    cin >> t;
    while (t--) solve();
}