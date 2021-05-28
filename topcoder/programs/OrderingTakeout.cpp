#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define snd second
#define fst first


const ll MAXN = 105;

vector<pair<int,int> > g[MAXN]; // u->[(v,cost)]
ll dists[MAXN];
void dijkstra(int x){
	for (ll i = 0; i < MAXN; i++) {
		dists[i] = -1;
	}

	//memset(dists,-1,sizeof(dists));
	priority_queue<pair<ll,int> > q;
	dists[x]=0;q.push(make_pair(0,x));
	while(!q.empty()){
		x=q.top().snd;ll c=-q.top().fst;q.pop();
		if(dists[x]!=c)continue;
		for(ll i =0; i < g[x].size(); i++){
			int y=g[x][i].fst; ll c=g[x][i].snd;
			if(dists[y]<0||dists[x]+c<dists[y])
				dists[y]=dists[x]+c,q.push(make_pair(-dists[y],y));
		}
	}
}




class OrderingTakeout {
public:
	int bestSelection(vector <int> rating, vector <int> startNode, vector <int> endNode, vector <int> dist) {
		for (ll i = 0; i < startNode.size(); i++) {
			g[startNode[i]].push_back({endNode[i], dist[i]});
			g[endNode[i]].push_back({startNode[i], dist[i]});
		}
		dijkstra(0);
		
		ll min_distance = LONG_LONG_MAX;
		for (ll i = 0; i < rating.size(); i++) {
			if (rating[i] != 0) {
				min_distance = min(min_distance, (ll)dists[i]);
			}
		}
		
		ll chosen = 0;
		ll max_rating = 0;
		
		for (ll i = 0; i < rating.size(); i++) {
			cout << "dists " << i << "=" << dists[i] << endl;
			if (dists[i] != -1 && dists[i] <= 10 + min_distance && max_rating < rating[i]) {
				chosen = i;
				max_rating = max(max_rating, (ll)rating[i]);
			}	
		}
		
		return chosen;
		
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector <int> p2, vector <int> p3, bool hasAnswer, int p4) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p3.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p3[i];
	}
	cout << "}";
	cout << "]" << endl;
	OrderingTakeout *obj;
	int answer;
	obj = new OrderingTakeout();
	clock_t startTime = clock();
	answer = obj->bestSelection(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p4 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p4;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	vector <int> p0;
	vector <int> p1;
	vector <int> p2;
	vector <int> p3;
	int p4;
	
	{
	// ----- test 0 -----
	int t0[] = {0,1,2,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,0,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,2,3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {5,6,7};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 3;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {0,1,2,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,0,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,2,3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {5,6,7};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 3;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {0,1,2,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,0,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,2,3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {5,8,10};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 2;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {0,1,0,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,0,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,2,3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {5,6,10};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 1;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {0,1,2,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {5,5};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 1;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!