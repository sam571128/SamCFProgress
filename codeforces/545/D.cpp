#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	sort(arr,arr+n);
	vector<int> ans, tmp;
	int sum = 0;
	for(auto x : arr){
		if(x >= sum) ans.push_back(x),sum+=x;
	}
	cout << ans.size() << "\n";
}