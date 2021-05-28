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

struct Fraction {
	ll num, den;


	Fraction operator*(const Fraction& other) const {
		Fraction res = {num * other.num, den * other.den};
		res.reduce();
		return res;
	}

	Fraction operator-(const Fraction& other) const {
		Fraction res = {num*other.den - other.num*den, den*other.den};
		res.reduce();
		return res;
	}

	Fraction operator+(const Fraction& other) const {
		Fraction res = {num*other.den + other.num*den, den*other.den};
		res.reduce();
		return res;
	}

	Fraction inverse() const {
		return {den, num};
	}

	Fraction operator/(const Fraction& other) const {
		return *this * other.inverse();
	}

	ld to_long_double() {
		return (ld)num/(ld)den;
	}

	void reduce() {
		if (den == 0) {
			num = 1;
		} else {
			ll g = __gcd(num, den);
			den /= g;
			num /= g;
		}
	}
};

int main() {
	IOS;

	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	Fraction first{a,b}, second{c,d}, one{1,1};

	Fraction f = one/((one-first)*(one-second));
	Fraction res = first * (one + (one/(f - one)));
	presicion(14);
	cout << res.to_long_double() << endl;

}
