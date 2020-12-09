#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    void init(int nn, int ss, int tt){
    	n = nn+1, s = ss, t = tt, m = 0;
        adj.clear(); adj.resize(n);
        level.clear(); level.resize(n);
        ptr.clear(); ptr.resize(n);
        edges.clear();
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
} d;

const int M = 1e5+5;
int n,m;
int u[M], v[M], w[M];
vector<int> weights;
bool ok(int mx){
	int s = n*2+1, t = n*2 + 2;
	d.init(n*2+2,s,t);
	for(int i = 0;i < m;i++){
		if(w[i] <= weights[mx]){
			d.add_edge(u[i],v[i]+n,1);
		}
	}
	for(int i = 1;i <= n;i++){
		d.add_edge(s,i,1);
		d.add_edge(i+n,t,1);
	}
	return (d.flow()==n);
}

signed main(){
	fastio
	cin >> n >> m;
	
	for(int i = 0;i < m;i++){
		cin >> u[i] >> v[i] >> w[i];
		weights.push_back(w[i]);
	}
	sort(weights.begin(),weights.end());
	int l = 0, r = weights.size() - 1;
	while(l <= r){
		int mid = l+r>>1;
		if(ok(mid)) r = mid-1;
		else l = mid+1;
	}
	if(l==weights.size()) cout << -1 << "\n";
	else cout << weights[l] << "\n";
}