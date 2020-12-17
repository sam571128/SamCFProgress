#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int sum[2] = {};
	int arr[n];
	for(int i = 0, tmp; i < n;i++){
		cin >> tmp;
		arr[i] = tmp;
		sum[i%2] += tmp; 
	}
	if(sum[0] < sum[1]){
		for(int i = 0;i < n;i++){
			if(i%2==0) cout << 1 << " ";
			else cout << arr[i]<< " ";
		}
	}else{
		for(int i = 0;i < n;i++){
			if(i%2) cout << 1 << " ";
			else cout << arr[i]<< " ";
		}
	}
	cout << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}