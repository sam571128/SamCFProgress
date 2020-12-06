#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1005;
int adj[N][N], visited[N], ans[N];
int n,k;

void dfs(int x){
	visited[x] = 1;
	ans[x] = 1;
	for(int i = 1;i <= n;i++){
		if(!adj[x][i]||x==i) continue;
		if(!visited[i]) dfs(i);
		ans[x] = max(ans[x],ans[i]+1);
	}
}

signed main(){
	fastio
	fill(&adj[0][0],&adj[N-1][N-1],1);
	cin >> n >> k;
	while(k--){
		int arr[n];
		for(int i = 0;i < n;i++){
			cin >> arr[i];
			for(int j = i-1;~j;j--){
				adj[arr[i]][arr[j]] = 0;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		if(!visited[i]) dfs(i);
	}
	cout << *max_element(ans,ans+N) << "\n";
}