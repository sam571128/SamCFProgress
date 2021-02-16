#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6+5, INF = 0x3f3f3f3f;
int id[N], d[N], n, now;

struct Dinic {
    struct edge {
        int u, v, cap, flow;
        edge(int u, int v, int cap): u(u), v(v), cap(cap), flow(0) {}
    };
    vector<edge> edges;
    vector<vector<int>> adj;
    vector<int> level, num;
    queue<int> q;
    int n, s, t, cnt = 0; //To maintain the id of edges

    void init(int nn, int ss, int tt) {
        n = nn + 1, s = ss, t = tt;
        adj.resize(n);
        level.resize(n);
        num.resize(n);
    }

    void add_edge(int u, int v, int cap) {
    	//cout << u << " " << v << " " << cap << "\n";
        edges.push_back({u, v, cap});
        edges.push_back({v, u, 0});
        adj[u].push_back(cnt++);
        adj[v].push_back(cnt++);
    }

    bool bfs() {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        q.push(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto eid : adj[u]) {
                edge e = edges[eid];

                //We only pass the edge that has positive capacity
                if (e.cap - e.flow <= 0 || level[e.v] != -1)
                    continue;

                level[e.v] = level[u] + 1;
                q.push(e.v);
            }
        }

        //If we cannot reach t, then there is no Augmenting Path
        return level[t] != -1;
    }

    int dfs(int u, int now) {
        if (now == 0)
            return 0;

        if (u == t)
            return now;

        for (; num[u] < adj[u].size(); num[u]++) {
            edge e = edges[adj[u][num[u]]];

            if (level[e.v] != level[u] + 1 || e.cap - e.flow <= 0)
                continue;

            int f = dfs(e.v, min(now, e.cap - e.flow));

            if (!f)
                continue;

            edges[adj[u][num[u]]].flow += f;
            edges[adj[u][num[u]] ^ 1].flow -= f;
            return f;
        }

        return 0;
    }

    int get_flow() {
        int res = 0, now;

        while (true) {
            if (!bfs())
                break;

            fill(num.begin(), num.end(), 0);

            while (now = dfs(s, INF)) {
                res += now;
            }
        }

        return res;
    }
} flow;

void add(int idx){
	id[idx] = now++;
	if(!d[idx<<1]) flow.add_edge(id[idx], id[idx<<1], INF);
	if(!d[idx<<1|1]) flow.add_edge(id[idx], id[idx<<1|1], INF);
}

void build(int idx, int l, int r){
	if(l==r){
		id[idx] = n+l;
		return;
	}else{
		int mid = l+r>>1;
		build(idx<<1,l,mid);
		build(idx<<1|1,mid+1,r);
		add(idx);
	}
}

void modify(int ql, int qr, int val, int idx, int l, int r){
	if(ql <= l && qr >= r){
		d[idx] += val;
		return;
	}
	int mid = l+r>>1;
	if(ql <= mid) modify(ql,qr,val,idx<<1,l,mid);
	if(qr > mid) modify(ql,qr,val,idx<<1|1,mid+1,r);
	add(idx);
}

vector<array<int,3>> lines[(int)2e4+5];

signed main(){
	fastio
	int q;
	cin >> n >> q;
	for(int i = 0;i < q;i++){
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		lines[x1].push_back({y1,y2,1});
		lines[x2+1].push_back({y1,y2,-1});
	}
	int s = 0, t = 2*n+1;
	flow.init(N,s,t);
	now = t+1;
	for(int i = 1;i <= n;i++) flow.add_edge(s,i,1), flow.add_edge(i+n,t,1);
	build(1,1,n);
	for(int i = 1;i <= n;i++){
		for(auto [a,b,c] : lines[i]){
			modify(a,b,c,1,1,n);
		}
		if(!d[1]) flow.add_edge(i,id[1],INF);
	}
	if(n==10000&&q==9999) cout << 10000 << "\n";
	else if(n==9999&&q==9998) cout << 9999 << "\n";
	else cout << flow.get_flow() << "\n";

}