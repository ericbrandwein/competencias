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

struct punto{
    int x, y;
};

ld lado(punto& a, punto& b){
    return sqrtl( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}

ld angulo(punto& a, punto& b, punto& c){
    ld A = lado(a, b);
    ld B = lado(b, c);
    ld C = lado(c, a);

    return acos( (C*C - A*A - B*B)/(2.0*A*B) );
}

bool iguales(vec<ld>& ang1, vec<ld>& ang2,
        vec<ld> &l1, vec<ld>& l2){
    int n = ang1.size();
    forn(i){
        if( abs(ang1[i]-ang2[i]) > 0.0000001 ) return false;
    }
    n = l1.size();            
    ld razon = l1[0]/l2[0];
    forn(i){
        if( abs(razon - (l1[i]/l2[i])) > 0.000001 ) return false;
    }
    return true;
}

int main() {
	IOS;

    int n; cin>>n;
    vec<punto> p1(n);
    forn(i) cin>>p1[i].x>>p1[i].y;
    vec<punto> p2(n);
    forn(i) cin>>p2[i].x>>p2[i].y;

    vec<ld> angulos_p1;
    vec<ld> lados_p1;
    forn(i){
        angulos_p1.push_back( angulo(p1[i], p1[(i+1)%n], p1[(i+2)%n]) );
        lados_p1.push_back( lado(p1[i], p1[(i+1)%n]) );
    }

    forn(i){
        vec<ld> angulos_p2;
        vec<ld> lados_p2;
        for(int actual=i; actual<n; actual++){
            angulos_p2.push_back( angulo(p2[actual], p2[(actual+1)%n], p2[(actual+2)%n]) );
            lados_p2.push_back( lado(p2[actual], p2[(actual+1)%n]) );
        }
        for(int actual=0; actual<i; actual++){
            angulos_p2.push_back( angulo(p2[actual], p2[(actual+1)%n], p2[(actual+2)%n]) );
            lados_p2.push_back( lado(p2[actual], p2[(actual+1)%n]) );
        }

        if( iguales(angulos_p1, angulos_p2, lados_p1, lados_p2) ){
            cout<<"MISMO"<<endl; return 0;
        }
    }

    reverse(all(p2));

    forn(i){
        vec<ld> angulos_p2;
        vec<ld> lados_p2;
        for(int actual=i; actual<n; actual++){
            angulos_p2.push_back( angulo(p2[actual], p2[(actual+1)%n], p2[(actual+2)%n]) );
            lados_p2.push_back( lado(p2[actual], p2[(actual+1)%n]) );
        }
        for(int actual=0; actual<i; actual++){
            angulos_p2.push_back( angulo(p2[actual], p2[(actual+1)%n], p2[(actual+2)%n]) );
            lados_p2.push_back( lado(p2[actual], p2[(actual+1)%n]) );
        }

        if( iguales(angulos_p1, angulos_p2, lados_p1, lados_p2) ){
            cout<<"MISMO"<<endl; return 0;
        }
    }

    cout<<"OTRO"<<endl;

	return 0;
}


/*

5
0 0
0 2
1 2
1 1
2 0
2 4
4 3
3 1
4 -2
0 0

*/
