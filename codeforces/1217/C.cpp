#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	string s;
	cin >> s;
	int ans = 0, n = s.size();
	int nxt[n] = {};
	for(int i = 0;i < n;i++){
		nxt[i] = (s[i]=='1' ? i : (i ? nxt[i-1] : -1));
	}
	for(int j = 0;j < n;j++){
		int sum = 0;
		for(int i = j;~i and j-i <= 20;i--){
			if(s[i]=='0') continue;
			sum += 1 << (j-i);	
			if(sum <= j-(i==0 ? -1 : nxt[i-1])){
				ans++;
			}
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