#include <bits/stdc++.h>

//#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> arr;
int solve(int l, int r){
	if(l > r) return 0;
	int tmp = max(arr[l-1],arr[r+1]);
	int mind = int(min_element(arr.begin()+l,arr.begin()+r+1) - arr.begin());
	return min(r-l+1,solve(l,mind-1)+solve(mind+1,r)+arr[mind]-tmp);
}

void solve(){
	int n;
	cin >> n;
	arr.assign(n+2,0);
	for(int i = 1;i <= n;i++){
		cin >> arr[i];
	}
	cout << solve(1,n) << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}