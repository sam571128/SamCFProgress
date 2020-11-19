#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	char c = '\0';
	int cnt = 0;
	string s;
	cin >> s;
	string ans = "";
	for(auto ch : s){
		if(ch!=c){
			if(cnt&&cnt%2) ans += c;
			c = ch;
			cnt = 1;
		}else cnt++;
	}
	if(cnt%2) ans += c;
	sort(ans.begin(),ans.end());
	ans.resize(unique(ans.begin(),ans.end())-ans.begin());
	cout << ans << "\n";
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--)
		solve();
}