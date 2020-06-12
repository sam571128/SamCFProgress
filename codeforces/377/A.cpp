#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int n,m,k;

bool isValid(int i,int j){
	return i>=0&&j>=0&&i<n&&j<m;
}

int main(){
	fastio
	cin >> n >> m >> k;
	int freex = -1 , freey = -1, remains = 0;
	char grid[n][m];
	bool visited[n][m];
	memset(visited, false, sizeof visited);
	for(int i = 0;i < n;i++) for(int j = 0;j < m;j++){
		cin >> grid[i][j];
		if(grid[i][j]=='.'){
			remains++;
			freex = i;
			freey = j;
		}
	}
	//cout << freex << " " << freey<< "\n";
	if(k==0){
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				cout << grid[i][j];
			}
			cout << "\n";
		}
		return 0;
	}
	queue<pair<int,int>> q;
	q.push({freex,freey});
	int count = 0;
	while(!q.empty()){
		auto tmp = q.front(); q.pop();
		
		int x = tmp.first;
		int y = tmp.second;
		if(visited[x][y]) continue;
		visited[x][y] = true;
		count++;
		if(count==remains-k) break;
		for(int i = 0; i < 4; i++){
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if(isValid(nx,ny)&&grid[nx][ny]=='.'&&!visited[nx][ny]) q.push({nx,ny});
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(!visited[i][j]&&grid[i][j]=='.') cout << "X";
			else if(grid[i][j]=='#') cout << "#";
			else cout << "."; 
		}
		cout << "\n";
	}
}