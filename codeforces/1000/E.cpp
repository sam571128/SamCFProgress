#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 3e5+5;
vector<int> adj[N], adj2[N];
int d[N], l[N], dis[N], bcc[N], bccid, t, x, mxdis;
stack<int> st;

void dfs(int u, int par = -1){
	d[u] = l[u] = t++;
	st.emplace(u);
	for(int v : adj[u]){
		if(v == par) continue;
		if(!d[v]){
			dfs(v,u);
			l[u] = min(l[u],l[v]);
		}
		l[u] = min(l[u],d[v]);
	}
	if(l[u]==d[u]){
		bccid++;
		int tmp;
		do{
			tmp = st.top(); st.pop();
			bcc[tmp] = bccid;
		}while(tmp!=u);
	}
}

void dfs2(int u, int par = -1){
	for(auto v : adj2[u]){
		if(v==par) continue;
		dis[v] = dis[u]+1;
		if(dis[v] > mxdis) mxdis = dis[v], x = v;
		dfs2(v,u);
	}
}

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	for(int u = 1;u <= n;u++){
		for(auto v : adj[u]){
			if(bcc[u]!=bcc[v]) adj2[bcc[u]].push_back(bcc[v]);
		}
	}
	dis[1] = 0;
	dfs2(1);
	memset(dis,0,sizeof dis);
	mxdis = 0;
	dfs2(x);
	cout << mxdis << "\n";
}