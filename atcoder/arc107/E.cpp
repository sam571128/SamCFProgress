#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 5e5+5, M = 4;
int grid1[M][N], grid2[N][M];

int mex(int a, int b){
	if(a > 0 && b > 0) return 0;
	else if(a+b==1) return 2;
	else return 1;
}

int ans[3];

signed main(){
	fastio
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> grid1[0][i];
		ans[grid1[0][i]]++;
		if(i < M) grid2[0][i] = grid1[0][i]; 
	}
	for(int i = 1;i < n;i++){
		cin >> grid2[i][0];
		ans[grid2[i][0]]++;
		if(i < M) grid1[i][0] = grid2[i][0];
	}
	for(int i = 1;i < min(M,n);i++){
		for(int j = 1;j < n;j++){
			grid1[i][j] = mex(grid1[i-1][j],grid1[i][j-1]);
			ans[grid1[i][j]]++;
		}
	}
	for(int i = 1;i < n;i++){
		for(int j = 1;j < min(M,n);j++){
			grid2[i][j] = mex(grid2[i-1][j],grid2[i][j-1]);
			if(i >= M) ans[grid2[i][j]]++;
		}
	}
	for(int i = M-1;i < n;i++){
		ans[grid1[M-1][i]] += n-i-1;
	}
	for(int i = M;i < n;i++){
		ans[grid2[i][M-1]] += n-i-1;
	}
	cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
}