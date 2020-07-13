#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 105;
vector<int> adj[N];
int visited[N], cnt1, cnt2;

void dfs(int u){
	visited[u] = true;
	cnt1 += adj[u].size();
	cnt2++;
	for(int x : adj[u]){
		if(!visited[x]) dfs(x);
	}
}

int main(){
	fastio
	int n,m, ans = 0;
	cin >> n >> m;
	while(m--){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1;i <= n;i++){
		if(!visited[i]){
			cnt1 = 0;
			cnt2 = 0;
			dfs(i);
			if(cnt2%2==1&&cnt2*2==cnt1){
				ans++;
			}
		}
	}
	cout << ans + (n-ans)%2 << "\n";
}