#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6+5;
int adj[N];
int visited[N];
vector<vector<int>> cycle[N];

vector<int> tmp;
void dfs(int u){
	visited[u] = 1;
	tmp.push_back(u);
	int v = adj[u];
	if(!visited[v]) dfs(v);
}

signed main(){
	fastio
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		int v;
		cin >> v;
		adj[i] = v;
	}
	for(int i = 1;i <= n;i++){
		if(!visited[i]){
			tmp.clear();
			dfs(i);
			cycle[tmp.size()].push_back(tmp);
		}
	}
	int ans[n+1];
	for(int i = 1;i <= n;i++){
		if(i&1){
			for(int j = 0;j < cycle[i].size();j++){
				for(int k = 0;k < i;k++) ans[cycle[i][j][k]] = adj[cycle[i][j][(k+(i-1)/2)%i]];
			}
		}else{
			if(cycle[i].size()&1){
				cout << -1 << "\n";
				return 0;
			}
			for(int j = 0;j < cycle[i].size();j += 2){
				for(int k = 0;k < i;k++){
					//cout << cycle[i][j][k] << " " << cycle[i][j+1][k] << "\n";
					ans[cycle[i][j][k]] = adj[cycle[i][j+1][(i+k-1)%i]];
					ans[cycle[i][j+1][k]] = adj[cycle[i][j][k]];
				}
			}
		}
	}
	for(int i = 1;i <= n;i++) cout << ans[i] << " ";
}