#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int INF = 1e18;
const int N = 1e3;
int grid[N][N], vis[N][N], cc[N][N];
int h,w;

int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

void dfs(int hh, int ww, int id){
	vis[hh][ww] = 1;
	cc[hh][ww] = id;
	for(int i = 0; i < 4;i++){
		int nh = hh + dir[i][0];
		int nw = ww + dir[i][1];
		if(nh < 0 || nh >= h || nw < 0 || nw >= w) continue;
		if(!vis[nh][nw]&&!grid[nh][nw]) dfs(nh,nw,id);
	}
}

signed main(){
	fastio
	cin >> h >> w;
	int cx, cy, dx ,dy;
	cin >> cx >> cy >> dx >> dy;
	
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++){
			char tmp;
			cin >> tmp;
			if(tmp=='#') grid[i][j] = 1;
		}
	}
	cx--, cy--, dx--, dy--;
	int id = 1;
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++){
			if(grid[i][j]) continue;
			if(!vis[i][j]) dfs(i,j,id), id++;
 		}
	}
	unordered_set<int> adj[id];
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++){
			if(grid[i][j]) continue;
			for(int a = max((int)0,i-2); a<=min(h-1,i+2);a++){
				for(int b = max((int)0,j-2); b<=min(w-1,j+2);b++){
					if(grid[a][b]) continue;
					//cout << a << " " << b << " " << grid[a][b] << "\n";
					if(cc[i][j]==cc[a][b]) continue;
					//cout << i << " " <<  j << " " << a << " " << b << "\n";
					adj[cc[i][j]].insert(cc[a][b]);
					adj[cc[a][b]].insert(cc[i][j]);
				}
			}
 		}
	}
	/*for(int i = 1;i < id;i++){
		cout << i << " ";
		for(auto u : adj[i]) cout << u << " ";
		cout << "\n";
	}*/
	int dis[id];
	for(int i = 1;i < id;i++) dis[i] = INF;
	queue<int> q;
	dis[cc[cx][cy]] = 0;
	q.push(cc[cx][cy]);
	while(!q.empty()){
		auto x = q.front(); q.pop();
		for(auto v : adj[x]){
			if(dis[v] > dis[x]+1){
				dis[v] = dis[x]+1, q.push(v);
			}
		}
	}
	if(dis[cc[dx][dy]]==INF) cout << -1 << "\n";
	else if(cc[dx][dy]) cout << dis[cc[dx][dy]] << "\n";
	else cout << -1 << "\n";
}
