#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	if(n==1){
		cout << arr[0] << "\n";
		return 0;
	}
	int ans = 0;
	bool allpos = 1, allneg = 1, haszero = 0;
	for(auto x : arr){
		if(x >= 0) allneg = 0, ans += x;
		else if(x <= 0) allpos = 0, ans += -x;
		if(x==0) haszero = 1;
	}
	if(haszero){
		cout << ans << "\n";
		return 0;
	}
	if(allneg){
		sort(arr,arr+n,greater<int>());
		cout << ans+2*arr[0] << "\n";
	}else if(allpos){
		sort(arr,arr+n);
		cout << ans-2*arr[0] << "\n";
	}else{
		cout << ans << "\n";
	}
}