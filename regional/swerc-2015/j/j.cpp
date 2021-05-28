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

const double EPS = 1e-9;

using namespace std;
struct pt {  // for 3D add z coordinate
	double x,y;
	pt(double x, double y):x(x),y(y){}
	pt(){}
	double norm2(){return *this**this;}
	double norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(double t){return pt(x*t,y*t);}
	pt operator/(double t){return pt(x/t,y/t);}
	double operator*(pt p){return x*p.x+y*p.y;}
//	pt operator^(pt p){ // only for 3D
//		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
	double angle(pt p){ // redefine acos for values out of range
		return acos(*this*p/(norm()*p.norm()));}
	pt unit(){return *this/norm();}
	double operator%(pt p){return x*p.y-y*p.x;}
	// 2D from now on
	bool operator<(pt p)const{ // for convex hull
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>-EPS;}
	bool left_incl(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>EPS;}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(double a){return rot(pt(sin(a),cos(a)));}
};
pt ccw90(1,0);
pt cw90(-1,0);

int sgn2(double x){return x<0?-1:1;}
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool has(pt r){return dist(r)<=EPS;}
	bool seghas(pt r){return has(r)&&(r-p)*(r-(p+pq))<=EPS;}
//	bool operator /(ln l){return (pq.unit()^l.pq.unit()).norm()<=EPS;} // 3D
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;} // 2D
	bool operator==(ln l){return *this/l&&has(l.p);}
// 	pt operator^(ln l){ // intersection
// 		if(*this/l)return pt(DINF,DINF);
// 		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
// //		if(!has(r)){return pt(NAN,NAN,NAN);} // check only for 3D
// 		return r;
// 	}
	double angle(ln l){return pq.angle(l.pq);}
	int side(pt r){return has(r)?0:sgn2(pq%(r-p));} // 2D
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
	pt ref(pt r){return proj(r)*2-r;}
	double dist(pt r){return (r-proj(r)).norm();}
//	double dist(ln l){ // only 3D
//		if(*this/l)return dist(l.p);
//		return abs((l.p-p)*(pq^l.pq))/(pq^l.pq).norm();
//	}
	// ln rot(auto a){return ln(p,p+pq.rot(a));} // 2D
};
// ln bisector(ln l, ln m){ // angle bisector
// 	pt p=l^m;
// 	return ln(p,p+l.pq.unit()+m.pq.unit());
// }
// ln bisector(pt p, pt q){ // segment bisector (2D)
// 	return ln((p+q)*.5,p).rot(ccw90);
// }

int sgn(double x){return x<-EPS?-1:x>EPS;}
struct pol {
	int n;vector<pt> p;
	pol(){}
	pol(vector<pt> _p){p=_p;n=p.size();}
	double area(){
		double r=0.;
		fore(i,0,n)r+=p[i]%p[(i+1)%n];
		return abs(r)/2; // negative if CW, positive if CCW
	}
	pt centroid(){ // (barycenter)
		pt r(0,0);double t=0;
		fore(i,0,n){
			r=r+(p[i]+p[(i+1)%n])*(p[i]%p[(i+1)%n]);
			t+=p[i]%p[(i+1)%n];
		}
		return r/t/3;
	}
	bool has(pt q){ // O(n)
		fore(i,0,n)if(ln(p[i],p[(i+1)%n]).seghas(q))return true;
		int cnt=0;
		fore(i,0,n){
			int j=(i+1)%n;
			int k=sgn((q-p[j])%(p[i]-p[j]));
			int u=sgn(p[i].y-q.y),v=sgn(p[j].y-q.y);
			if(k>0&&u<0&&v>=0)cnt++;
			if(k<0&&v<0&&u>=0)cnt--;
		}
		return cnt!=0;
	}
	void normalize(){ // (call before haslog, remove collinear first)
		if(p[2].left_incl(p[0],p[1]))reverse(p.begin(),p.end());
		int pi=min_element(p.begin(),p.end())-p.begin();
		vector<pt> s(n);
		fore(i,0,n)s[i]=p[(pi+i)%n];
		p.swap(s);
	}
	bool haslog(pt q){ // O(log(n)) only CONVEX. Call normalize first
		if(q.left_incl(p[0],p[1])||q.left_incl(p.back(),p[0]))return false;
		int a=1,b=p.size()-1;  // returns true if point on boundary
		while(b-a>1){          // (change sign of EPS in left
			int c=(a+b)/2;       //  to return false in such case)
			if(!q.left_incl(p[0],p[c]))a=c;
			else b=c;
		}
		return !q.left_incl(p[a],p[a+1]);
	}
	pt farthest(pt v){ // O(log(n)) only CONVEX
		if(n<10){
			int k=0;
			fore(i,1,n)if(v*(p[i]-p[k])>EPS)k=i;
			return p[k];
		}
		if(n==p.size())p.push_back(p[0]);
		pt a=p[1]-p[0];
		int s=0,e=n,ua=v*a>EPS;
		if(!ua&&v*(p[n-1]-p[0])<=EPS)return p[0];
		while(1){
			int m=(s+e)/2;pt c=p[m+1]-p[m];
			int uc=v*c>EPS;
			if(!uc&&v*(p[m-1]-p[m])<=EPS)return p[m];
			if(ua&&(!uc||v*(p[s]-p[m])>EPS))e=m;
			else if(ua||uc||v*(p[s]-p[m])>=-EPS)s=m,a=c,ua=uc;
			else e=m;
			assert(e>s+1);
		}
	}
	// pol cut(ln l){   // cut CONVEX polygon by line l
	// 	vector<pt> q;  // returns part at left of l.pq
	// 	fore(i,0,n){
	// 		int d0=sgn(l.pq%(p[i]-l.p)),d1=sgn(l.pq%(p[(i+1)%n]-l.p));
	// 		if(d0>=0)q.push_back(p[i]);
	// 		ln m(p[i],p[(i+1)%n]);
	// 		if(d0*d1<0&&!(l/m))q.push_back(l^m);
	// 	}
	// 	return pol(q);
	// }
	double callipers(){ // square distance of most distant points
		double r=0;     // prereq: convex, ccw, NO COLLINEAR POINTS
		for(int i=0,j=n<2?0:1;i<j;++i){
			for(;;j=(j+1)%n){
				r=max(r,(p[i]-p[j]).norm2());
				if((p[(i+1)%n]-p[i])%(p[(j+1)%n]-p[j])<=EPS)break;
			}
		}
		return r;
	}
};

// CCW order
// Includes collinear points (change sign of EPS in left to exclude)
vector<pt> chull(vector<pt> p){
	if(p.size()<3)return p;
	vector<pt> r;
	sort(p.begin(),p.end()); // first x, then y
	fore(i,0,p.size()){ // lower hull
		while(r.size()>=2&&r.back().left(r[r.size()-2],p[i]))r.pop_back();
		r.push_back(p[i]);
	}
	r.pop_back();
	int k=r.size();
	for(int i=p.size()-1;i>=0;--i){ // upper hull
		while(r.size()>=k+2&&r.back().left(r[r.size()-2],p[i]))r.pop_back();
		r.push_back(p[i]);
	}
	r.pop_back();
	return r;
}


int main() {
	IOS;
	ll l;
	cin >> l;
	vec<pt> large(l);
	fore (i, 0, l) cin >> large[i].x >> large[i].y;

	ll s;
	cin >> s;
	vec<pt> small(s);
	fore (i, 0, s) cin >> small[i].x >> small[i].y;

	vec<pt> convex_hull = chull(large);
	pol polygon(convex_hull);
	polygon.normalize();
	ll total = 0;
	fore (i, 0, s) {
		if (polygon.haslog(small[i])) total++;
	}

	cout << total << endl;

}
