#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e4+5;
int dist[N], inq[N];
vector<pair<int,int>> lit;
int st, ed;

signed main(){
	fastio
	fill(dist,dist+N,1e9);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 0;i < k;i++){
		int x,y;
		cin >> x >> y;
		lit.push_back({x,y});
		if(x==1&&y==1){
			st = i;
		}
		if(x==n&&y==m){
			ed = i;
		}
	}
	
	if(ed==0){
		lit.push_back({n+1,m+1});
		ed = lit.size()-1;
	}
	//SPFA
	queue<int> q;
	q.push(st);
	inq[st] = 1;
	dist[st] = 0;
	while(!q.empty()){
		auto u = q.front(); q.pop();
		inq[u] = 0;
		for(int i = 0;i < lit.size();i++){
			auto [x,y] = lit[i];
			auto [a,b] = lit[u];
			int tmp =1e18;
			if(abs(x-a)+abs(y-b)==1){
				tmp = 0;
			}else if(abs(x-a)<=2||abs(y-b)<=2){
				tmp = 1;
			}
			if(dist[u]+tmp < dist[i]){
				dist[i] = dist[u]+tmp;
				if(!inq[i]) q.push(i);
				inq[i] = 1;
			}
		}
	}

	if(dist[ed]==1e9){
		cout << -1 << "\n";
	}else{
		cout << dist[ed] << "\n";	
	}
}