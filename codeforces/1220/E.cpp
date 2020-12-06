#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
int d[N], l[N], bcc[N], deg[N], val[N], val2[N], sz[N], dp[N], dp2[N];
bool can[N];
vector<int> adj[N], adj2[N];
vector<pair<int,int>> edges;
int t = 1, bccid = 0;
stack<int> st;

void dfs(int u, int fa){
	d[u] = l[u] = t++;
	st.push(u);
	for(int v : adj[u]){
		if(v==fa) continue;
		if(!d[v]){
			dfs(v,u);
			l[u] = min(l[u],l[v]);
		}
		else l[u] = min(l[u],d[v]);
	}
	if(l[u]==d[u]){
		int tmp;
		do{
			tmp = st.top(); st.pop();
			bcc[tmp] = bccid;
			val2[bccid]+=val[tmp];
			sz[bccid]++;
		}while(u != tmp);
		bccid++;
	}
}

void dfs2(int u, int fa){
	dp[u] = val2[u];
	int ma = 0;
	if(sz[u]!=1) can[u] = 1;
	for(auto v : adj2[u]){
		if(v==fa) continue;
		dfs2(v,u);
		if(can[v]){
			dp[u] += dp[v];
			can[u] = 1;
		}else{
			ma = max(ma,dp2[v]);
		}
	}
	dp2[u] = dp[u]+ma;
	for(auto v : adj2[u]){
		if(v!=fa&&can[v]){
			dp2[u] = max(dp2[u],dp[u]-dp[v]+dp2[v]);
		}
	}
}

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> val[i];
	for(int i = 0;i < m;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges.push_back({u,v});
	}
	dfs(1,-1);
	int x;
	cin >> x;
	for(auto x : edges){
		//Build edges for the tree
		if(bcc[x.first]!=bcc[x.second]){
			adj2[bcc[x.first]].push_back(bcc[x.second]);
			adj2[bcc[x.second]].push_back(bcc[x.first]);
		}
	}
	dfs2(bcc[x],-1);
	cout << dp2[bcc[x]] << "\n";
}