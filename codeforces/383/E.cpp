#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int maxn = (1<<24)-1;
int dp[(1<<24)+5];

signed main(){
	fastio
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		int tmp = 0;
		string s;
		cin >> s;
		for(int j = 0;j < 3;j++) tmp |= (1<<(s[j]-'a'));
		dp[tmp]++;
	}
	for(int i = 0;i <= 23;i++){
		for(int mask = 0; mask <= maxn; mask++){
			if(mask&(1<<i))
				dp[mask] += dp[mask^(1<<i)];
		}
	}
	int ans = 0;
	for(int i = 0;i < maxn;i++){
		ans ^= (n-dp[i]) * (n-dp[i]);
	}
	cout << ans << "\n";
}