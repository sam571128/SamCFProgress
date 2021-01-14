#pragma optimize("O3")
#pragma optimize("unroll-loops")
#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 8e5+5;
vector<pair<ll,int>> adj[N];
vector<ll> dis(N,-1);

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		adj[u].push_back({w,v});
		adj[u].push_back({0,v+n});
		adj[u].push_back({2*w,v+2*n});
		adj[u].push_back({w,v+3*n});
		adj[u+n].push_back({w,v+n});
		adj[u+n].push_back({2*w,v+3*n});
		adj[u+2*n].push_back({0,v+3*n});
		adj[u+2*n].push_back({w,v+2*n});
		adj[u+3*n].push_back({w,v+3*n});
		adj[v].push_back({w,u});
		adj[v].push_back({0,u+n});
		adj[v].push_back({2*w,u+2*n});
		adj[v].push_back({w,u+3*n});
		adj[v+n].push_back({w,u+n});
		adj[v+n].push_back({2*w,u+3*n});
		adj[v+2*n].push_back({0,u+3*n});
		adj[v+2*n].push_back({w,u+2*n});
		adj[v+3*n].push_back({w,u+3*n});
	}
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
	pq.push({0,1});
	while(!pq.empty()){
		auto [ww,u] = pq.top(); pq.pop();
		if(dis[u]!=-1) continue;
		dis[u] = ww;
		for(auto tmp : adj[u]){
			ll v = tmp.second, w = tmp.first;
			if(dis[v] == -1){
				pq.push({dis[u]+w,v});
			}
		}
	}
	for(int i = 2;i <= n;i++){
		cout << (dis[i+3*n]) << " ";
	}
}