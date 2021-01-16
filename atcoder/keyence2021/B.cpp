#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,k;
	cin >> n >> k;
	int arr[n], cnt[n+2] = {};
	for(auto &x : arr) cin >> x;
	cnt[0] += k;
	sort(arr,arr+n);
	for(auto x : arr){
		if(cnt[x]) cnt[x]--, cnt[x+1]++;
	}
	int ans = 0;
	for(int i = 0;i <= n+1;i++){
		ans += cnt[i]*i;
	}
	cout << ans << "\n";
}