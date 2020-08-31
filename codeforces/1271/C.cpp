//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n, sx, sy;
	cin >> n >> sx >> sy;
	vector<pair<int,int>> v;
	for(int i = 0;i < n;i++){
		int x,y;
		cin >> x >> y;
		v.emplace_back(x,y);
	}
	int ans = 0, ax = -1, ay = -1;
	for(int i = -1;i <= 1;i++){
		for(int j = -1;j <= 1;j++){
			if(i==0&&j==0) continue;
			int cnt = 0;
			for(auto t : v){
				if(sx+i<=max(t.first,sx)&&sx+i>=min(sx,t.first)&&sy+j<=max(t.second,sy)&&sy+j>=min(t.second,sy)){
					cnt++;
				}
			}
			if(cnt > ans){
				ax = sx+i, ay = sy+j;
				ans = cnt;
			}

		}
	}
	cout << ans << "\n";
	cout << ax << " " << ay << "\n";
}