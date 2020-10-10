#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	char grid[n][m];
	int ans = 0;
	for(int i = 0;i < n;i++) cin >> grid[i];
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(grid[i][j]=='#') continue;
			ans += (i!=n-1&&grid[i+1][j]=='.') + (j!=m-1&&grid[i][j+1]=='.');
		}
	}
	cout << ans << "\n";
}