#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int MOD = 998244353, N = 1e4+5;
int dp[N][N]; //dp[i][j] => the ways we divide j into i numbers

signed main(){
	fastio
	int n,k;
	cin >> n >> k;
	dp[1][1] = 1; //the number to divide 1 into one number is one
	for(int i = 1;i <= n;i++){
		for(int j = n;~j;j--){
			//dp[i-1][j-1] => we place 1 one into multiset
			//dp[i][2*j] => the number of j dividing into i numbers not using one
			//				is the same as dividing 2j into i numbers
			dp[i][j] = (dp[i][j] + dp[i-1][j-1] + dp[i][2*j])%MOD;
		}
	}
	cout << dp[n][k] << "\n";
}