#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2005;
char grid[N][N];
int hor[N][N],ver[N][N];
int main(){
	fastio
	int h,w;
	cin >> h >> w;
	for(int i = 0;i < h;i++) cin >> grid[i];
	for(int y = 0; y < h; ++y) for(int x = 0; x < w; ++x) {
		hor[x+1][y+1] = hor[x][y+1] + hor[x+1][y] - hor[x][y];
		ver[x+1][y+1] = ver[x][y+1] + ver[x+1][y] - ver[x][y];
		if(grid[y][x] != '.') continue;
		if(x != w - 1 && grid[y][x+1] == '.') ++hor[x+1][y+1];
		if(y != h - 1 && grid[y+1][x] == '.') ++ver[x+1][y+1];
	}
	int q;
	cin >> q;
	while(q--){
		int x1,y1,x2,y2;
		cin >> y1 >> x1 >> y2 >> x2;
		--x1,--y1;
		int ans = 0;
		ans += hor[x2-1][y2] - hor[x1][y2] - hor[x2-1][y1] + hor[x1][y1];
		ans += ver[x2][y2-1] - ver[x1][y2-1] - ver[x2][y1] + ver[x1][y1];
		cout << ans << "\n";
	}
	cerr << "Time : " << (double) clock() / (double) CLOCKS_PER_SEC << "s\n";
}