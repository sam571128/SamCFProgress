#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	map<int,int> cnt, idx;
	int n;
	cin >> n;
	int arr[n];
	for(int i = 1;i <= n;i++){
		cin >> arr[i-1];
		if(i-idx[arr[i-1]]>1) cnt[arr[i-1]]++;
		idx[arr[i-1]] = i;
	}
	int ans = INT_MAX;
	for(int i = 0;i < n;i++){
		ans = min(ans,cnt[arr[i]]+(arr[n-1]!=arr[i]));
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}