#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	string s;
	cin >> s;
	int ans = 0;
	int cnt1 = 0, cnt2 = 0;
	for(auto c : s){
		if(c=='(') cnt1++;
		if(c=='[') cnt2++;
		if(c==')'&&cnt1) cnt1--,ans++;
		if(c==']'&&cnt2) cnt2--,ans++;
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}