#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int N = 2e5+5;

int dp[N];
signed main(){
	fastio
	int n,k;
	cin >> n >> k;
	
	int a[n];
	for(auto &x : a) cin >> x;
	for(int i = 0; i <= k;i++){
		for(auto x : a){
			if(i >= x) dp[i] |= !(dp[i-x]);
		}
	}
	cout << (dp[k] ? "First" : "Second") << "\n";
}
