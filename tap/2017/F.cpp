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

ll st_query(const vec<int>& st, int l, int r, int idx, int i, int j) {
	if (l <= i && j < r)
		return st[idx];
	else if (r <= i + (j - i) / 2)
		return st_query(st, l, r, 2 * idx, i, i + (j - i) / 2);
	else if (i + (j - i) / 2 <= l)
		return st_query(st, l, r, idx * 2 + 1, i + (j - i) / 2, j);
	else
		return st_query(st, l, r, 2 * idx, i, i + (j - i) / 2)
			 + st_query(st, l, r, idx*2 + 1, i + (j - i) / 2, j);
}

ll st_query(const vec<int>& st, int l, int r) {
	return st_query(st, l, r, 0, 0, 100000);
}

ll st_set(vec<int>& st, int i, int v) {
	st[100000+i] = v;
	st[i] = st[i*2] + st[i*2+1];
	while (i) {
		i /= 2;
		st[i] = st[i*2] + st[i*2+1];
	}
}

int main() {
	IOS;
	ll n;
	vec<int> st(200000);
	vec<tuple<int, int, int>> shows;
	set<pair<int, int>> fines;

	cin >> n;
	shows.reserve(n);

	forn(j) {
		int q, i, f, v, k, a, b;
		tuple<int, int, int> show;
		cin >> q;
		switch (q) {
			case 1:
				cin >> i >> f >> v;
				shows.push_back({i, f, v});
				fines.insert({f, shows.size()-1});
				st_set(st, i, v);
			break;
			case 2:
				cin >> a >> b;
				k -= 1;
				show = shows[k];
				fines.erase({get<1>(show), k});
				st_set(st, k, 0);
			break;
			case 3:
				cin >> a >> b;
				ll fel = st_query(st, a, b);
				auto posible = fines.upper_bound({a, -100000});
				if (posible != fines.end() && get<0>(shows[posible->second]) < a)
					fel += get<2>(shows[posible->second]);
				cout << fel;
			break;
		}
	}

	
	return 0;
}
