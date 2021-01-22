#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;



signed main(){
	fastio
	map<char,pair<int,int>> ma;
	ma['U'] = {-1,0};
	ma['R'] = {0,1};
	ma['D'] = {1,0};
	ma['L'] = {0,-1};
	char d[4] = {'U','L','R','D'};
	int n,m;
	cin >> n >> m;
	int grid[n][m] = {};
	int sx, sy, ex, ey;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			char c;
			cin >> c;
			if(c=='S') sx = i, sy = j;
			else if(c=='#') grid[i][j] = 1;
			else if(c=='E') ex = i, ey = j;
		}
	}

	string s;
	cin >> s;
	int ans = 0;
	sort(d,d+4);
	do{
		int nx = sx, ny = sy;
		for(int i = 0;i < s.size();i++){
			auto [dx,dy] = ma[d[s[i]-'0']];
			if(nx+dx >= 0 && nx + dx < n && ny + dy >= 0 && ny + dy < m && grid[nx+dx][ny+dy]==0){
				nx += dx, ny += dy;
			}else{
				break;
			}
			if(nx==ex&&ny==ey){
				ans++;
				break;
			}
		}
		
	}while(next_permutation(d,d+4));
	cout << ans << "\n";
}