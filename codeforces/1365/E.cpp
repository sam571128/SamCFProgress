#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	ll int n;
	cin >> n;
	ll int arr[n];
	for(int i = 0;i < n;i++) cin >> arr[i];
	if(n<=3){
		ll int ans = 0;
		for(int i = 0;i < n;i++) ans |= arr[i];
		cout << ans;
		return 0;
	}
	ll int ans = 0;
	for(int i = 0;i < n;i++)
		for(int j = i+1;j < n;j++)
			for(int k = j+1;k < n;k++)
				ans = max(ans,arr[i]|arr[j]|arr[k]);
	cout << ans << "\n";
}