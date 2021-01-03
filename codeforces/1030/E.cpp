#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int arr[n+1] = {};
	for(int i = 1;i <= n;i++) cin >> arr[i];
	for(int i = 1;i <= n;i++) arr[i] = __builtin_popcountll(arr[i]);
	int dp[n+1][2] = {}; //dp[i][j] means how many sums are even or odd before index i
	for(int i = 2; i <= n; ++i){
        if(arr[i]%2==1){
            dp[i][0] = dp[i-1][1] + (arr[i-1]%2==1);
            dp[i][1] = dp[i-1][0] + (arr[i-1]%2==0);
        }else{
            dp[i][0] = dp[i-1][0] + (arr[i-1]%2==0);
            dp[i][1] = dp[i-1][1] + (arr[i-1]%2==1);
        }
    }

	int ans = 0;
	for(int i = 2;i <= n;i++){
		int ma = 0, remove = 0, sum = 0;
		for(int j = i;j >= max((int)1,i-200);j--){
			sum += arr[j];
			ma = max(arr[j],ma);
			if(i==j) continue;
			if((sum&1^1)&&2*ma > sum) remove++;
		}
		ans += (dp[i][0]-remove);
	}
	cout << ans << "\n";
}