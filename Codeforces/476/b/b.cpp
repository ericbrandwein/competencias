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

	string orig, recv;
	cin >> orig >> recv;

	int plus_orig = 0;
	int minus_orig = 0;
	int plus_recv = 0;
	int question_recv = 0;
	int minus_recv = 0;
	for (char& car : orig) {
		if (car == '+') plus_orig++;
		else minus_orig++;
	}
	for (char& car : recv) {
		if (car == '+') plus_recv++;
		else if (car == '?') question_recv++;
		else minus_recv++;
	}

	int plus_missing = plus_orig - plus_recv;
	presicion(10);
	if (plus_missing >= 0 && question_recv >= plus_missing) {
		// Porba de agarrar plus_missing de question_recv
		// question_recv! / plus_missing! * (question_recv - plus_missing)!
		ll num = 1;
		for (ll i = question_recv; i > plus_missing; i--) {
			num *= i;
		}
		for (ll i = 2; i <= question_recv - plus_missing; i++) {
			num /= i;
		}
		double total = pow(2, question_recv);
		cout << (double)num / total << endl;
	} else {
		cout << 0 << endl;
	}



	return 0;
}
