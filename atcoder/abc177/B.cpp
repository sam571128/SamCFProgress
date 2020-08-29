#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	string s,t;
	cin >> s >> t;
	int ans = INT_MAX;
	int n = s.size(), m = t.size();
	for(int i = 0;i <= n-m;i++){
		int cnt = 0;
		for(int j = 0;j < m;j++){
			if(s[i+j]!=t[j])
				cnt++;
		}
		//cout << i << " " << ans << "\n";
		ans = min(cnt,ans);
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}