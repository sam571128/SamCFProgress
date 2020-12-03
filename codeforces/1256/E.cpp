#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	//fastio
	int n;
	cin >> n;
	vector<pair<int,int>> v(n);
	for(int i = 0;i < n;i++){
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.begin(),v.end());
	pair<int,int> dp[n+1];
	for(int i = 0;i <= n;i++){
		dp[i] = {1e18,-1};
	}
	dp[0] = {0,0};
	for(int i = 0;i < n;i++){
		for(int j = 2;j < 5;j++){
			if(i+j >= n) break;
			if(dp[i+j+1].first > dp[i].first + v[i+j].first - v[i].first){
				dp[i+j+1] = {dp[i].first + v[i+j].first - v[i].first, i};
			}
		}
	}
	int ans = 0, arr[n] = {};
	int idx = n;
	while(idx){
		for(int i = idx-1;i >= dp[idx].second;i--)
			arr[v[i].second] = ans+1;
		ans++;
		idx = dp[idx].second;
	}
	cout << dp[n].first << " " << ans << "\n";
	for(auto x : arr) cout << x << " ";
}