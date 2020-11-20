#pragma GCC optimize ("O3", "unroll-loops")
#pragma GCC target ("avx2")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <bits/extc++.h>
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using namespace __gnu_pbds;

unsigned hash_f(unsigned x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}
struct chash {
    int operator()(int x) const { return hash_f(x); }
};

const int N = 2e5+5;
gp_hash_table<int,pair<int,int>,chash> tmp; 

signed main(){
	fastio
	int n;
	cin >> n;
	int arr[n+1] = {};
	for(int i = 1;i <= n;i++) cin >> arr[i];
	pair<int,int> dp[n+1];
	pair<int,int> mx = {};
	int idx = 0;
	for(int i = 1;i <= n;i++){
		dp[i] = tmp[arr[i]-1];
		dp[i].first++;
		if(dp[i] > mx) mx = max(dp[i],mx), idx = i;
		tmp[arr[i]] = max(make_pair(dp[i].first,i),tmp[arr[i]]);
	}
	cout << mx.first << "\n";
	vector<int> ans;
	ans.reserve(N);
	while(idx!=0){
		ans.push_back(idx);
		idx = mx.second;
		mx = dp[idx];
	}
	while(!ans.empty()){
		cout << ans.back() << " ";
		ans.pop_back();
	}
}
