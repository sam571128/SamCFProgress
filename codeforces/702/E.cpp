#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5, M = 36; //log2(1e10) = 33.~
int dp[N][M], sum[N][M], mi[N][M];
//binary lifting
signed main(){
	fastio
	int n,k;
	cin >> n >> k;
	memset(mi,0x3f3f3f,sizeof mi);
	for(int i = 1;i <= n;i++){
		cin >> dp[i][0];
		dp[i][0]++;
	}
	for(int i = 1;i <= n;i++){
		cin >> sum[i][0];
		mi[i][0] = sum[i][0];
	}
	for(int i = 1;i < M;i++){
		for(int j = 1;j <= n;j++){
			dp[j][i] = dp[dp[j][i-1]][i-1];
			sum[j][i] = sum[j][i-1]+sum[dp[j][i-1]][i-1];
			mi[j][i] = min(mi[j][i-1],mi[dp[j][i-1]][i-1]);
		}
	}
	for(int i = 1;i <= n;i++){
		int v = k, now = i, ans1 = 0, ans2 = 1e18;
		for(int j = M-1;~j;j--){
			if(v&(1LL<<j)){
				ans1 += sum[now][j];
				ans2 = min(ans2,mi[now][j]);
				now = dp[now][j];
			}
		}
		cout << ans1 << " " << ans2 << "\n";
	}
}