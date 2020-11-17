#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	char grid[n][m];
	for(int i = 0;i < n;i++) cin >> grid[i];
	vector<array<int,6>> v;
	v.reserve(3*n*m+5);
	for(int i = 0;i < n-1;i++){
		for(int j = 0;j < m-1;j++){
			while(grid[i][j]!='0'||grid[i+1][j]!='0'||grid[i][j+1]!='0'||grid[i+1][j+1]!='0'){
				//cout << i << " " << j << "\n";
				//for(int a = 0;a < n;a++){for(int b = 0;b < m;b++) cout << grid[a][b] << ""; cout << "\n";}
				if(grid[i][j]=='1'&&grid[i+1][j]=='0'&&grid[i][j+1]=='0'&&grid[i+1][j+1]=='0'){
					v.push_back({i+1,j+1,i+1,j+2,i+2,j+1});
					grid[i][j] = '0', grid[i+1][j] = '1', grid[i][j+1] = '1';
				}
				if(grid[i][j]=='0'&&grid[i+1][j]=='1'&&grid[i][j+1]=='0'&&grid[i+1][j+1]=='0'){
					v.push_back({i+1,j+1,i+2,j+1,i+2,j+2});
					grid[i][j] = '1', grid[i+1][j] = '0', grid[i+1][j+1] = '1';
				}
				if(grid[i][j]=='0'&&grid[i+1][j]=='0'&&grid[i][j+1]=='1'&&grid[i+1][j+1]=='0'){
					v.push_back({i+1,j+1,i+1,j+2,i+2,j+2});
					grid[i][j] = '1', grid[i][j+1] = '0', grid[i+1][j+1] = '1';
				}
				if(grid[i][j]=='0'&&grid[i+1][j]=='0'&&grid[i][j+1]=='0'&&grid[i+1][j+1]=='1'){
					v.push_back({i+1,j+2,i+2,j+1,i+2,j+2});
					grid[i][j+1] = '1', grid[i+1][j] = '1', grid[i+1][j+1] = '0';
				}
				if(grid[i][j]=='1'&&grid[i+1][j]=='1'&&grid[i][j+1]=='0'&&grid[i+1][j+1]=='0'){
					v.push_back({i+1,j+1,i+1,j+2,i+2,j+2});
					grid[i][j] = '0', grid[i][j+1] = '1', grid[i+1][j+1] = '1';
				}
				if(grid[i][j]=='1'&&grid[i+1][j]=='0'&&grid[i][j+1]=='1'&&grid[i+1][j+1]=='0'){
					v.push_back({i+1,j+1,i+2,j+1,i+2,j+2});
					grid[i][j] = '0', grid[i+1][j] = '1', grid[i+1][j+1] = '1';
				}
				if(grid[i][j]=='1'&&grid[i+1][j]=='0'&&grid[i][j+1]=='0'&&grid[i+1][j+1]=='1'){
					v.push_back({i+1,j+1,i+2,j+1,i+1,j+2});
					grid[i][j] = '0', grid[i+1][j] = '1', grid[i][j+1] = '1';
				}
				if(grid[i][j]=='0'&&grid[i+1][j]=='1'&&grid[i][j+1]=='1'&&grid[i+1][j+1]=='0'){
					v.push_back({i+1,j+1,i+2,j+1,i+2,j+2});
					grid[i][j] = '1', grid[i+1][j] = '0', grid[i+1][j+1] = '1';
				}
				if(grid[i][j]=='0'&&grid[i+1][j]=='1'&&grid[i][j+1]=='0'&&grid[i+1][j+1]=='1'){
					v.push_back({i+1,j+1,i+1,j+2,i+2,j+2});
					grid[i][j] = '1', grid[i][j+1] = '1', grid[i+1][j+1] = '0';
				}
				else if(grid[i][j]=='0'&&grid[i+1][j]=='0'&&grid[i][j+1]=='1'&&grid[i+1][j+1]=='1'){
					v.push_back({i+1,j+1,i+1,j+2,i+2,j+1});
					grid[i][j] = '1', grid[i][j+1] = '0', grid[i+1][j] = '1';
				}
				if(grid[i][j]=='1'&&grid[i+1][j]=='1'&&grid[i][j+1]=='1'&&grid[i+1][j+1]=='0'){
					v.push_back({i+1,j+1,i+2,j+1,i+1,j+2});
					grid[i][j] = '0', grid[i][j+1] = '0', grid[i+1][j] = '0';
				}
				if(grid[i][j]=='1'&&grid[i+1][j]=='1'&&grid[i][j+1]=='0'&&grid[i+1][j+1]=='1'){
					v.push_back({i+1,j+1,i+2,j+1,i+2,j+2});
					grid[i][j] = '0', grid[i+1][j] = '0', grid[i+1][j+1] = '0';
				}
				if(grid[i][j]=='1'&&grid[i+1][j]=='0'&&grid[i][j+1]=='1'&&grid[i+1][j+1]=='1'){
					v.push_back({i+1,j+1,i+1,j+2,i+2,j+2});
					grid[i][j] = '0', grid[i][j+1] = '0', grid[i+1][j+1] = '0';
				}
				if(grid[i][j]=='0'&&grid[i+1][j]=='1'&&grid[i][j+1]=='1'&&grid[i+1][j+1]=='1'){
					v.push_back({i+2,j+1,i+1,j+2,i+2,j+2});
					grid[i+1][j] = '0', grid[i][j+1] = '0', grid[i+1][j+1] = '0';
				}
				if(grid[i][j]=='1'&&grid[i+1][j]=='1'&&grid[i][j+1]=='1'&&grid[i+1][j+1]=='1'){
					v.push_back({i+2,j+1,i+1,j+2,i+2,j+2});
					grid[i+1][j] = '0', grid[i][j+1] = '0', grid[i+1][j+1] = '0';
				}
				//for(auto x : v.back()) cout << x << " ";
				//cout << "\n";
			}

			//cout << i << " " << j << "\n";
			//cout << (grid[i][j]!='0'||grid[i+1][j]!='0'||grid[i][j+1]!='0'||grid[i+1][j+1]!='0') << "\n";
		}
	}
	cout << v.size() << "\n";
	for(auto x : v){
		for(auto y : x) cout << y << " ";
		cout << "\n";
	}
}

signed main(){
	//fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}	 