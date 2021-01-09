#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int w,l;
	cin >> w >> l;
	int arr[w+1];
	arr[0] = arr[w] = 1e18;
	for(int i = 1;i < w;i++){
		cin >> arr[i];
	}
	int ans = 1e18, sum = 0;
	for(int i = 0;i < l;i++){
		sum += arr[i];
	}
	ans = min(sum,ans);
	for(int i = l;i < w; i++){
		sum += arr[i] - arr[i-l];
		ans = min(ans,sum);
	}
	cout << ans << "\n";
}