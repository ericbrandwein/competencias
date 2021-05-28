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

ll increment(vector<char>& nums) {
	ll i;
	for (i = nums.size() - 1; i >= 0 && nums[i] == '9'; i--);
	if (i >= 0) {
		nums[i] += 1;
		i++;
		for (; i < nums.size(); i++) {
			nums[i] = '0';
		}
		return 0;
	} else {
		nums = vector<char>(nums.size(), '0');
		nums[0] = '1';
		return 1;
	}
}

int main() {
	IOS;

	ll n, salto;
	cin >> n >> salto;
	string a;
	cin >> a;

	vector<char> nums(salto);

	for (ll i = 0; i < salto; i++) {
		nums[i] = a[i];
	}

	bool incremented = false;
	bool restart = false;
	for (ll i = salto; i < n; i++) {
		char current = nums[i % salto];
		if (a[i] < current) {
			incremented = true;
		}
		if (!incremented && a[i] > current) {
			n += increment(nums);
			restart = true;
			break;
		}
		a[i] = current;
	}

	if (restart) {
		a = "";
		for (ll i = 0; i < n; i++) {
			char current = nums[i % salto];
			a.push_back(current);
		}
	}

	cout << a.size() << endl;
	cout << a << endl;


	return 0;
}
