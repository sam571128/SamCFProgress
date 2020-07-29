#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5;
vector<int> e[N];


signed main(){
	fastio
	int n;
	cin >> n;	
	vector<int> ans(n-1,-1);
	for(int i = 0;i < n-1;i++){
		int u,v;
		cin >> u >> v;
		e[u].push_back(i);
		e[v].push_back(i);
	}
	int ma = 0, ind = -1;
	for(int i = 1;i <= n;i++){
		if(e[i].size()>ma) ind = i, ma = e[i].size();
	}
	int tmp = 0;
	for(auto x : e[ind]) ans[x] = tmp++;
	for(auto &x : ans){
		if(!~x) x = tmp++;
		cout << x << "\n";
	}

}