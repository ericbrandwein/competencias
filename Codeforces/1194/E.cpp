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

struct Segment {
    int x1, y1, x2, y2;

    bool operator<(Segment& otro) {
        return x1 < otro.x1;
    }
};

bool interseca(Segment& horizontal, Segment& vertical) {
    return vertical.x1 <= horizontal.x2 && vertical.x1 >= horizontal.x2 &&
        horizontal.y1 <= vertical.y2 && horizontal.y2 >= vertical.y1;
}

int main() {
	IOS;

    int n;
    cin >> n;
    
    vector<Segment> verticales;
    vector<Segment> horizontales;

    forn (i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 > y2) {
            int medio = y1;
            y1 = y2;
            y2 = medio;
        }
        if (x1 > x2) {
            int medio = x1;
            x1 = x2;
            x2 = medio;
        }
        if (x1 == x2) {
            verticales.push_back({x1, y1, x2, y2});
        } else {
            horizontales.push_back({x1, y1, x2, y2});
        }
    }

    vector<vector<ll>> intersecciones_horizontales;

    for (int i = 0; i < horizontales.size(); i++) {
        vector<ll> intersecciones;
        for (int j = 0; j < verticales.size(); j++) {
            if (interseca(horizontales[i], verticales[j])) {
                intersecciones.push_back(j);
            }
        }
        intersecciones_horizontales.push_back(intersecciones);
    }



}
