#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int x, y;
	cin >> x >> y;
	int cnt[4] = {};
	string s;
	cin >> s;
	for(auto c : s){
		if(c=='R') cnt[0]++;
		else if(c=='L') cnt[1]++;
		else if(c=='U') cnt[2]++;
		else if(c=='D') cnt[3]++;
	}
	if(x < 0) swap(cnt[0],cnt[1]);
	if(y < 0) swap(cnt[2],cnt[3]);
	if(cnt[0] >= abs(x) && cnt[2] >= abs(y)) cout << "YES\n";
	else cout << "NO\n"; 
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}