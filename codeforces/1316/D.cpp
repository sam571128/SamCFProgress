#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e3+5;
struct Node{
	int x,y;
} a[N][N];
int n;
char grid[N][N];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; //U,D,L,R
char p1[4] = {'U','D','L','R'};
char p2[4] = {'D','U','R','L'};

void dfs(int x, int y, int fx , int fy){
 	for(int i = 0;i < 4;i++){
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if(nx < 1 || nx > n || ny < 1 || ny > n || grid[nx][ny] != '0') continue;
		if(a[nx][ny].x == fx && a[nx][ny].y == fy){
			grid[nx][ny] = p2[i];
			dfs(nx,ny,fx,fy);
		}
	}
}

int main(){
	fastio
	cin >> n;
	memset(grid,'0',sizeof grid);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cin >> a[i][j].x >> a[i][j].y;
		}
	}
	//cout << "ok" << "\n";
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(a[i][j].x == i && a[i][j].y == j){
				grid[i][j] = 'X';
				dfs(i,j,i,j);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(a[i][j].x == -1 && a[i][j].y == -1 && grid[i][j] == '0'){
				//cout << i << " " << j << "\n";
				bool ok = false;
				for(int k = 0;k < 4;k++){
					int nx = i + dir[k][0];
					int ny = j + dir[k][1];
					if(nx < 1 || nx > n || ny < 1 || ny > n || grid[i][j] != '0') continue;
					if(a[nx][ny].x == -1&& a[nx][ny].y == -1){
						grid[i][j] = p1[k];
						ok = true;
						break;
					}
				}
				if(ok){
					dfs(i,j,-1,-1);
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(grid[i][j] == '0'){
				cout << "INVALID\n";
				return 0;
			}
		}
	}
	cout << "VALID\n";
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cout << grid[i][j];
		}
		cout << '\n';
	}
} 	