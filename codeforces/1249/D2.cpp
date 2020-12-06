#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
signed main(){
	fastio
	int n,k;
	cin >> n >> k;
	int arr[N] = {};
	vector<pair<int,int>> v[N];
	for(int i = 0;i < n;i++){
		int l,r;
		cin >> l >> r;
		arr[l]++, arr[r+1]--;
		v[l].push_back({r+1,i});
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> pq;
	vector<int> ans;
	int now = 0;
	for(int i = 0;i < N;i++){
		now += arr[i];
		for(auto x : v[i]) pq.push(x);
		while(now > k){
			auto x = pq.top(); pq.pop();
			arr[x.first]++;
			ans.push_back(x.second+1);
			now--;
		}
	}
	cout << ans.size() << "\n";
	for(auto x : ans) cout << x << " ";
}