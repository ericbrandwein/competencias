#include <bits/stdc++.h>

using namespace std;

class  ShootingGame {
public:
    double findProbability(int p) {
		if (p > 500000 || p / (double) (1000000 - p) > 1) {
			return -1;
		}

		return p / (double) (1000000 - p);
	}

	
	{ 1 }
	
	500000
	0
	
	{1}
	{1, 1, 1, 2, 3}
	{1, 1, 1, 2, 2,  3}
};
