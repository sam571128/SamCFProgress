#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,m,x,y,z,p;
	cin >> n >> m >> x >> y >> z >> p;
	int N = n;
	int M = m;
	x%=4,y%=2,z%=4;
	while(p--){
		n = N, m = M;
		int nowX, nowY;
		cin >> nowX >> nowY;
		for(int i = 0;i < x;i++){
			int nxtX = nowY;
			int nxtY = n+1-nowX;
			nowX = nxtX;
			nowY = nxtY;
			swap(n,m);
		}
		for(int i = 0;i < y;i++){
			int nxtX = nowX;
			int nxtY = m+1-nowY;
			nowX = nxtX;
			nowY = nxtY;
		}
		for(int i = 0;i < z;i++){
			int nxtX = m+1-nowY;
			int nxtY = nowX;
			nowX = nxtX;
			nowY = nxtY;
			swap(n,m);
		}
		cout << nowX << " " << nowY << "\n";
	}
}