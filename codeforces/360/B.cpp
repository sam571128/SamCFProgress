#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e3+5;
int arr[N];
int n,k;

bool check(int x){
	int dp[n] = {};
	for(int i = 1;i < n;i++){
		dp[i] = i;
		for(int j = 0; j < i;j++){
			if((abs(arr[i]-arr[j]) <= x*(i-j))) dp[i] = min(dp[i],dp[j]+i-j-1);
		}
		if(dp[i]+n-i-1<=k) return true;
	}
	return false;
}

signed main(){
	fastio
	cin >> n >> k;
	if(n==1){
		cout << 0 << "\n";
		return 0;
	}
	for(int i = 0;i < n;i++) cin >> arr[i];
	int l = 0, r = 2e9+5;
	while(l < r){
		int mid = l+r>>1;
		if(check(mid)) r = mid;
		else l = mid+1;
	}
	cout << l << "\n";
}