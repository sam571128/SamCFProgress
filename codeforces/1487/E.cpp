#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	//fastio
	int num[4];
	for(int i = 0;i < 4;i++){
		cin >> num[i];
	}
	vector<vector<int>> arr;
	arr.resize(4);
	for(int i = 0;i < 4;i++){
		arr[i].resize(num[i]);
		for(auto &x : arr[i]) cin >> x;
	}
	vector<vector<vector<int>>> adj(4);
	for(int i = 1;i <= 3;i++){
		adj[i].resize(num[i]+1);
		int tmp;
		cin >> tmp;
		for(int j = 0;j < tmp;j++){
			int u,v;
			cin >> u >> v;
			u--,v--;
			adj[i][v].push_back(u);
		}
	}
	for(int i = 1;i <= 3;i++){
		multiset<int> ms;
		ms.insert(1e18);
		for(int j = 0;j < num[i-1];j++){
			ms.insert(arr[i-1][j]);
		}
		//cout << *ms.begin() << "\n";
		for(int j = 0;j < num[i];j++){
			for(auto v : adj[i][j])
				ms.erase(ms.find(arr[i-1][v]));
			arr[i][j] += *ms.begin();
			for(auto v : adj[i][j])
				ms.insert(arr[i-1][v]);
		}
	}

	int ans = *min_element(arr[3].begin(),arr[3].end());
	cout << (ans>=1e18 ? -1 : ans) << "\n";
}