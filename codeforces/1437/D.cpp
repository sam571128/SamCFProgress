#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int tmp1 = 0, tmp2 = 0, ans = 0;
	int arr[n];
	for(auto &x : arr) cin >> x;
	for(int i = 1;i < n;i++){
		if(i==1||arr[i] < arr[i-1]){
			if(tmp1) tmp1--,tmp2++;
			else{
				tmp1 = tmp2, tmp2 = 0, ans++;
			}
		}else{
			tmp2++;
		}
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}