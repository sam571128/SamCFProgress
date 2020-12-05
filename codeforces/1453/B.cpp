#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int idx = -1, ma = 0;
	int arr[n];
	for(auto &x : arr) cin >> x;
	if(n==2){
		cout << 0 << "\n";
		return;
	}
	int ans = 0;
	for(int i = 0;i < n;i++){
		int val = abs((i==0 ? 0 : abs(arr[i]-arr[i-1]))+(i==n-1 ? 0 : abs(arr[i]-arr[i+1]))-(i==0||i==n-1 ? 0 : abs(arr[i-1]-arr[i+1])));
		if(val > ma){
			idx = i;
			ma = val;
		}
	}
	for(int i = 1;i < n;i++){
		ans += abs(arr[i]-arr[i-1]);
	}
	if(~idx){
		ans -= (idx==0 ? 0 : abs(arr[idx]-arr[idx-1]))+(idx==n-1 ? 0 : abs(arr[idx]-arr[idx+1]));
		ans += (idx==0||idx==n-1 ? 0 : abs(arr[idx-1]-arr[idx+1]));
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}