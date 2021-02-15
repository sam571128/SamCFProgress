#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int grid[n][n];
	if(n%2==0){
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				if(j-i==n/2) grid[i][j] = 0;
				else if(j-i < n/2) grid[i][j] = 1;
				else grid[i][j] = -1;
			}
		}
	}else{
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				if(j-i <= n/2) grid[i][j] = 1;
				else grid[i][j] = -1;
			}
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = i+1;j < n;j++){
			cout << grid[i][j] << " ";
		}
	}
	cout << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}