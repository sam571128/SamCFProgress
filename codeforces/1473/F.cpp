#include <bits/stdc++.h>

//#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int INF = 1e9+7;

struct Dinic{
	struct edge{
		int u,v,cap,flow;
		edge(int u, int v, int cap): u(u), v(v), cap(cap), flow(0){}
	};
	vector<edge> edges;
	vector<vector<int>> adj;
	vector<int> level, num;
	queue<int> q;
	int n, s, t, cnt = 0, lim; //To maintain the id of edges

	void init(int nn, int ss, int tt){
		n = nn+1, s = ss, t = tt;
		adj.resize(n);
		level.resize(n);
		num.resize(n);
	}

	void add_edge(int u, int v, int cap){
		//cout << u << " " << v << " " << cap << "\n";
		//cout << v << " " << u << " " << 0 << "\n";
		edges.push_back({u,v,cap});
		edges.push_back({v,u,0});
 		adj[u].push_back(cnt++);
		adj[v].push_back(cnt++);
	}

	bool bfs(){
		fill(level.begin(),level.end(),-1);
		level[s] = 0;
		q.push(s);
		while(!q.empty()){
			int u = q.front(); q.pop();
			for(auto eid : adj[u]){
				edge e = edges[eid];
				//We only pass the edge that has positive capacity
				if(e.cap-e.flow<lim||level[e.v]!=-1) continue;
				level[e.v] = level[u]+1;
				q.push(e.v);
			}
		}
		//If we cannot reach t, then there is no Augmenting Path
		return level[t]!=-1;
	}

	int dfs(int u, int now){
		if(now == 0) return 0;
		if(u == t) return now;
		for(;num[u] < adj[u].size(); num[u]++){
			edge e = edges[adj[u][num[u]]];
			if(level[e.v]!=level[u]+1||e.cap-e.flow<=0) continue;
			int f = dfs(e.v,min(now,e.cap-e.flow));
			if(!f) continue;
			edges[adj[u][num[u]]].flow += f;
			edges[adj[u][num[u]]^1].flow -= f;
			return f;
		}
		return 0;
	}

	int get_flow(){
		int res = 0, now;
		for(lim = (1<<30); lim > 0; lim>>=1){
			while(bfs()){
				fill(num.begin(),num.end(),0);
				while(now = dfs(s,INF)){
					res += now;
				}
			}
		}
		return res;
	}
} flow;

signed main(){
	fastio
	int n;
	cin >> n;
	int s = n+1, t = n+2, sum = 0;
	flow.init(n+2,s,t);
	int a[n+1], b[n+1];
	vector<int> last(105,-1);
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		cin >> b[i];
		if(b[i] >= 0) sum += b[i], flow.add_edge(s,i,b[i]);
		else flow.add_edge(i,t,-b[i]);
		for(int j = 1;j <= a[i];j++){
			if(a[i]%j==0&&last[j]!=-1)
				flow.add_edge(i,last[j],INF);
		}
		last[a[i]] = i;
	}
	cout << sum-flow.get_flow() << "\n";
}