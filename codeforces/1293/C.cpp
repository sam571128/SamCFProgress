#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

bool grid[2][(int)1e5+5];
signed main(){
	fastio
	int n,q;
	cin >> n >> q;
	int tmp = 0;
	for(int i = 0;i < q;i++){
		int r,c;
		cin >> r >> c;
		r--,c--;
		grid[r][c] ^= 1;
		if(grid[r][c]){
			if(c!=0&&grid[r^1][c-1]) tmp++;
			if(grid[r^1][c]) tmp++;
			if(c!=n-1&&grid[r^1][c+1]) tmp++;
		}
		else{
			if(c!=0&&grid[r^1][c-1]) tmp--;
			if(grid[r^1][c]) tmp--;
			if(c!=n-1&&grid[r^1][c+1]) tmp--;	
		}
		cout << (tmp ? "NO\n" : "YES\n");
	} 
}