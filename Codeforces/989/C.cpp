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
#define deb(x) cerr<<#x<<" = "<<x<<endl
#define PI 3.14159265358979323
#define sen(ang) sin((ang)*PI/180)
//cout<<flush;

using namespace std;

char tablero[50][51];

int main() {
	IOS;
	int a, b, c, d;

	cin >> a >> b >> c >> d;

	a -= 1;
	b -= 1;

	for (int i = 0; i < 40; i++)
		for (int j = 0; j < 50; j++)
			tablero[i][j] = 'A';


	for (int i = 39; i < 50; i++)
		for (int j = 0; j < 50; j++)
			tablero[i][j] = 'B';
	
	/* Pongo los B que me faltan */
	for (int i = 1; i < 10; i+=2)
		for (int j = 1; j < 49 && b; j+=2, b--)
			tablero[i][j] = 'B';

	/* Pongo los C que me faltan */
	for (int i = 11; i < 20; i+=2)
		for (int j = 1; j < 49 && c; j+=2, c--)
			tablero[i][j] = 'C';

	/* Pongo los D que me faltan */
	for (int i = 21; i < 30; i+=2)
		for (int j = 1; j < 49 && d; j+=2, d--)
			tablero[i][j] = 'D';


	/* Pongo los A que me faltan */
	for (int i = 40; i < 49; i+=2)
		for (int j = 1; j < 49 && a; j+=2, a--)
			tablero[i][j] = 'A';

	cout << 50 << ' ' << 50 << endl;
	for (int i = 0; i < 50; i++)
		cout << tablero[i] << endl;

	cerr << endl << a << ' ' << b << ' ' << c << ' ' << d << endl;

	return 0;
}
