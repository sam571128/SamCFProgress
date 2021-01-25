#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int grid[n][n];
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			char c;
			cin >> c;
			grid[i][j] = c-'0';
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			char c;
			cin >> c;
			if(c=='1') grid[i][j] ^=1;
		}
	}
	for(int i = 0;i < n;i++){
		if(grid[0][i]==1){
			for(int j = 0;j < n;j++) grid[j][i]^=1;
		}
	}
	for(int i = 0;i < n;i++){
		if(grid[i][0]==1){
			for(int j = 0;j < n;j++) grid[i][j]^=1;
		}
	}
	bool ok = true;
	for(int i = 0;i < n;i++){
		int sum = 0;
		for(int j = 0;j < n;j++){
			sum += grid[i][j];
		}
		if(sum!=0) ok = false;
	}
	cout << (ok ? "YES\n" : "NO\n");
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}