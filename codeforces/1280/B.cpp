#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	int grid[n][m];
	bool check1 = 0, check2 = 0;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++){
			char tmp;
			cin >> tmp;
			if(tmp=='A') grid[i][j] = 1, check1 = 1;
			else grid[i][j] = 0, check2 = 1;
		}
	if(!check1){
		cout << "MORTAL\n";
		return;
	}
	if(!check2){
		cout << 0 << "\n";
		return;
	}
	bool hasborder = 0;
	int ans = 4;
	for(int i = 0;i < n;i++){
		bool check = 1;
		for(int j = 0;j < m;j++){
			if((i==0||i==n-1)&&grid[i][j]) hasborder = true;
			if(!grid[i][j]) check = false;
		}
		if(check){
			if(i==0||i==n-1){
				cout << 1 << "\n";
				return;
			}else{
				ans = min(ans,2);
			}
		}
	}
	for(int j = 0;j < m;j++){
		bool check = 1;
		for(int i = 0;i < n;i++){
			if((j==0||j==m-1)&&grid[i][j]) {
				hasborder = true;
			}	
			if(!grid[i][j]) check = false;
		}
		if(check){
			if(j==0||j==m-1){
				cout << 1 << "\n";
				return;
			}else{
				ans = min(ans,2);
			}

		}
	}
	if(ans!=4){ cout << ans << "\n"; return;}
	if(!hasborder){
		cout << 4 << "\n";
		return;
	}
	if(grid[0][0]||grid[0][m-1]||grid[n-1][0]||grid[n-1][m-1]){
		cout << 2 << "\n";
		return;
	}
	else cout << 3 << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}