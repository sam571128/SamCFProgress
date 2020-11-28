#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	//DP first time for minimum houses
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	sort(arr,arr+n);
	int ans1 = 1, lst = arr[0];
	for(int i = 1;i < n;i++){
		if(arr[i] > lst+2){
			ans1++;
			lst = arr[i];
		}
	}
	map<int,int> m;
	int ans2 = 0;
	for(int i = 0;i < n;i++){
		if(!m[arr[i]-1]){
			ans2++;
			m[arr[i]-1]++;
		}else if(!m[arr[i]]){
			ans2++;
			m[arr[i]]++;
		}else if(!m[arr[i]+1]){
			ans2++;
			m[arr[i]+1]++;
		}
	}
	cout << ans1 << " " << ans2 << "\n";
}