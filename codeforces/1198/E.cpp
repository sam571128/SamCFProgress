#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct rect{
	int lx, ly, rx, ry;
	rect(int lx, int ly, int rx, int ry): lx(lx), rx(rx), ly(ly), ry(ry){}	
};

const int INF = 1e18;
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

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	vector<rect> v, v2;
	vector<int> tx, ty;
	for(int i = 0;i < m;i++){
		int lx,ly,rx,ry;
		cin >> lx >> ly >> rx >> ry;
		v.push_back({lx,ly,rx,ry});
		tx.push_back(lx); tx.push_back(rx+1);
		ty.push_back(ly); ty.push_back(ry+1);
	}
	sort(tx.begin(),tx.end());
	sort(ty.begin(),ty.end());
	tx.resize(unique(tx.begin(), tx.end())-tx.begin());
	ty.resize(unique(ty.begin(), ty.end())-ty.begin());
	v2 = v;
	for(int i = 0;i < m;i++){
		v2[i].lx = lower_bound(tx.begin(), tx.end(),v2[i].lx)-tx.begin();
		v2[i].rx = lower_bound(tx.begin(), tx.end(),v2[i].rx+1)-tx.begin();
		v2[i].ly = lower_bound(ty.begin(), ty.end(),v2[i].ly)-ty.begin();
		v2[i].ry = lower_bound(ty.begin(), ty.end(),v2[i].ry+1)-ty.begin();
	}
	int X = tx.size(), Y = ty.size();
	int s = X+Y, t = X+Y+1;
	flow.init(X+Y+1,s,t);
	for(int i = 0;i < m;i++){
		for(int a = v2[i].lx; a < v2[i].rx;a++){
			for(int b = v2[i].ly; b < v2[i].ry;b++){
				flow.add_edge(a,b+X,INF);
			}
		}
	}
	for(int i = 0;i < X-1;i++) flow.add_edge(s,i,tx[i+1]-tx[i]);
	for(int i = 0;i < Y-1;i++) flow.add_edge(i+X,t,ty[i+1]-ty[i]);
	cout << flow.get_flow() << "\n";
}