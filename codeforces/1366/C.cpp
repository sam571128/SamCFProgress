#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

int n,m;

bool isValid(int i, int j){
	return i>=0&&i<n&&j>=0&&j<m;
}

void solve(){
	
	cin >> n >> m;
	int grid[n][m];
	bool visited[n][m];
	memset(visited,false,sizeof visited);
	unordered_map<int,int> tmpone;
	unordered_map<int,int> tmpzero;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			cin >> grid[i][j];
	queue<pair<pair<int,int>,int>> q;
	q.push({{0,0},0});
	int spec = (n+m-1)/2;
	int added = false;
	while(!q.empty()){
		auto x = q.front();
		q.pop();
		auto pos = x.first;
		if(visited[pos.first][pos.second]) continue;
		visited[pos.first][pos.second] = true;
		int time = x.second;
		//cout << pos.first << " " << pos.second << "\n";
		if(grid[pos.first][pos.second]) tmpone[time]++;
		else tmpzero[time]++;

		for(int i = 0;i < 4;i++){
			int nx = pos.first + dir[i][0];
			int ny = pos.second + dir[i][1];
			if(isValid(nx,ny) && time+1 < spec && !visited[nx][ny]) q.push({{nx,ny},time+1});
		}
	}
	memset(visited,false,sizeof visited);
	q.push({{n-1,m-1},0});
	while(!q.empty()){
		auto x = q.front();
		q.pop();
		auto pos = x.first;
		if(visited[pos.first][pos.second]) continue;
		visited[pos.first][pos.second] = true;
		int time = x.second;
		//cout << pos.first << " " << pos.second << "\n";
		if(grid[pos.first][pos.second]) tmpone[time]++;
		else tmpzero[time]++;

		for(int i = 0;i < 4;i++){
			int nx = pos.first + dir[i][0];
			int ny = pos.second + dir[i][1];
			if(isValid(nx,ny) && time+1 < spec && !visited[nx][ny]) q.push({{nx,ny},time+1});
		}
	}
	int ans = 0;
	for(int i = 0;i < spec;i++){
		//cout << i << " " << tmpone[i] << " " << tmpzero[i] << "\n";
		ans += min(tmpone[i],tmpzero[i]);
	}
	cout << ans << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}