#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n = 4, m ,k;
	cin >> m >> k;
	cout << "YES\n";
	int grid[n][m] = {};
	for(int i = 1;i < m/2;i++){
		if(k>=2){
			k-=2;
			grid[1][i] = grid[1][m-1-i] = 1;
		}
		if(k>=2){
			k-=2;
			grid[2][i] = grid[2][m-1-i] = 1;
		}
	}
	if(k) k--,grid[1][m/2] = 1;
	if(k) grid[2][m/2] = 1; 
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cout << (grid[i][j] ? '#' : '.');
		}
		cout << "\n";
	}
}