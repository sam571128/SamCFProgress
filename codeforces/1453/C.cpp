#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
int l[10], r[10], u[10], d[10];

void solve(){
	int n;
	cin >> n;	
	int grid[n][n];
	for(int i = 0;i < 10;i++){
		r[i] = d[i] = 0;
		l[i] = u[i] = n-1;
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			char tmp;
			cin >> tmp;
			grid[i][j] = (tmp-'0');
			l[grid[i][j]] = min(j,l[grid[i][j]]);
			r[grid[i][j]] = max(j,r[grid[i][j]]);
			u[grid[i][j]] = min(i,u[grid[i][j]]);
			d[grid[i][j]] = max(i,d[grid[i][j]]);
		}
	}
	for(int a = 0; a <= 9; a++){
		int ans = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(grid[i][j]==a){
					ans = max(ans,max(i,n-i-1)*max(j-l[a],r[a]-j));
					ans = max(ans,max(j,n-j-1)*max(i-u[a],d[a]-i));
				}
			}
		}
		cout << ans << " ";
	}
	cout << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}