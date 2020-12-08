#include <bits/stdc++.h>

#define double long double
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct point{
	double x,y;
	point(){}
	point(double x, double y):x(x),y(y){}
};

double a,b,c;

double mdis(point a, point b){
	return abs(a.x-b.x)+abs(a.y-b.y);
}

double dis(point a, point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
//ax+by+c=0 -> x = (-c-by)/a, y = (-c-ax)/b;
double findY(double x){
	return (double)(-c-a*x)/b;
}

double findX(double y){
	return (double)(-c-b*y)/a;
}

signed main(){
	fastio
	cin >> a >> b >> c;
	int x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	point p1(x1,y1), p2(x2,y2);
	double ans = 1e18;
	point f[2], s[2];
	f[0] = point(x1,findY(x1)), f[1] = point(findX(y1),y1);
	s[0] = point(x2,findY(x2)), s[1] = point(findX(y2),y2);
	for(int i = 0;i < 2;i++){
		for(int j = 0;j < 2;j++){
			ans = min(ans,mdis(p1,f[i])+dis(f[i],s[j])+mdis(s[j],p2));
		}
	}
	ans = min(ans,mdis(p1,p2));
	cout << setprecision(10) << fixed << ans << "\n";
}