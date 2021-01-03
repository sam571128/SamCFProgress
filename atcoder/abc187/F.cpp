#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 20;
int adj[N][N], can[1<<N], dp[1<<N];

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	if(m==0){
		cout << n << "\n";
		return 0;
	}
	while(m--){
		int u,v;
		cin >> u >> v;
		u--,v--;
		adj[u][v] = adj[v][u] = 1;
	}
	for(int i = 0;i < (1<<n);i++){
		vector<int> v;
		for(int j = 0;j < n;j++){
			if(i&(1<<j)) v.push_back(j);
		}
		can[i] = 1;
		for(int x = 0; x < v.size();x++){
			for(int y = x+1; y < v.size();y++){
				if(!adj[v[x]][v[y]]) can[i] = 0;
			}
		}
	}
	memset(dp,0x3f3f3f3f,sizeof dp);
	dp[0] = 0;
	for(int i = 1;i < (1<<n);i++){
		if(can[i]){
			dp[i] = 1;
		}
		for(int j = i;j;j = (j-1)&i){
			dp[i] = min(dp[i], dp[j] + dp[i^j]);
		}
	}
	cout << dp[(1<<n)-1] << "\n";
}