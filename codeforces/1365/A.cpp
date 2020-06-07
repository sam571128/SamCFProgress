#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int grid[55][55];
int n,m;
bool check(int r, int c){
	for(int i = 0; i < n;i++)
		if(grid[i][c]==1) return false;
	for(int i = 0; i < m;i++)
		if(grid[r][i]==1) return false;
	return true;
}

void solve(){
	cin >> n >> m;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			cin >> grid[i][j];
	bool status = true;
	for(int i = 0; i < n;i++){
		for(int j = 0;j < m;j++){
			if(grid[i][j]!=1&&check(i,j)){
				status = !status;
				grid[i][j] = 1;
			}
		}
	}
	cout << (status?"Vivek":"Ashish") << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}