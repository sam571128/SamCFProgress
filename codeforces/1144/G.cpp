#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int INF = 1e18;

void solve(){
	int n;
	cin >> n;
	vector<int> inc, dec;
	int arr[n];
	vector<int> ans(n,0);
	for(auto &x : arr) cin >> x;
	int a = -INF, b = INF;
	for(int i = 0;i < n;i++){
		if(a < arr[i]&&b > arr[i]){
			if(i==n-1 || arr[i] < arr[i+1]) a = arr[i];
			else b = arr[i], ans[i] = 1;
		}else if(a < arr[i]){
			a = arr[i];
		}else if(b > arr[i]){
			b = arr[i];
			ans[i] = 1;
		}else{
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
	for(auto x : ans) cout << x << " ";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}