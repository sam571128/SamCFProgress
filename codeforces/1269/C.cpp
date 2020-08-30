#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,k;
	cin >> n >> k;
	string s, ans;
	cin >> s;
	for(int i = 0;i < n;i++){
		if(i < k) ans += s[i];
		else ans += ans[i-k];
	}
	if(ans >= s){
		cout << n << "\n" << ans << "\n";
	}else{
		for(int i = k-1;~i;i--){
			if(ans[i]!='9'){
				ans[i]++;
				for(int j = i + 1;j < k;j++) ans[j] = '0';
				break;
			}
		}
		cout << n << "\n";
		for(int i = 0;i < n;i++){
			if(i>=k) ans[i] = ans[i-k];
			cout << ans[i];
		}
	}
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}