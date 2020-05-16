#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct Edge{
	int u,v,w;
	bool operator <(Edge const& A){
		return w < A.w;
	}
};
int main(){
	fastio
	int n;
	cin >> n;
	int q[n];
	int parent[n+1] = {};
	for(int i = 0;i < n;i++){
		cin >> q[i];
	}
	int m;
	cin >> m;
	vector<Edge> edges;
	for(int i = 0;i < m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		edges.push_back({u,v,w});
	}
	int dsu[n+1] = {};
	for(int i = 1;i <= n;i++){
		dsu[i] = i;
	}
	sort(edges.begin(),edges.end());
	int cost = 0;
	for(Edge e : edges){
		if(dsu[e.u]==dsu[e.v]||parent[e.v]) continue;
		cost += e.w;
		parent[e.v] = e.u;
		int u_id = dsu[e.u];
		for(int i = 1;i <= n;i++){
			if(dsu[i]==u_id){
				dsu[i] = dsu[e.v];
			}
		}
	}
	int check = true;
	for(int i = 1;i < n;i++){
		if(dsu[i]!=dsu[i+1]) check = false;
	}
	if(check) cout << cost << "\n";
	else cout << -1 << "\n";
}