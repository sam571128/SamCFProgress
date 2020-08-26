#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n;
const int MOD = 1e9+7;

struct mat{
	vector<vector<int>> t;
	mat(){
		t.resize(n, vector<int>(n));
	}
	mat operator* (const mat& b) const{
		mat c = mat(); 
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				for(int k = 0;k < n;k++){
					c.t[i][k] = (c.t[i][k] + t[i][j]*b.t[j][k]%MOD)%MOD;
				}
			}
		}
		return c;
	}
};

void solve(){
	cin >> n;
	int k;
	cin >> k;
	//int grid[n][n];
	vector<vector<int>> grid(n,vector<int>(n));
	for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) cin >> grid[i][j];
	mat ans = mat();
	for(int i = 0;i < n;i++) ans.t[i][i] = 1;
	mat m = mat();
	m.t = grid;
	while(k){
		if(k&1) ans = ans * m;
		m = m*m;
		k>>=1;
	}
	int ans2 = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			ans2 = (ans2 + ans.t[i][j])%MOD;
		}
	}
	cout << ans2 << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}