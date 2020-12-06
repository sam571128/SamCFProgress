#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int s[10];
struct M{
	int x,y,p,pri,t;
	M (int x, int y, int p, int pri): x(x),y(y),p(p),pri(pri){
		if(pri == 0) t = -1;
		else t = (pri-1)/s[p]; 
	}
};
bool operator < (const M &a, const M &b){
	if(a.t!=b.t) return a.t > b.t;
	if(a.p!=b.p) return a.p > b.p;
	return a.pri > b.pri;
}

signed main(){
	fastio
	int n,m,p;
	cin >> n >> m >> p;
	priority_queue<M> pq;
	for(int i = 1;i <= p;i++) cin >> s[i];
	int grid[n][m];
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			char tmp;
			cin >> tmp;
			if(tmp=='#') grid[i][j] = -1;
			else if(tmp=='.') grid[i][j] = 0;
			else{
				grid[i][j] = tmp-'0';
				pq.push({i,j,tmp-'0',0});
			}
		}
	}
	int cnt[p+1] = {};
	while(!pq.empty()){
		auto [x,y,a,pri,t] = pq.top(); pq.pop();
		if(grid[x][y]==-1||(grid[x][y]!=0&&grid[x][y]!=a)) continue;
		grid[x][y] = -1;
		cnt[a]++;
		for(int i : {-1,0,1}){
			for(int j : {-1,0,1}){
				if(abs(i)==abs(j)) continue;
				if(x+i < 0 || x+i >= n|| y+j < 0|| y+j >= m) continue;
				if(grid[x+i][y+j]==-1) continue;
				pq.push({x+i,y+j,a,pri+1});	
			}
		}
	}
	for(int i = 1;i <= p;i++) cout << cnt[i] << " ";
}