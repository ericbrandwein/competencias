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

bool can_go(string& in, string& out, ll from, ll to) {
	return out[from] == 'Y' && in[to] == 'Y';
}

void solve(ll number) {
	ll n;
	cin >> n;
	string in, out;
	cin >> in >> out;


	vector<vector<bool>> possible(n, vector<bool>(n, false));
	forn (i) {
		possible[i][i] = true;
		for (ll right = i + 1; right < n; right++) {
			possible[i][right] =
				possible[i][right-1] && can_go(in, out, right-1, right);
		}
		for (ll left = i - 1; left >= 0; left--) {
			possible[i][left] =
				possible[i][left+1] && can_go(in, out, left+1, left);
		}
	}

	cout << "Case #" << number << ":" << endl;
	fore (i, 0, n) {
		fore (j, 0, n) {
			if (possible[i][j]) cout << 'Y';
			else cout << 'N';
		}
		cout << endl;
	}


}

int main() {
	IOS;

	ll t;
	cin >> t;
	fore (i, 1, t+1) {
		solve(i);
	}

	return 0;
}
