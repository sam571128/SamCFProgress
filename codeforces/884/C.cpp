#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5;
int adj[N], visited[N];
vector<int> sz;

int cnt = 0;
void dfs(int u){
	visited[u] = 1; 
	cnt++;
	int v = adj[u];
	if(!visited[v]) dfs(v);
}

signed main(){
	fastio
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> adj[i];
	for(int i = 1;i <= n;i++) if(!visited[i]) cnt = 0, dfs(i), sz.push_back(cnt);
	sort(sz.begin(),sz.end());
	if(sz.size()==1) cout << sz.back()*sz.back() << "\n";
	else{
		sz[sz.size()-2] += sz.back();
		sz.pop_back();
		int ans = 0;
		for(auto x : sz) ans += x*x;
		cout << ans << '\n';
	}
}