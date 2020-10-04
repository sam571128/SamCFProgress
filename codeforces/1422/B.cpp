#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	int grid[n][m];
	int visited[n][m] = {};
	for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) cin >> grid[i][j];
	int ans = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(visited[i][j]) continue;
			visited[i][j] = 1;
			visited[i][m-j-1] = 1;
			visited[n-i-1][j] = 1;
			visited[n-i-1][m-j-1] = 1;
			if(i==n-i-1&&j==m-j-1) continue;
			vector<int> v;
			v.push_back(grid[i][j]);
			if(j!=m-j-1) v.push_back(grid[i][m-j-1]);
			if(i!=n-i-1) v.push_back(grid[n-i-1][j]);
			if(j!=m-j-1&&i!=n-i-1) v.push_back(grid[n-i-1][m-j-1]);
			sort(v.begin(),v.end());
			if(v.size()==4) ans += v[2]+v[3]-v[0]-v[1];
			else ans += v[1]-v[0];
		}
	}
	cout << ans << "\n";
	
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}