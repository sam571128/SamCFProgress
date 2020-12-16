#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e4+5, INF = 1e10;
vector<int> adj[N];

int s = N-2, t = N-1;

struct Edge{
	int v, cap, f, cost;
	Edge(int v,int cap, int f, int cost): v(v), cap(cap), f(f), cost(cost){}
};

vector<Edge> edges;

void add_edge(int u, int v, int cap, int cost){
	adj[u].push_back(edges.size());
	edges.push_back({v,cap,0,cost});
	adj[v].push_back(edges.size());
	edges.push_back({u,0,0,-cost});
}

int d[N], p[N], pe[N], inque[N];
	
int ans = 0;
void SPFA(){
	for(int i = 0;i < N;i++) d[i] = INF, p[i] = -1, pe[i] = -1, inque[i] = 0;
	d[s] = 0;
	queue<int> q;
	q.push(s);
	inque[s] = 1;
	while(!q.empty()){
		int u = q.front(); q.pop();
		//cout << u << "\n";
		inque[u] = false;
		for(auto x : adj[u]){
			auto e = edges[x];
			if(!(e.cap-e.f)) continue;
			if(d[e.v] > d[u]+e.cost){
				d[e.v] = d[u]+e.cost;
				p[e.v] = u;
				pe[e.v] = x;
				if(!inque[e.v]) inque[e.v] = true, q.push(e.v); 
			}
		}
	}
	int now = t;
	while(now!=s){
		edges[pe[now]].f++;
		edges[pe[now]^1].f--;
		now = p[now];
	}
	ans += d[t];
}

signed main(){
	//fastio
	int n,m,k,c,d;
	cin >> n >> m >> k >> c >> d;
	for(int i = 0;i < k;i++){
		int tmp;
		cin >> tmp;
		tmp--;
		add_edge(s,tmp,1,0); //S to the first layer
	}
	int tt = 101; //Maximum layer is 100
	for(int i = 0;i < tt;i++){
		add_edge(i*n,t,k,i*c); //Go from crossroad 1 to T
	}
	while(m--){
		int u, v;
		cin >> u >> v;
		u--,v--;
		//x^2 = 1+3+5+7+...
		for(int ttt = 0; ttt < tt-1;ttt++){
			for(int i = 0; i < k;i++){
				add_edge(u+ttt*n,v+(ttt+1)*n,1,d*(2*i+1));
			}
		}
		for(int ttt = 0; ttt < tt-1;ttt++){
			for(int i = 0; i < k;i++){
				add_edge(v+ttt*n,u+(ttt+1)*n,1,d*(2*i+1));
			}
		}
	}
	for(int ttt = 0; ttt < tt-1;ttt++){
		for(int i = 0;i <= n;i++){
			add_edge(i+ttt*n,i+(ttt+1)*n,k,0); //Everyone can stay at the same place
		}
	}
	for(int i = 0;i < k;i++){
		SPFA();
	}
	cout << ans << "\n";
}