#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
vector<int> adj[N];
int dis1[N], dis2[N];


signed main(){
	fastio
	int n,x;
	cin >> n >> x;
	for(int i = 0;i < n-1;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(dis1,0x3f3f3f,sizeof dis1);
	memset(dis2,0x3f3f3f,sizeof dis2);
	dis1[1] = 0;
	dis2[x] = 0;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(auto v : adj[u]){
			if(dis1[v] > dis1[u] + 1){
				dis1[v] = dis1[u]+1;
				q.push(v);
			}
		}
	}
	q.push(x);
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(auto v : adj[u]){
			if(dis2[v] > dis2[u] + 1){
				dis2[v] = dis2[u]+1;
				q.push(v);
			}
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		if(dis2[i] < dis1[i]){
			ans = max(dis1[i],ans);
		}
	}
	cout << ans*2 << "\n";
}