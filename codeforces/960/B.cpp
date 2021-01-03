#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n, a, b;
	cin >> n >> a >> b;
	a += b;
	priority_queue<int> pq;
	int arr1[n], arr2[n];
	for(auto &x : arr1) cin >> x;
	for(auto &x : arr2) cin >> x;
	for(int i = 0;i < n;i++) pq.push(abs(arr1[i]-arr2[i]));
	while(a--){
		int num = pq.top(); pq.pop();
		pq.push(abs(num-1));
	}
	int ans = 0;
	while(!pq.empty()){
		ans += pq.top()*pq.top(); pq.pop();
	}
	cout << ans << "\n";
}