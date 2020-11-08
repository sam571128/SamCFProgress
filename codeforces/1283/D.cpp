#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

map<int,bool> h;

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	int arr[n];
	for(auto &x : arr) cin >> x;
	queue<pair<int,int>> q;
	vector<int> ans;
	ll ans2 = 0;
	for(auto x : arr) h[x] = 1, q.push({x+1,1}), q.push({x-1,1});
	while(!q.empty()){
		int x = q.front().first; int dis = q.front().second; q.pop();
		if(h[x]) continue;
		ans.push_back(x), h[x]=1, ans2 += dis;
		if(ans.size()==m) break;
		if(!h[x+1]) q.push({x+1,dis+1});
		if(!h[x-1]) q.push({x-1,dis+1});
	}
	cout << ans2 << "\n";
	for(auto x : ans) cout << x << " ";
}