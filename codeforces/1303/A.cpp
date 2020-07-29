#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	string s;
	cin >> s;
	int status = -1;
	int n = s.size();
	int cnt = 0, ans = 0;
	for(int i = 0;i < n;i++){
		if(~status^1&&s[i]=='1') status = 1;
		if(~status&&status){
			if(s[i]=='0') cnt++;
			else ans+=cnt, cnt=0;
		}
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}