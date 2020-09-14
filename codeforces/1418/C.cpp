#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	int ans = arr[0];
	int cnt = 0, lst = -1;
	for(int i = 1;i < n;i++){
		if(arr[i]==1){
			cnt++;
		}else{
			ans += cnt/3;
			cnt = 0;
		}
	}
	ans += cnt/3;
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}