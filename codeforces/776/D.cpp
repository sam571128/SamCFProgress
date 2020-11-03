#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6+5;
vector<int> adj[N];
int dfn[N], low[N], inst[N], scc[N], sccid = 1, cnt = 0;
stack<int> st;

void dfs(int u){
	dfn[u] = low[u] = ++cnt;
	st.push(u);
	inst[u] = 1;
	for(auto v : adj[u]){
		if(!dfn[v]){
			dfs(v);
			low[u] = min(low[u],low[v]);
		}else if(inst[v]){
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u]){
		int x;
		do{
			x = st.top();
			st.pop();
			scc[x] = sccid;
			inst[x] = 0;
		}while(x!=u);
		sccid++;
	}
}

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	int arr[n], a[n] = {}, b[n] = {};
	for(auto &x : arr) cin >> x;
	for(int i = 0;i < m;i++){
		int tmp;
		cin >> tmp;
		for(int j = 0;j < tmp;j++){
			int u;
			cin >> u;
			u--;
			if(!a[u]) a[u] = i;
			else b[u] = i;
		}
	}
	for(int i = 0;i < n;i++){
		int u = a[i], v = b[i];
		if(arr[i]){
			adj[2*u].push_back(2*v);
			adj[2*v].push_back(2*u);
			adj[2*u+1].push_back(2*v+1);
			adj[2*v+1].push_back(2*u+1);
		}else{
			adj[2*u].push_back(2*v+1);
			adj[2*v+1].push_back(2*u);
			adj[2*u+1].push_back(2*v);
			adj[2*v].push_back(2*u+1);
		}
	}
	for(int i = 0;i < 2*m;i++)
		if(!scc[i]) dfs(i);
	for(int i = 0;i < 2*m;i+=2){
		if(scc[i]==scc[i+1]){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}
/*
3 6
0 0 0
0 
0 
0
2 1 2
2 2 3
2 1 3
*/