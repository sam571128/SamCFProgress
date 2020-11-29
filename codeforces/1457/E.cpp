#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,k;
	cin >> n >> k;
	int arr[n];
	priority_queue<int> s;
	for(auto &x : arr) cin >> x;
	sort(arr,arr+n,greater<int>());
	for(int i = 0;i <= k;i++){
		s.push(0);
	}
	int ans = 0;
	for(auto x : arr){
		int val = s.top(); s.pop();
		ans += val;
		s.push(val+x);
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}