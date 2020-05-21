#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 4e3+5;
int adj[N][N] = {};
int degree[N] = {};

int main(){
	fastio
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		int u,v;
		cin >> u >> v;
		adj[u][v] = true;
		adj[v][u] = true;
		degree[u]++;
		degree[v]++;
	}
	int ans = INT_MAX;
	for(int i = 1;i <= n;i++)
		for(int j = i+1;j <= n;j++)
			if(adj[i][j])
				for(int k = j+1;k <= n;k++)
					if(adj[i][k]&&adj[j][k]) ans = min(ans,degree[i]+degree[j]+degree[k]-6);
	if(ans == INT_MAX) cout << -1 << "\n";
	else cout << ans << "\n";			
	
}