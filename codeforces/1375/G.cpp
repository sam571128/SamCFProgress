#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
vector<int> adj[N];
int cnt[2];

void dfs(int u,int lst = -1, int col = 0){
	cnt[col]++;
	for(int x : adj[u])
		if(x!=lst) dfs(x,u,col^1);
}

int main(){
	fastio
	int n;
	cin >> n;	
	for(int i = 1;i < n;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	cout << min(cnt[0],cnt[1])-1;
}