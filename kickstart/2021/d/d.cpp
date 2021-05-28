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

struct Expression;

struct Expression {
	Expression* reduce() {
		if (this->operation != 'N') {
			left = left->reduce();
			right = right->reduce();
			if (this->operation == '*') {
				if (is_number(*left, 0) || is_number(*right, 0)) {
					this->operation = 'N';
					this->num = 0;
				} else if (is_number(*left, 1)) {
					this->copy(*right);
				} else if (is_number(*right, 1)) {
					this->copy(*left);
				}
			}
		}
		return this;
	}
};

struct BinaryExpression : Expression {
	Expression* left;
	Expression* right;

	Expression* reduce() {
		this->left->reduce();
		this->right->reduce();
		return this;
	}
};

struct Sum : BinaryExpression {
	Expression* reduce() {
		BinaryExpression::reduce();
		if ()
	}
};

struct Product : BinaryExpression {

};

struct Numeral : BinaryExpression {

};

struct Constant : Expression {
	string num
	bool is_constant() {
		return true;
	}

	int num() {

	}
	Expression* reduce() {
		return this;
	}
};


void solve() {
	ll n;
	cin >> n;
	vec<string> expressions(n);
	vec<Expression*> reduced(n);
	forn (i) {
		cin >> expressions[i];
	}



}


int main() {
	IOS;

	ll t;
	cin >> t;
	fore (i, 0, t) {
		cout << "Case #" << i+1 << ": ";
		solve();
		cout << endl;
	}

}
