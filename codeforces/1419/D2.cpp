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
	int ans[n];
	for(int i = 0;i < n;i++){
		if(i&1){
			ans[i] = arr[i/2];
		}else{
			ans[i] = arr[i/2+n/2];
		}
	}
	int tmp = 0;
	for(int i = 0;i < n;i++){
		if(i-1>=0&&i+1<n&&ans[i]<ans[i+1]&&ans[i]<ans[i-1]) tmp++;
	}
	cout << tmp << "\n";
	for(auto &x : ans) cout << x << " ";
}