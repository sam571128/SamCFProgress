#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	string s;
	cin >> s;
	int n = s.size();
	s = "$" + s;
	int now = 0;
	int idx[3], dp[n+1];
	idx[0] = dp[0] = 0, idx[1] = idx[2] = -1;
	for(int i = 1;i <= n;i++){
		now = (now + s[i]-'0')%3;
		dp[i] = dp[i-1];
		if(idx[now]!=-1) dp[i] = max(dp[i],dp[idx[now]] + 1);
		idx[now] = i;
	}
	cout << "\n";
	cout << dp[n] << "\n";
}