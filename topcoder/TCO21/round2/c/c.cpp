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


class TheUltimatePackages {

public:
	vector<int> count(int N, int D, vector<int> Xprefix, vector<int> Yprefix, int L, int seed) {

		vector<int> X(D), Y(D);
		int XL = Xprefix.size();

		for (int i=0; i<XL; ++i) {
			X[i] = Xprefix[i];
			Y[i] = Yprefix[i];
		}

		long long state = seed;
		for (int i=XL; i<D; ++i) {
			state = (state * 1103515245 + 12345) % (1LL << 31);
			int elen = 1 + state%L;
			state = (state * 1103515245 + 12345) % (1LL << 31);
			Y[i] = state % (N - elen);
			X[i] = Y[i] + elen;
		}



	}
};