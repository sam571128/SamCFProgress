#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

/* O(n*k)
	void solve(){
	int n,k,l;
	cin >> n >> k >> l;
	int arr[n+1];
	for(int i = 1;i <= n;i++){
		char tmp;
		cin >> tmp;
		arr[i] = (islower(tmp)>0);
	}
	int dp[n+1][k+1] = {}, ans = INT_MAX;
	for(int i = 1;i <= n;i++){
		dp[i][0] = dp[i-1][0] + arr[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= k;j++){
			dp[i][j] = min(dp[i][j-1],dp[i-1][j]+arr[i]);
			if(i-l>=0) dp[i][j] = min(dp[i][j],dp[i-l][j-1]);
		}
	}
	ans = min(ans,dp[n][k]);
	for(int i = 1;i <= n;i++) arr[i]^=1;
	for(int i = 1;i <= n;i++){
		dp[i][0] = dp[i-1][0] + arr[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= k;j++){
			dp[i][j] = min(dp[i][j-1],dp[i-1][j]+arr[i]);
			if(i-l>=0) dp[i][j] = min(dp[i][j],dp[i-l][j-1]);
		}
	}
	ans = min(ans,dp[n][k]);
	cout << ans << "\n";
}*/

const int N = 1e6+5, INF = 1e18;
int arr[N];
pair<int,int> dp[N];
int n,k,l;

int update(int val){
	for(int i = 1;i <= n;i++) dp[i] = {INF,INF};
	dp[0] = {0,0};
	for(int i = 1;i <= n;i++){
		dp[i] = min(dp[i],{dp[i-1].first+arr[i],dp[i-1].second});
		if(i-l>=0) dp[i] = min(dp[i],{dp[i-l].first+val,dp[i-l].second+1});
	}
	return dp[n].second;
}

int solve(){
	int l = 0, r = n, mid;
	while(l < r){
		mid = l+r>>1;
		if(update(mid)<=k) r = mid;
		else l = mid+1;
	}
	update(l);
	return dp[n].first - l * k;
}

signed main(){
	fastio
	cin >> n >> k >> l;
	for(int i = 1;i <= n;i++){
		char tmp;
		cin >> tmp;
		arr[i] = (tmp==tolower(tmp));
	}
	int ans = INT_MAX;
	ans = min(ans,solve());
	for(int i = 1;i <= n;i++) arr[i] ^= 1;
	ans = min(ans,solve());
	update(0);
	if(dp[n].second <= k) ans = 0;
	cout << ans << "\n";
}