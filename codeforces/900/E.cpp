#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5;
int dp[2][N] , cnt[N], arr[N], ans[N];
//0 => a, 1 => b

void solve(){
	int n, t;
	string s;
	cin >> n >> s >> t;
	s = 'X' + s;
	for(int i = 1;i <= n;i++){
		cnt[i] = (s[i]=='?');
		cnt[i] += cnt[i-1];
	}
	for(int i = 1;i <= n;i++){
		if(s[i]!='a') //s[i] = b or ?
			dp[1][i] = dp[0][i-1] + 1;
		if(s[i]!='b') //s[i] = a or ?
			dp[0][i] = dp[1][i-1] + 1;
		if(dp[t&1^1][i] < t){
			arr[i] = arr[i-1], ans[i] = ans[i-1];
		}else{
			arr[i] = arr[i-t] + 1;
			ans[i] = ans[i-t] + cnt[i] - cnt[i-t];
		}
		if(arr[i]==arr[i-1]) ans[i] = min(ans[i],ans[i-1]);
		else if(arr[i] < arr[i-1]) ans[i] = ans[i-1];
	}
	cout << ans[n] << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}