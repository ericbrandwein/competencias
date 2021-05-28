#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
	int weight;
	cin >> weight;

	int resto = weight % 2;
	if (resto == 0 && weight != 2) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}
