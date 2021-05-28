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

struct Point {
    ll x, y;

    void print() {
        cout << x << " " << y << endl;
    }
};

void solve(ll b, ll w) {
    Point first_b = {3, 2};
    Point first_w = {2, 2};
    Point curr_b = first_b;
    Point curr_w = first_w;
    if (b >= w) {
        bool black = false;
        curr_w = curr_b;
        curr_w.x++;
        for (ll i = 0; w > 0; i++) {
            black = !black;
            if (black) {
                curr_b.print();
                curr_b.x+=2;
                b--;
            } else {
                curr_w.print();
                curr_w.x+=2;
                w--;
            }
        }
        if (b > 0) {
            curr_b.print();
            b--;
        }

        curr_w.x-=2;

        while(b > 0) {
            curr_b = curr_w;
            curr_b.y--;
            curr_b.print();
            b--;
            if (b > 0) {
                curr_b.y+=2;
                curr_b.print();
                b--;
            }
            curr_w.x-=2;
        }
    } else {
        bool black = true;
        curr_b = curr_w;
        curr_b.x++;
        for (ll i = 0; b > 0; i++) {
            black = !black;
            if (black) {
                curr_b.print();
                curr_b.x+=2;
                b--;
            } else {
                curr_w.print();
                curr_w.x+=2;
                w--;
            }
        }
        if (w > 0) {
            curr_w.print();
            w--;
        }
        curr_b.x-=2;
        while(w > 0) {
            curr_w = curr_b;
            curr_w.y--;
            curr_w.print();
            w--;
            if (w > 0) {
                curr_w.y+=2;
                curr_w.print();
                w--;
            }
            curr_b.x-=2;
        }
    }
}

int main() {
	IOS;

    ll q;
    cin >> q;

    fore (i, 0, q) {
        ll b, w;
        cin >> b >> w;

        if (b * 3 + 1 >= w && w * 3 + 1 >= b) {
            cout << "YES" << endl;

            solve(b, w);


        } else {
            cout << "NO" << endl;
        }

    }


	return 0;
}
