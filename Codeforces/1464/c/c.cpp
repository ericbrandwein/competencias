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

vec<ll> to_bits(ll t) {
	vec<ll> res;
	while (t > 0) {
		res.push_back(t % 2);
		t /= 2;
	}
	return res;
}

int main() {
	IOS;

	ll n, t;
	cin >> n >> t;
	string s;
	cin >> s;

	vec<ll> bits = to_bits(t);
	vec<ll> nums(s.size());
	for (ll i = 0; i < s.size(); i++) {
		nums[i] = s[i] - 'a';
	}
	t += 1<<s[s.size() - 1];
	t -= 1<<s[s.size() - 2];
	vec<ll> amount(26, 0);
	for (ll i = 0; i < nums.size() - 2; i++) {
		amount[nums[i]]++;
	}

	while (bits.size() < 26) bits.push_back(0);
	for (ll i = 25; i >= 0; i--) {
		ll restado = min(amount[i], bits[i]);
		bits[i] -= restado;
		amount[i] -= restado;
		ll sumar_anterior = 0;
		if (bits[i] == 0) {
			if (amount[i] % 2 == 1) {
				sumar_anterior += 2;
			}
		} else {
			sumar_anterior = bits[i] * 2;
		}
		if (sumar_anterior > 0 && i == 0) {
			cout << "No" << endl;
			return 0;
		} else if (i > 0) {
			bits[i-1] += sumar_anterior;
		}
	}

	cout << "Yes" << endl;

}
