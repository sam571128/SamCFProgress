#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 3005;
int dp[N][N];

signed main(){
	fastio
	int n;
	cin >> n;
	int a[n];
	for(auto &x : a) cin >> x;
	for(int i = n-1;i >= 0;i--){
		for(int j = i;j < n;j++){
			if(i==j) dp[i][j] = a[i];
			else dp[i][j] = max(a[i]-dp[i+1][j], a[j]-dp[i][j-1]);
		}
	}
	cout << dp[0][n-1] << "\n";
}