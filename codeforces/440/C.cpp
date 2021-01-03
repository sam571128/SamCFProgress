#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> arr;

int dfs(int n, int i){
	int num = n/arr[i];
	n %= arr[i];
	if(n==0) return num*i;
	else return num*i+min(i+dfs(arr[i]-n,i-1),dfs(n,i-1));
}

signed main(){
	fastio
	int cnt = 18, now = 1;
	arr.push_back(0);
	while(cnt--){
		arr.push_back(now);
		now = now*10+1;
	}
	int n;
	cin >> n;
	cout << dfs(n,17) << "\n";
}
