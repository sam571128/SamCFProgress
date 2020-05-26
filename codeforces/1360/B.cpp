#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n];
		for(int i = 0;i < n;i++) cin >> arr[i];
		sort(arr,arr+n);
		if(n==1){
			cout << arr[0] << "\n";
			continue;
		}
		int ans = INT_MAX;
		for(int i = 1;i < n;i++){
			ans = min(ans,arr[i]-arr[i-1]);
		}
		cout << ans << "\n";
	}
}