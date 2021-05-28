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

	ll n;
	cin >> n;
	vec<vec<ll>> nums(n, vec<ll>(n, 0)); 
	forn (i) {
		forn (j) {
			cin >> nums[i][j];
		}
	}

	vec<ll> as(n, 1);
	ll gcd_total = 0;
	fore (i, 1, n) {
		gcd_total = __gcd(gcd_total, nums[0][i]);
	}

	fore (i, 1, n) {
		as[i] = nums[0][i] / gcd_total;
	}

	fore (i, 0, n) {
		fore (j, 0, n) {
			nums[i][j] /= as[i];
			nums[i][j] /= as[j];
		}
	}

	fore (i, 1, n) {
		as[i] *= sqrt(nums[1][2]);
	}

	as[0] = nums[0][1] / sqrt(nums[1][2]);

	fore (i, 0, n) {
		cout << as[i];
		if (i < n - 1) {
			cout << " ";
		}
	}
	cout << endl;



	return 0;
}
