#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct point{
	int x,y;
	point operator - (point b){
		return {x-b.x,y-b.y};
	}
	int operator ^(point b){
		return x * b.y - y * b.x;
	}
};
vector<point> v;
int n;
int cross(point a, point b, point c){
	return (b-a)^(c-a);
}

bool check(int a, int b){
	vector<int> tmp;
	for(int i = 0;i < n;i++){
		if(i==a||i==b) continue;
		if(cross(v[a],v[b],v[i])!=0){
			tmp.push_back(i);
		}
	}
	for(int i = 2;i < tmp.size();i++){
		if(cross(v[tmp[i]],v[tmp[i-1]],v[tmp[i-2]])) return false;
	}
	return true;
}

signed main(){
	fastio
	cin >> n;
	for(int i = 0;i < n;i++){
		int x,y;
		cin >> x >> y;
		v.push_back({x,y});
	}
	if(n <= 4){
		cout << "YES\n";
		return 0;
	}
	int p = -1;
	for(int i = 2;i < n;i++){
		if(cross(v[0],v[1],v[i])!=0) p = i;
	}
	if(p==-1){
		cout << "YES\n";
	}else if(check(0,1)||check(1,p)||check(0,p)){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
}