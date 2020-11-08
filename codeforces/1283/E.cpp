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
	int mi = 1, lst = arr[0];
	for(int i = 0;i < n;i++){
		if(arr[i] > lst+2){
			mi++;
			lst = arr[i];
		}
	}
	map<int,bool> m;
	int ans[n+1] = {};
	for(int i = 0;i < n;i++){
		ans[i+1] = ans[i];
		if(!m[arr[i]-1]){
			ans[i+1] = ans[i]+1;
			m[arr[i]-1] = 1;
		}else if(!m[arr[i]]){
			ans[i+1] = ans[i]+1;
			m[arr[i]] = 1;
		}else if(!m[arr[i]+1]){
			ans[i+1] = ans[i]+1;
			m[arr[i]+1] = 1;
		}
	}
	cout << mi << " " << ans[n] << "\n";
}