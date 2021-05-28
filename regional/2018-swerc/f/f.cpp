//#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/STACK: 20000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
//using ll = __int128;
using ld = long double;
//#define all(x) x.begin(), x.end()
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define EPSILON 0.0000001

struct pt {
    ll x, y, g;
    pt operator-(const pt& p) const {
        return pt{x - p.x, y - p.y, 0};
    }
	bool operator==(const pt& otro) const {
		return x == otro.x && y == otro.y;
	}
};

struct Cmp { // IMPORTANT: add const in pt operator -
    pt r;
    Cmp(pt r):r(r){}
    int cuad(const pt &a)const {
        if(a.x>0&&a.y>=0)return 0;
        if(a.x<=0&&a.y>0)return 1;
        if(a.x<0&&a.y<=0)return 2;
        if(a.x>=0&&a.y<0)return 3;
        assert(a.x==0&&a.y==0);
        return -1;
    }
    bool cmp(const pt& p1, const pt& p2)const {
        int c1=cuad(p1),c2=cuad(p2);
        if(c1==c2)return p1.y*p2.x<p1.x*p2.y;
        return c1<c2;
    }
    bool operator()(const pt& p1, const pt& p2)const {
        return cmp(p1-r,p2-r);
    }
};



ll operator %(pt o, pt p) { return o.x*p.y - o.y*p.x; }
// o is the origin, p is another point
// dir == +1 => p is clockwise from this
// dir ==  0 => p is colinear with this
// dir == -1 => p is counterclockwise from this
int a_derecha(pt from, pt to, pt other) {
	ll x = (to - from) % (other - from);
	return x > 0;
}

int main() {
    // IOS;
    ll N;
	cin >> N;
    vector<pt> data(N);
    ll suma_total = 0;
    for (ll i = 0; i < N; i++) {
        cin >> data[i].x >> data[i].y >> data[i].g;
        suma_total += data[i].g;
    }

	ll min_dif = LONG_LONG_MAX;

    for (ll k = 0; k < data.size(); k++) {
		pt& centro = data[k];
		vector<pt> ordenados;
		for (ll i = 0; i < data.size(); i++) {
			if (i != k) ordenados.push_back(data[i]);
		}
        sort(ordenados.begin(), ordenados.end(), Cmp(centro));
		ll ultimo = 0;
		ll suma_actual = 0;
		for (ll i = 0; i < ordenados.size(); i++) {
			pt& otro = ordenados[i];
			if (ultimo == i) {
				ultimo++;
				ultimo %= ordenados.size();
			} else {
				suma_actual -= otro.g;
			}
			while (a_derecha(centro, otro, ordenados[ultimo])) {
				suma_actual += ordenados[ultimo].g;
				ultimo++;
				ultimo %= ordenados.size();
			}
			ll izquierda = suma_total - suma_actual - centro.g - otro.g;
			min_dif = min(min_dif, abs(suma_actual - izquierda));
		}
    }

	cout << min_dif << endl;

    return 0;
}