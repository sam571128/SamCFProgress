//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> arr;
int dfs(vector<int> &ar, int dep){
	if(dep < 0) return 0;
	vector<int> a, b;
	for(int i = 0;i < ar.size();i++){
		if((ar[i]>>dep)&1) a.push_back(ar[i]);
		else b.push_back(ar[i]);
	}
	if(a.size()==0) return dfs(b,dep-1);
	if(b.size()==0) return dfs(a,dep-1);
	return min(dfs(a,dep-1),dfs(b,dep-1)) + (1<<dep);
}

signed main(){
	fastio
	int n;
	cin >> n;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		arr.push_back(tmp);
	}
	cout << dfs(arr,30) << "\n";
}