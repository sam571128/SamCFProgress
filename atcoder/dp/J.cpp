//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 305;
double dp[N][N][N];

signed main(){
	fastio
	int n;
	cin >> n;
	int a[3];
	memset(a,0,sizeof a);
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		a[tmp-1]++;
	}

	double p = 1.0/n;
	for(int k = 0;k <= n;k++){
		for(int j = 0;j <= n;j++){
			for(int i = 0;i <= n;i++){
				int z = n-i-j-k;
				if(z < 0) break;
				if(z==n) continue;
				double x = 1-z*p;
				if(i) dp[i][j][k] += dp[i-1][j][k]*i*p;
				if(j) dp[i][j][k] += dp[i+1][j-1][k]*j*p;
				if(k) dp[i][j][k] += dp[i][j+1][k-1]*k*p;
				dp[i][j][k] += 1;
				dp[i][j][k] /= x;
			}
		}
	}
	cout << fixed << setprecision(10) <<  dp[a[0]][a[1]][a[2]] << "\n";
}