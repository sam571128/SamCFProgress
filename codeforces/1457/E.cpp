#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,k;
	cin >> n >> k;
	int arr[n];
	for(auto &x : arr) cin >> x;
	priority_queue<int> pq;
	sort(arr,arr+n,greater<int>());
	for(int i = 0;i <= k;i++) pq.push(0);
	
	int ans = 0;
	for(auto x : arr){
		int val = pq.top(); pq.pop();
		ans += val;
		pq.push(x+val);
	}
	
	cout << ans << "\n";
}