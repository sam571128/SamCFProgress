//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	char grid[n][m];
	for(auto &a : grid) for(auto &b : a) cin >> b;
	bool hasP = false, hasA = false;
	for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) if(grid[i][j]=='P') hasP = true; else hasA = true;
	if(!hasP) { cout << 0 << "\n"; return;} if(!hasA) { cout << "MORTAL" << "\n"; return;}
	bool corner = false;
	int a1[2] = {0,n-1}, a2[2] = {0,m-1};
	for(int i : a1) for(int j : a2) if(grid[i][j]=='A') corner = true;
	bool row[n], col[m];
	memset(row,true,sizeof row);
	memset(col,true,sizeof col);
	for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) if(grid[i][j]!='A') row[i] = false, col[j] = false;
	bool border = false;
	for(int i : a1) for(int j = 0;j < m;j++) if(grid[i][j] == 'A') border = true;
	for(int j : a2) for(int i = 0;i < n;i++) if(grid[i][j] == 'A') border = true;
	if(row[0]||row[n-1]){
		cout << 1 << "\n";
		return;
	}
	if(col[0]||col[m-1]){
		cout << 1 << "\n";
		return;
	}
	for(int i = 0;i < max(m,n);i++){
		//cout << i << " " << (i >= n ? -1 : row[i]) << (1>=m ? -1 : col[i]) << "\n"; 
		if(corner){
			cout << 2 << "\n";
			return;
		}
		if(i<n&&row[i]){
			cout << 2 << "\n";
			return;
		}
		if(i<m&&col[i]){
			cout << 2 << "\n";
			return;
		}
	}
	if(border){
		cout << 3 << "\n";
	}else{
		cout << 4 << "\n";
	}

}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}