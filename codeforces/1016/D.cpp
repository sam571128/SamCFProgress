#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	int a[n], b[m];
	int xor1 = 0, xor2 = 0;
	for(auto &x : a) cin >> x;
	for(auto &x : b) cin >> x;
	for(auto x : a) xor1 ^= x;
	for(auto x : b) xor2 ^= x;
	if(xor1!=xor2){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	int grid[n][m] = {};
	grid[0][0] = a[0]^b[0]^xor2;
	for(int i = 1;i < m;i++){
		grid[0][i] = b[i];
	}
	for(int i = 1;i < n;i++){
		grid[i][0] = a[i];
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
}