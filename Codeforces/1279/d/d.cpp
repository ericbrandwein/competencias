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

// m must be positive
template<typename T>
static T mod(T a, T m)
{
    a %= m;
    if (a < 0)
        a += m;
    return a;
}

// a must be relatively prime to m
template<typename T>
static T inverse(T a, T m)
{
    a = mod(a, m);
    if (a <= 1)
        return a;
    return mod((1 - inverse(m%a, a) * m)) / a, m);
}


int main() {
	IOS;

	ll n;
	cin >> n;

	vector<vector<ll>> presents_per_kid(n);
	vector<ll> kids_with_present(1000000, 0);
	forn (i) {
		ll k;
		cin >> k;
		for (ll j = 0; j < k; j++) {
			ll present;
			cin >> present;
			present--;
			presents_per_kid[i].push_back(present);
			kids_with_present[present]++;
		}
	}


	return 0;
}
