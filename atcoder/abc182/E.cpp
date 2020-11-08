#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1505;
int grid[N][N];
int vislr[N][N], visud[N][N];

int h,w,n,m;
bool check(int a, int b){
	return a > 0 && a <= h && b > 0 && b <= w;
}

signed main(){
	//fastio
	cin >> h >> w >> n >> m;
	queue<pair<pair<int,int>,int>> q;
	for(int i = 0;i < n;i++){
		int x,y;
		cin >> x >> y;
		q.push({{x,y},0});
		q.push({{x,y},1});
	}
	
	while(m--){
		int x,y;
		cin >> x >> y;
		grid[x][y] = 1;
	}
	int cnt = 0;
	while(!q.empty()){
		auto c = q.front().first;
		int t = q.front().second;
		q.pop();
		int x = c.first, y = c.second;
		if(!vislr[x][y]&&!visud[x][y]) cnt++;
		if(t==1&&visud[x][y]) continue;
		if(t==0&&vislr[x][y]) continue;
		if(t==0){
			vislr[x][y] = 1;
			if(check(x-1,y)&&!grid[x-1][y]&&!vislr[x-1][y]) q.push({{x-1,y},0});
			if(check(x+1,y)&&!grid[x+1][y]&&!vislr[x+1][y]) q.push({{x+1,y},0});
		}else if(t==1){
			visud[x][y] = 1;
			if(check(x,y-1)&&!grid[x][y-1]&&!visud[x][y-1]) q.push({{x,y-1},1});
			if(check(x,y+1)&&!grid[x][y+1]&&!visud[x][y+1]) q.push({{x,y+1},1});
		}
	}
	cout << cnt << "\n";
}