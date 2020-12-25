#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int MOD = 998244353;

signed main(){
	fastio
	int n,k;
	cin >> n >> k;

	k %= MOD;
	int ans[n+1];
	for(int i = 1;i <= n;i++) cin >> ans[i];
	
	//dp[i][j] => How many posibilities that after cyclic
	//When we get to the the elements before index i would give a j points
	//dp[i][j] =  dp[i-1][j-1]		 (When ans[i+1]==(The element we choose) && ans[i]!=(The element we choose), there is only one of those)
	//         +  dp[i-1][j]*(k-2)   (When ans[i+1]!=(The element we choose) && ans[i]!=(The element we choose), there are k-2 of those)
	//         +  dp[i-1][j+1]       (When ans[i]==(The element we choose), but ans[i+1]!=(The element we choose), there is only one of those)
	//What about base case??
	//dp[0][0] = 1
	//It is also possible to have dp[0][-1...-n] so we need to increase the index for dp
	int dp[n+1][n*2+2] = {};
	auto getIDX = [&](int x){
		return x + n+1;
	};
	dp[0][getIDX(0)] = 1; //When we choose 0 elements, the only contribution is one
	for(int i = 1;i <= n;i++){
		for(int j = 1; j <= 2*n+1;j++){
			if(ans[i]==ans[i%n+1]) dp[i][j] = dp[i-1][j]*k%MOD;
			else dp[i][j] = (dp[i-1][j-1]%MOD + dp[i-1][j]*(k-2)%MOD + dp[i-1][j+1]%MOD)%MOD; 
		}
	}
	int sum = 0;
	for(int i = 1;i <= n;i++){
		sum = (sum + dp[n][getIDX(i)]%MOD)%MOD;
	}
	cout << sum << "\n";
	
}