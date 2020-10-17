#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;


void solve(){
	int n;
	string s;
	cin >> n >> s;
	int vis[n] = {};
	int added[n] = {};
	int ans = 0;
	for(int i = 0;i < 2*n;i++){
		if(vis[i%n]&&!added[i%n]) ans++, added[i%n] = 1;
		vis[i%n] = 1;
		if(s[i%n]=='>'||s[i%n]=='-') continue;
		else break;
	}
	memset(vis,0,sizeof vis);
	for(int i = 2*n;~i;i--){
		if(vis[i%n]&&!added[i%n]) ans++, added[i%n] = 1;
		vis[i%n] = 1;
		if(s[(i-1+n)%n]=='<'||s[(i-1+n)%n]=='-') continue;
		else break;
	}
	for(int i = 0;i < n;i++) if(!added[i]){
		if(s[i]=='-'||s[(i-1+n)%n]=='-') ans++;
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}