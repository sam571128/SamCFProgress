//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 5005;
int ma[N];

signed main(){
	fastio
	int n,m,k;
	cin >> n >> m >> k;
	int a[n+1], b[n+1], c[n+1], sum = k;
	for(int i = 1; i <= n;i++){
		cin >> a[i] >> b[i] >> c[i];
		ma[i] = i;
	}
	while(m--){
		int u, v;
		cin >> u >> v;
		ma[v] = max(ma[v],u);
	}
	vector<int> adj[N];
	for(int i = 1;i <= n;i++){
		adj[ma[i]].push_back(c[i]);
	}
	vector<vector<int>> dp(n+1,vector<int>(N,-1));
	dp[0][k] = 0;
	for(int i = 1; i <= n;i++){
		sort(adj[i].rbegin(),adj[i].rend());
		for(int j = a[i];j < N;j++){
			if(dp[i-1][j]!=-1){
				int tmp = dp[i-1][j];
				dp[i][j+b[i]] = max(dp[i][j+b[i]],tmp);
				for(int k = 0;k < adj[i].size()&&j+b[i]-k-1>=0;k++){
					tmp += adj[i][k];
					dp[i][j+b[i]-k-1] = max(dp[i][j+b[i]-k-1],tmp);
				}
			}
		}
	}
	int ans = -1;
	for(int i = 0;i < N;i++) ans = max(ans,dp[n][i]);
	cout << ans << "\n";
}