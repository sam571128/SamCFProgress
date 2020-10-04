#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int ans = INT_MAX;
	for(int i = 0;i <= sqrt(1e9);i++){
		int tmp = (n-1)/(i+1);
		ans = min(ans,tmp+i); 
	}	
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}