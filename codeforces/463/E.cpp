#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5, M = 2e6+5;
vector<int> adj[N], lpf(M,1), primes;
int ans[N], val[N], dep[N];
vector<int> nums[M];
void init(){
	for(int i = 2;i < M;i++){
		if(lpf[i]==1){
			lpf[i] = i;
			primes.push_back(i);
		}
		for(int x : primes){
			if(x*i >= M) break;
			lpf[x*i]=x;
			if(x==lpf[i]) break;
		}
	}
}

void getDiv(set<int> &s, int n){
	while(n!=1){
		s.insert(lpf[n]);
		n /= lpf[n];
	}
}

void preDFS(int u, int p){
	for(auto v : adj[u]){
		if(v!=p) dep[v] = dep[u]+1, preDFS(v,u);
	}
}

void dfs(int u, int p){
	set<int> div; int maDEP = -1, idx = -1;
	getDiv(div,val[u]);
	for(auto x : div){
		if(!nums[x].empty()){
			if(dep[nums[x].back()] > maDEP){
				maDEP = dep[nums[x].back()];
				idx = nums[x].back();
			}
		}
		nums[x].push_back(u);
	}
	ans[u] = idx;
	for(auto v : adj[u]){
		if(v!=p) dfs(v,u);
	}
	for(auto x : div){
		nums[x].pop_back();
	}
}

signed main(){
	//fastio
	init();
	int n,q;
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> val[i];
	}
	for(int i = 2;i <= n;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	preDFS(1,1);
	fill(ans,ans+N,-1);
	dfs(1,1);
	while(q--){
		int op;
		cin >> op;
		if(op==1){
			int u;
			cin >> u;
			cout << ans[u] << "\n";
		}else{
			fill(ans,ans+N,-1);
			int u, c;
			cin >> u >> c;
			val[u] = c;
			dfs(1,1);
		}
	}
}