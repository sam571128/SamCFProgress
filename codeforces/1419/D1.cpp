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
	sort(arr,arr+n);
	cout << n/2+(n%2 ? 0 : -1) << "\n";
	int ans[n];
	for(int i = 0;i < n;i++){
		if(i&1){
			ans[i] = arr[i/2];
		}else{
			ans[i] = arr[i/2+n/2];
		}
	}
	for(auto &x : ans) cout << x << " ";
}