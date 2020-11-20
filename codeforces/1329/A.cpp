#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	int arr[m], suff[m+1] = {};
	for(auto &x : arr) cin >> x;
	for(int i = m-1;~i;i--){
		suff[i] = suff[i+1] + arr[i];
	}
	if(suff[0] < n){
		cout << -1 << "\n";
		return 0;
	}
	int ans[m];
	for(int i = 0;i < m;i++){
		if(arr[i]+i > n){
			cout << -1 << "\n";
			return 0;
		}
		ans[i] =  max(i+1,n-suff[i]+1);
	}
	for(auto x : ans) cout << x << " ";
}
