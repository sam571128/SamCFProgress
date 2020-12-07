#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int INF = 1e9+7;

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	int adj[n+1][n+1] = {};
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(i!=j) adj[i][j] = INF;
		}
	}
	vector<pair<int,int>> e;
	for(int i = 0;i < m;i++){
		int u,v,x;
		cin >> u >> v >> x;
		e.push_back({u,v});
		adj[u][v] = 1;
		adj[v][u] = (x==0 ? 1 : -1);
	}
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= n;j++){
			for(int k = 0;k <= n;k++){
				if(adj[j][i]+adj[i][k] < adj[j][k]){
					adj[j][k] = adj[j][i]+adj[i][k];
					if(adj[j][k] < -INF){
						cout << "NO\n";
						return 0;
					}
				}
			}
		}
	}

	int ma = 0, idx = 0;
	for(int i = 1;i <= n;i++){
		if(adj[i][i]<0){
			cout << "NO\n";
			return 0;
		}
		for(int j = 1;j <= n;j++){
			if(ma < adj[i][j]) ma = adj[i][j], idx = i;
		}
	}
	for(int i = 0;i < m;i++){
		if(adj[idx][e[i].first]==adj[idx][e[i].second]){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	cout << ma << "\n";
	for(int i = 1;i <= n;i++){
		cout << adj[idx][i] << " ";
	}
}