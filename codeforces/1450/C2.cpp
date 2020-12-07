#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	char grid[n][n];
	int cnt = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cin >> grid[i][j];
			if(grid[i][j]!='.') cnt++;
		}
	}
	cnt/=3;
	for(int x = 0;x < 3;x++){
		int tmp = 0;
		char grid2[n][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				grid2[i][j] = grid[i][j];
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(((i+j-n)%3+3)%3==x&&grid2[i][j]=='O') grid2[i][j]='X', tmp++;
				if(((i+j-n)%3+3)%3==(x+1)%3&&grid2[i][j]=='X') grid2[i][j]='O', tmp++;
			}
		}
		if(tmp <= cnt){
			for(int i = 0;i < n;i++){
				for(int j = 0;j < n;j++){
					cout << grid2[i][j];
				}
				cout << "\n";
			}
			return;
		}
	}	
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
} 