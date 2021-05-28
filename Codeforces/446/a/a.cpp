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
	vector<ll> nums(n);
	forn (i) cin >> nums[i];

	vector<ll> non_increasing;
	fore (i, 1, n) {
		if (nums[i] <= nums[i - 1]) {
			non_increasing.push_back(i);
		}
	}

	if (non_increasing.empty()) {
		cout << n << endl;
		return 0;
	}

	// Si este puede subir
	vector<bool> can_go_up(non_increasing.size());
	fore (i, 0, non_increasing.size()) {
		ll elem_index = non_increasing[i];
		can_go_up[i] = elem_index == nums.size() - 1 ||
		 	nums[elem_index - 1] + 1 < nums[elem_index + 1];
	}

	// Si el anterior puede bajar
	vector<bool> can_go_down(non_increasing.size());
	fore (i, 0, non_increasing.size()) {
		ll elem_index = non_increasing[i];
		can_go_down[i] = elem_index == 1 || nums[elem_index] - 1 > nums[elem_index - 2];
	}

	ll max_length = 0;
	ll prev_non_increasing = 0;
	fore (i, 0, non_increasing.size()) {
		// Subiendo el actual
		max_length = max(
			max_length, non_increasing[i] - prev_non_increasing + 1
		);
		// Bajando o subiendo el anterior
		if (i > 0 && (can_go_up[i - 1] || can_go_down[i - 1])) {
			ll sub_start = 0;
			if (i - 1 > 0) {
				sub_start = non_increasing[i - 2];
			}
			max_length = max(
				max_length, non_increasing[i] - 1 - sub_start + 1
			);
		}
		// Si el anterior no puede ni subir ni bajar, entonces
		// lo mejor que podemos hacer terminando en el non_increasing[i] - 1
		// es empezando desde el non_increasing[i - 1], que nos da el mismo
		// length que subiendo el actual.
		prev_non_increasing = non_increasing[i];
	}

	// Bajando el anterior
	max_length = max(
		max_length, n - prev_non_increasing + 1
	);

	if (can_go_up[non_increasing.size() - 1] || can_go_down[non_increasing.size() - 1]) {
		if (non_increasing.size() > 1) {
			max_length = max(
				max_length, n - non_increasing[non_increasing.size() - 2]
			);
		} else {
			max_length = max(max_length, n);
		}
	}

	cout << max_length << endl;

	return 0;
}