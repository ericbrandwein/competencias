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

struct Operation {
	ll left, right, sum;
};

int main() {
	IOS;

	ll n, m, k;
	cin >> n >> m >> k;

	vector<ll> orig(n);
	forn (i) {
		cin >> orig[i];
	}

	vector<Operation> operations(m);
	fore (i, 0, m) {
		cin >> operations[i].left >> operations[i].right >> operations[i].sum;
		operations[i].left--;
		operations[i].right--;
	}

	vector<ll> applications(m + 1);
	fore (i, 0, k) {
		ll from, to;
		cin >> from >> to;
		from--;
		to--;
		applications[from]++;
		applications[to + 1]--;
	}

	vector<ll> summed(n + 1);
	ll curr_applications = 0;
	fore (i, 0, m) {
		curr_applications += applications[i];
		ll from = operations[i].left;
		ll to = operations[i].right;
		ll sum = operations[i].sum;
		summed[from] += sum * curr_applications;
		summed[to + 1] -= sum * curr_applications;
	}

	ll curr_sum = 0;
	forn (i) {
		curr_sum += summed[i];
		cout << orig[i] + curr_sum << " ";
	}
	cout << endl;


	return 0;
}
