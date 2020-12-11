#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	int isSpruce[n][m][2] = {};
	int cnt = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			char c;
			cin >> c;
			if(c=='*') isSpruce[i][j][0] = 1, cnt++;
		}
	}
	for(int t = 1;t <= 500;t++){
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(!isSpruce[i][j][(t+1)%2]) continue;
				if(i-1<0||j-1<0||j+1>=m) isSpruce[i][j][t%2] = 0;
				else{
					if(isSpruce[i-1][j][(t+1)%2]&&isSpruce[i][j-1][(t+1)%2]&&isSpruce[i][j+1][(t+1)%2]){
						isSpruce[i][j][t%2] = 1, cnt++;
					}else{
						isSpruce[i][j][t%2] = 0;
					}
				}
			}
		}
	}
	cout << cnt << '\n';
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}