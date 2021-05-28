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

struct Robot {
    ll x;
    ll y;
    bool move_up;
    bool move_down;
    bool move_right;
    bool move_left;
};

int main() {
	IOS;

    ll q;
    cin >> q;

    fore (i, 0, q) {
        ll n;
        cin >> n;

        vector<Robot> robots(n);
        forn(j) {
            cin >> robots[j].x >> robots[j].y >> robots[j].move_left >>
                robots[j].move_up >> robots[j].move_right >> robots[j].move_down;
        }

        ll min_x = -100000, max_x = 100000, min_y = -100000, max_y = 100000;

        forn(j) {
            if (!robots[j].move_down) {
                min_y = max(robots[j].y, min_y);
            }
            if (!robots[j].move_up) {
                max_y = min(robots[j].y, max_y);
            }
            if (!robots[j].move_left) {
                min_x = max(robots[j].x, min_x);
            }
            if (!robots[j].move_right) {
                max_x = min(robots[j].x, max_x);
            }
        }


        if (min_y <= max_y && min_x <= max_x) {
            cout << 1 << " " << min_x << " " << min_y << endl;
        } else {
            cout << 0 << endl;
        }
    }
	return 0;
}
