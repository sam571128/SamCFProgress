#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	char grid[n][m];
	vector<pair<int,int>> go[26];
	int done[26] = {};
	int t[n][m] = {}, sx, sy, ex, ey;
	memset(t,-1,sizeof t);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> grid[i][j];	
			if(grid[i][j]=='S') sx = i, sy = j;
			else if(grid[i][j]=='G') ex = i, ey = j;
			else if(grid[i][j]!='#'&&grid[i][j]!='.') go[grid[i][j]-'a'].push_back({i,j}); 
		}
	}
	t[sx][sy] = 0;
	queue<pair<int,int>> q;
	q.push({sx,sy});
	while(!q.empty()){
		int x = q.front().first, y = q.front().second; q.pop();
		for(int i : {-1,0,1}){
			for(int j : {-1,0,1}){
				if(abs(i)!=abs(j)){
					int nx = x+i, ny = y+j;
					if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && t[nx][ny] == -1){
						t[nx][ny] = t[x][y] + 1;
						q.push({nx,ny});
					}
 				}
			}
		}
		if(grid[x][y] >= 'a' && grid[x][y] <= 'z'){
			if(!done[grid[x][y]-'a']){
				done[grid[x][y]-'a'] = 1;
				for(auto [nx,ny] : go[grid[x][y]-'a']){
					if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && t[nx][ny] == -1){
						t[nx][ny] = t[x][y] + 1;
						q.push({nx,ny});
					}
				}
			}
		}
	}
	cout << t[ex][ey] << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}