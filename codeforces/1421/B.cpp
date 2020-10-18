#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int grid[n][n] = {};
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++){
			char tmp;
			cin >> tmp;
			if(isdigit(tmp)) grid[i][j] = tmp - '0';			
		} 
	for(int i = 0;i <= 1;i++){
		for(int j = 0;j <= 1;j++){
			if(i==j) continue;
			int cnt = 0;
			cnt += (grid[1][0]!=i), cnt += (grid[0][1]!=i);
			cnt += (grid[n-1][n-2]!=j), cnt += (grid[n-2][n-1]!=j);
			if(cnt <= 2){
				cout << cnt << "\n";
				if(grid[1][0]!=i) cout << "2 1\n";
				if(grid[0][1]!=i) cout << "1 2\n";
				if(grid[n-1][n-2]!=j) cout << n << " " << n-1 << "\n";
				if(grid[n-2][n-1]!=j) cout << n-1 << " " << n << "\n";
				return;
			}
		}
	}
	cout << 0 << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}