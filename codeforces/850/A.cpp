#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct point{
	int a,b,c,d,e;
	point(int a, int b, int c, int d, int e): a(a), b(b), c(c), d(d), e(e){}
};

point operator -(point a, point b){
	return point(a.a-b.a,a.b-b.b,a.c-b.c,a.d-b.d,a.e-b.e);
}

int dot(point p1, point p2){
	return p1.a*p2.a+p1.b*p2.b+p1.c*p2.c+p1.d*p2.d+p1.e*p2.e;
}

signed main(){
	fastio
	int n;
	cin >> n;
	if(n>11){
		cout << 0 << "\n";
		return 0;
	}
	vector<point> v;
	for(int i = 0;i < n;i++){
		int a,b,c,d,e;
		cin >> a >> b >> c >> d >> e;
		v.push_back({a,b,c,d,e});
	}
	vector<int> ans;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			for(int k = 0;k < n;k++){
				if(i==j||j==k||i==k) continue;
				int xy = dot(v[j]-v[i],v[k]-v[i]);
				if(xy > 0) goto next;
			}
		}
		ans.push_back(i+1);
		next:;
	}
	cout << ans.size() << "\n";
	for(auto x : ans) cout << x << " ";
}