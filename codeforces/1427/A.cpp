#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[n], sum = 0, pos = 0, neg = 0;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		sum += arr[i];
		if(arr[i] > 0) pos += arr[i];
		else neg += -arr[i];
	}
	if(sum==0){
		cout << "NO\n";
	}else{
		cout << "YES\n";
		if(pos > neg) sort(arr,arr+n,greater<int>());
		else sort(arr,arr+n);
		for(auto x : arr) cout << x << " ";
		cout << "\n";
	}
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}