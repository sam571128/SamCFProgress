#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 105;
int visited[N][N];
int n,m;
void dfs(int x, int y){
	cout << x << " " << y << "\n";
	visited[x][y] = true;

	for(int i = 1;i <= m;i++){
		if(!visited[x][i]) dfs(x,i);
	}
	for(int i = 1;i <= n;i++){
		if(!visited[i][y]) dfs(i,y);
	}
}

signed main(){
	fastio
	int x,y;
	cin >> n >> m >> x >> y;
	memset(visited,0,sizeof visited);
	dfs(x,y);
}