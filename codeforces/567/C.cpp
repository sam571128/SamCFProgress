#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

map<int,int> m;
map<int,int> dp;
signed main(){ 
	fastio
	int n,k;
	cin >> n >> k;
	int ans = 0;
	if(k==1){
		for(int i = 0, tmp;i < n;i++){
			cin >> tmp;
			ans += m[tmp]*(m[tmp]-1)/2;
			m[tmp]++;
		}
	}else{
		for(int i = 0, tmp;i < n;i++){
			cin >> tmp;
			if(tmp==0){
				ans += m[tmp]*(m[tmp]-1)/2;
				m[tmp]++;
				continue;
			}
			if(tmp%k==0) dp[tmp] += m[tmp/k], ans += dp[tmp/k];
			m[tmp]++;
		}
	}
	cout << ans << "\n";
}