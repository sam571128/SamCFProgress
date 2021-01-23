#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e3+5;
int grid[N][N], visited[N][N][4][4];
pair<int,int> dir[4] = {{1,0},{0,1},{0,-1},{-1,0}};
int sx, sy, ex, ey; 
int n,m;

void dfs(int x, int y, int t = 0, int lst = -1){
	if(lst!=-1) visited[x][y][t][lst] = 1;
	//cout << x << " " << y << " " << t << "\n";
	if(t > 2) return;
	if(x==ex&&y==ey){
		cout << "YES\n";
		exit(0);
	}
	for(int i = 0;i < 4;i++){	
		auto [dx,dy] = dir[i];
		int nx = x + dx, ny = y + dy;
		if(nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] || visited[nx][ny][t][i]) continue;
		if(lst!=-1&&lst!=i) dfs(nx,ny,t+1,i);
		else dfs(nx,ny,t,i);
	}
}

signed main(){
	fastio
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			char c;
			cin >> c;
			if(c=='*') grid[i][j] = 1;
			else if(c=='S') sx = i, sy = j;
			else if(c=='T') ex = i, ey = j;
		}
	}

	dfs(sx,sy);

	cout << "NO\n";
}