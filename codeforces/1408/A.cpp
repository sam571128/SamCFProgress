#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[3][n];
	for(int i = 0;i < 3;i++) for(int j = 0;j < n;j++) cin >> arr[i][j];
	int ans[n];
	for(int i = 0;i < n;i++){
		for(int j = 0;j < 3;j++){
			if(i==0){
				ans[i] = arr[j][i];
				break;
			}
			if(i!=n-1&&arr[j][i]!=ans[i-1]){
				ans[i] = arr[j][i];
				break;
			}
			if(i==n-1&&arr[j][i]!=ans[0]&&arr[j][i]!=ans[i-1]){ 	
				//cout << arr[j][i] << " " << ans[0] << "\n";
				ans[i] = arr[j][i];
				break;
			}
		}
	}
	for(auto x : ans) cout << x << ' ';
	cout << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}