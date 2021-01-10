#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,k,m;
	cin >> n >> k >> m;
	int arr[k];
	for(auto &x : arr) cin >> x;
	int sum = accumulate(arr,arr+k,0);
	int ans = 0;
	for(int i = 0;i <= n;i++){
		if(sum*i > m) break;
		int tmp = (k+1)*i;
		vector<int> v;
		for(int j = 0;j < n-i;j++){
			for(int l = 0;l < k;l++){
				v.push_back(arr[l]);
			}
		}
		sort(v.begin(),v.end(),greater<int>());
		int tm = m-sum*i;
		while(tm > 0){
			if(v.empty()||tm < v.back()) break;
			else tm -= v.back(), tmp++, v.pop_back();
		}
		ans = max(tmp,ans);
	}
	cout << ans << "\n";
}