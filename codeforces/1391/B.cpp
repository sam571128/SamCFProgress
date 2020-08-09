#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m, ans = 0;
	cin >> n >> m;
	char grid[n][m];
	for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) cin >> grid[i][j];
	for(int i = 0;i < n;i++) for(int j = 0;j < m;j++){
		if(i==n-1&&j==m-1) break;
		if(i==n-1){
			if(grid[i][j]!='R') ans++;
		}else if(j==m-1){
			if(grid[i][j]!='D') ans++;
		}else{
			if(grid[i][j]=='U'||grid[i][j]=='L') ans++;
		}
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}