#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	queue<int> q;
	q.push(0);
	int arr[n];
	for(auto &x : arr) cin >> x;
	int ans = 0;
	for(int i = 1;i < n;i++){
		if(arr[i] < arr[i-1])
			q.pop();
		q.push(q.front()+1), ans = max(q.front()+1,ans);
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}