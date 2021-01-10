#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e3+5, MOD = 1e9+7;
int dp[N][N];

signed main(){
	fastio
	int n,h;
	cin >> n >> h;
	int arr[n];
	for(auto &x : arr) cin >> x;
	dp[0][0] = (arr[0]==h||arr[0]+1==h), dp[0][1] = (arr[0]+1==h);
	for(int i = 1;i < n;i++){
		for(int j = 0;j <= h;j++){
			if(j+arr[i]==h){
				if(j!=0) dp[i][j] = (dp[i][j] + dp[i-1][j-1])%MOD; //start a segment
				dp[i][j] = (dp[i][j]+dp[i-1][j])%MOD; //Just continue 
			}else if(j+arr[i]==h-1){
				dp[i][j] = (dp[i][j] + dp[i-1][j+1] * (j+1))%MOD; //close a segment
				dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD; //Start and end at itself
				dp[i][j] = (dp[i][j] + dp[i-1][j]*j)%MOD; //close and start another
			}
		}
	}
	cout << dp[n-1][0] << "\n";
}