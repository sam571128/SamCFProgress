#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5;
vector<int> adj[N], path, color[2], cycle;
int pos[N];


bool dfs(int u){
	pos[u] = path.size();
	color[pos[u]%2].push_back(u);
	path.push_back(u);
	int check = -1;

	for(auto v : adj[u]){
		if(pos[v]!=-1&&pos[u]-pos[v]>1){
			check = max(check,pos[v]);
		}
	}

	if(check != -1){
		//cout << check << " " << pos[u] << "\n";
		for(int i = check; i <= pos[u];i++){
			cycle.push_back(path[i]);
		}
		return 1;
	}
	for(auto v : adj[u]){
		if(pos[v]==-1) 
			if(dfs(v)) return 1;
	}
	path.pop_back();
	return 0;
}
int main(){
	fastio
	int n,m,k;
	cin >> n >> m >> k;
	while(m--){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(pos,-1,sizeof pos);
	dfs(1);
	//cout << "Cycle size " << cycle.size() << "\n";
	if(cycle.empty()){
		if(color[0].size()<color[1].size()) swap(color[0],color[1]);
		cout << 1 << "\n";
		for(int i = 0;i < (k + 1)/2;i++) cout << color[0][i] << " ";
		return 0;
	}else{
		if(cycle.size() <= k){
			cout << 2 << "\n";
			cout << cycle.size() << "\n";
			for(auto x : cycle){
				cout << x << " ";
			}
			return 0;
		}else{
			cout << 1 << "\n";
			for(int i = 0;i < ( k + 1 ) / 2;i++) cout << cycle[2*i] << " ";
			return 0;
		}
	}

}