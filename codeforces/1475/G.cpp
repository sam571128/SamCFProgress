#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
vector<int> fac[N];
int dp[N];

void init(){
	for(int i = 1;i < N;i++){
		for(int j = i;j < N;j += i) fac[j].push_back(i);
	}
}

void solve(){
	memset(dp,0,sizeof dp);
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	sort(arr,arr+n);
	for(auto x : arr){
		int tmp = 0;

		for(auto y : fac[x]) tmp = max(tmp,dp[y] + 1);
		dp[x] = max(dp[x],tmp);
	}
	cout << n-*max_element(dp,dp+N) << "\n";
}

signed main(){
	fastio
	init();
	int t = 1;
	cin >> t;
	while(t--) solve();
}