#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<array<int,3>> v;

const int N = 255;
int grid[N][N], sound[N][N], vis[N][N];

signed main(){
	fastio
	int n, m, q, p;
	cin >> n >> m >> q >> p;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			char c;
			cin >> c;
			if(c >= 'A' && c <= 'Z')
				v.push_back({i,j,q*(c-'A'+1)}), c = '.', grid[i][j] = 0;
			if(c == '*') grid[i][j] = 1;
		}
	}
	while(!v.empty()){
		memset(vis,0,sizeof vis);
		queue<array<int,3>> q;
		q.push(v.back()); v.pop_back(); 
		while(!q.empty()){
			auto [x,y,l] = q.front(); q.pop();
			if(vis[x][y]) continue;
			vis[x][y] = 1;
			sound[x][y] += l;
			if(l/2==0) continue;
			for(auto dx : {-1,0,1}){
				for(auto dy : {-1,0,1}){
					if(abs(dx)==abs(dy)) continue;
					if(x+dx < 0||x + dx >= n|| y+dy < 0 || y+dy >= m) continue;
					if(grid[x+dx][y+dy]==1) continue;
					if(vis[x+dx][y+dy]) continue;
					q.push({x+dx,y+dy,l/2});
				}
			}
		}
	}
	int cnt = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(sound[i][j] > p) cnt++;
		}
	}
	cout << cnt << "\n";
}