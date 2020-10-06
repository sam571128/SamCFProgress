#include<stdio.h>
#include<math.h>

#include<set>
#include<iostream>

#define ll long long
#define Pair pair<int,int>
using namespace std;
const int INF32=0x3f3f3f3f;
const double EPS=1.0e-8;
const double PI=acos(-1.0);

struct Point{
	double x,y;
	Point(double _x=0,double _y=0){
		x=_x;y=_y;
	}
	friend Point operator + (const Point &a,const Point &b){
		return Point(a.x+b.x,a.y+b.y);
	}
	friend Point operator - (const Point &a,const Point &b){
		return Point (a.x-b.x,a.y-b.y);
	}
	friend double operator ^ (const Point &a,const Point &b){
		return a.x*b.y-a.y*b.x;
	}
	friend bool operator == (const Point &a,const Point &b){
		return fabs(a.x-b.x)<EPS&&fabs(a.y-b.y)<EPS;
	}
};
struct V{
	Point start,end;
	V(Point _start=Point(0,0),Point _end=Point(0,0)){
		start=_start;end=_end;
	}
};
Point Basic;
set<Point> Set;

double Distance(Point a,Point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool operator < (Point a,Point b){
	a=a-Basic;b=b-Basic;
	double Ang1=atan2(a.y,a.x),Ang2=atan2(b.y,b.x);
	double Len1=Distance(a,Point(0.0,0.0)),Len2=Distance(b,Point(0.0,0.0));
	if(fabs(Ang1-Ang2)<EPS) return Len1<Len2;
	return Ang1<Ang2;
}
set<Point>::iterator Pre(set<Point>::iterator it){
	if(it==Set.begin()) it=Set.end();
	return --it;
}
set<Point>::iterator Nxt(set<Point>::iterator it){
	++it;
	return it==Set.end()?Set.begin():it;
}
int Query(Point p){
	set<Point>::iterator it=Set.lower_bound(p);
	if(it==Set.end()) it=Set.begin();
	return ((p- *(Pre(it)))^(*(it)- *(Pre(it))))<EPS;
}
void Insert(Point p){
	if(Query(p)) return ;
	Set.insert(p);
	set<Point>::iterator it=Nxt(Set.find(p));
	while(Set.size()>3&&((p- *(Nxt(it)))^(*(it)- *(Nxt(it))))<EPS){
		Set.erase(it);it=Nxt(Set.find(p));
	}it=Pre(Set.find(p));
	while(Set.size()>3&&((p- *(it))^(*(it)- *(Pre(it))))>-EPS){
		Set.erase(it);it=Pre(Set.find(p));
	}
}
int main(){
	int q;scanf("%d",&q);
	Basic=Point(0,0);
	int oper;Point a,str[5];
	for(int i=1;i<=3;++i){
		scanf("%d%lf%lf",&oper,&str[i].x,&str[i].y);
		Basic=Basic+str[i];//Set.insert(str[i]);
	}Basic.x/=3.0;Basic.y/=3.0;q-=3;
	for(int i=1;i<=3;++i){
		Set.insert(str[i]);
	}
	while(q--){
		scanf("%d%lf%lf",&oper,&a.x,&a.y);
		if(oper==1){
			Insert(a);
		}
		else{
			if(Query(a)) printf("YES\n");
			else printf("NO\n");
		}
	}
}