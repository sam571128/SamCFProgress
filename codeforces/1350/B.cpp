#include <bits/stdc++.h>

#define long long ll
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n+1] = {0};
		for(int i = 1;i <= n;i++){
			cin >> arr[i];	
		}
		int dp[n+1] = {};
		for(int i = 0;i <= n;i++) dp[i] = 1;
		for(int i = 1;i <= n;i++){
			for(int j = 2*i;j <= n;j += i){
				if(arr[j]>arr[i]) dp[j] = max(dp[j],dp[i] + 1); 
			}
		}
		cout << *max_element(dp,dp+n+1) << "\n";
	}
}