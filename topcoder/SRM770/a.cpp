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

class DeleteArrays {
public:
	vector<long long> doDelete(int a, int b, int c, long long x, long long y, long long z) {
		ll mina = LONG_LONG_MAX;
		vector<ll> A(a);
		A[0] = 33;
		A[1] = 42;
		for (ll i = 2; i < a; i++) {
 			A[i] = (5*A[i-1] + 7*A[i-2]) % 1000000007 + 1;
			mina = min(A[i], mina);
		}

		ll minb = LONG_LONG_MAX;
		vector<ll> B(b);
		B[0] = 13;
		fore (i, 1, b) {
			B[i] = (11*B[i-1]) % 1000000007 + 1;
			minb = min(B[i], minb);
		}

		vector<ll> C(c);
		C[0] = 7;
		C[1] = 2;
		fore(i, 2, c)
			C[i] = (5*C[i-1] + 7*C[i-2]) % 1000000007 + 1;

		sort(all(A));
		sort(all(B));
		sort(all(C));





	}
}
