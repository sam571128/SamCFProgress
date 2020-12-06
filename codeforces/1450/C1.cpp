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
			if(grid[i][j]=='X') cnt++;
		}
	}
	cnt/=3;
	int cnt1 = 0, mi = INT_MAX, tmp;
	for(int x = 0;x < n;x++){
		cnt1 = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if((i+j+x-n)%3==0&&grid[i][j]=='X') cnt1++;
			}
		}
		if(cnt1 < mi) mi = cnt1, tmp = x;
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if((i+j+tmp-n)%3==0&&grid[i][j]=='X'&&cnt) grid[i][j]='O',cnt--;
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cout << grid[i][j];
		}
		cout << "\n";
	}
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
} 