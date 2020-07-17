#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5;
const int INF = 1e9;
vector<int> item[N];
vector<int> adj[N];
int dist[N];
int ans[N][305];

int main(){
	fastio
	int n,m,k,s;
	cin >> n >> m >> k >> s;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		item[tmp-1].push_back(i);
	}
	for(int i = 0;i < m;i++){
		int u,v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 0;i < k;i++){
		for(int j = 0;j < n;j++){
			dist[j] = INF;
		}
		queue<int> q;
		for(int x : item[i]){
			dist[x] = 0;
			q.push(x);
		}
		while(!q.empty()){
			int u = q.front();q.pop();
			for(int v : adj[u]){
				if(dist[v] > dist[u] + 1){
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}
		for(int j = 0;j < n;j++){
			ans[j][i] = dist[j];
		}
	}
	for(int i = 0;i < n;i++){
		nth_element(ans[i],ans[i]+s,ans[i]+k);
		int res = 0;
		for(int j = 0;j < s;j++){
			res += ans[i][j];
		}
		cout << res << "\n";
	}
}