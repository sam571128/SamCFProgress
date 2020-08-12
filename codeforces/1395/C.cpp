//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 205;
int dp[N][1024];
int a[N], b[N];

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= m;i++) cin >> b[i];
	dp[0][0] = 1;
	for(int i = 1;i <= n;i++){
		for(int k = 0;k < 1024;k++){
			if(!dp[i-1][k]) continue;
			for(int j = 1;j <= m;j++){
				dp[i][k|(a[i]&b[j])] = 1;
			}
		}
	}
	for(int i = 0;i < 1024;i++){
		if(dp[n][i]){
			cout << i << "\n";
			return 0;
		}
	}
}